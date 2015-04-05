#ifndef _EVENTLOOP_HPP_
#define _EVENTLOOP_HPP_

#include <android_native_app_glue.h>
#include "EventHandler.hpp"

class EventLoop
{
public:
	EventLoop(android_app* application);
	void Run(EventHandler* activityHandler);

protected:
	void Activate();
	void Deactivate();

	void HandleActivityEvent(int iCommand);

private:
	android_app* application;
	bool bEnabled;
	bool bExit;
	EventHandler* activityHandler;

	static void EventCallback(android_app* application, int iCommand);
};

#endif
