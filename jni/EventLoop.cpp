#include "EventLoop.hpp"
#include "Log.hpp"

EventLoop::EventLoop(android_app* application)
	: application(application),
	  bEnabled(false),
	  bExit(false),
	  activityHandler(NULL)
{
	application->onAppCmd = EventCallback;
	application->userData = this;
}

void EventLoop::Run(EventHandler* activityHandler)
{
	app_dummy();
	this->activityHandler = activityHandler;

	Log::info("Start event loop");

	android_poll_source* source;
	int iEvents = 0;

	while(true)
	{
		while(ALooper_pollOnce(bEnabled ? 0 : -1, NULL, &iEvents, (void**)&source) >= 0)
		{
			if(source != NULL)
			{
				Log::info("Processing an event");
				source->process(application, source);
			}

			if(application->destroyRequested)
			{
				Log::info("Exiting event loop");

				return;
			}
		}

		if(bEnabled && !bExit && (activityHandler->onStep() != STATUS_OK))
		{
			bExit = true;
			ANativeActivity_finish(application->activity);
		}
	}
}

void EventLoop::Activate()
{
	if (!bEnabled && (application->window != NULL))
	{
		bExit = false;
		bEnabled = true;

		if (activityHandler->onActivate() != STATUS_OK)
		{
			bExit = true;
			Deactivate();
			ANativeActivity_finish(application->activity);
		}
	}
}

void EventLoop::Deactivate()
{
	if (bEnabled)
	{
		activityHandler->onDeactivate();
		bEnabled = false;
	}
}

void EventLoop::EventCallback(android_app* application, int iCommand)
{
	EventLoop& eventLoop = *((EventLoop*)application->userData);
	eventLoop.HandleActivityEvent(iCommand);
}

void EventLoop::HandleActivityEvent(int iCommand)
{
	switch (iCommand)
	{
		case APP_CMD_CONFIG_CHANGED:
			activityHandler->onConfigurationChanged();
			break;

		case APP_CMD_INIT_WINDOW:
			activityHandler->onCreateWindow();
			break;

		case APP_CMD_DESTROY:
			activityHandler->onDestroy();
			break;

		case APP_CMD_GAINED_FOCUS:
			Activate();
			activityHandler->onGainFocus();
			break;

		case APP_CMD_LOST_FOCUS:
			activityHandler->onLostFocus();
			Deactivate();
			break;

		case APP_CMD_LOW_MEMORY:
			activityHandler->onLowMemory();
			break;

		case APP_CMD_PAUSE:
			activityHandler->onPause();
			Deactivate();
			break;

		case APP_CMD_RESUME:
			activityHandler->onResume();
			break;

		case APP_CMD_SAVE_STATE:
			activityHandler->onSaveState(&application->savedState, application->savedStateSize);
			break;

		case APP_CMD_START:
			activityHandler->onStart();
			break;

		case APP_CMD_STOP:
			activityHandler->onStop();
			break;

		case APP_CMD_TERM_WINDOW:
			activityHandler->onDestroyWindow();
			Deactivate();
			break;

		default:
			break;
	}
}


