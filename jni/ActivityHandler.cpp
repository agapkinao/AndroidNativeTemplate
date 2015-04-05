#include "ActivityHandler.hpp"
#include "Log.hpp"
#include <unistd.h>

ActivityHandler::ActivityHandler()
{
	Log::info("Creating ActivityHandler");
}

ActivityHandler::~ActivityHandler()
{
	Log::info("Destructing ActivityHandler");
}

int ActivityHandler::onActivate()
{
	Log::info("onActivate()");

	return STATUS_OK;
}

void ActivityHandler::onDeactivate()
{
	Log::info("onDeactivate()");
}

int ActivityHandler::onStep()
{
	Log::info("onStep() : Starting:");

	usleep(300000);

	Log::info("onStep() : Done:");

	return STATUS_OK;
}

void ActivityHandler::onStart()
{
	Log::info("onStart()");
}

void ActivityHandler::onResume()
{
	Log::info("onResume()");
}

void ActivityHandler::onPause()
{
	Log::info("onPause()");
}

void ActivityHandler::onStop()
{
	Log::info("onStop()");
}

void ActivityHandler::onDestroy()
{
	Log::info("onDestroy()");
}

void ActivityHandler::onSaveState(void** pData, size_t pSize)
{
	Log::info("onSaveState()");
}

void ActivityHandler::onConfigurationChanged()
{
	Log::info("onConfigurationChanged()");
}

void ActivityHandler::onLowMemory()
{
	Log::info("onLowMemory()");
}

void ActivityHandler::onCreateWindow()
{
	Log::info("onCreateWindow()");
}

void ActivityHandler::onDestroyWindow()
{
	Log::info("onDestroyWindow()");
}

void ActivityHandler::onGainFocus()
{
	Log::info("onGainFocus()");
}

void ActivityHandler::onLostFocus()
{
	Log::info("onLostFocus()");
}
