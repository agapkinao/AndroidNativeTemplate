#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

#include <stddef.h>

const int STATUS_OK = 0;
const int STATUS_KO = -1;
const int STATUS_EXIT = -2;

class EventHandler
{
public:
	virtual ~EventHandler() {};

	virtual int onActivate() = 0;
	virtual void onDeactivate() = 0;
	virtual int onStep() = 0;

	virtual void onStart() {};
	virtual void onResume() {};
	virtual void onPause() {};
	virtual void onStop() {};
	virtual void onDestroy() {};

	virtual void onSaveState(void** data, size_t iSize) {};
	virtual void onConfigurationChanged() {};
	virtual void onLowMemory() {};

	virtual void onCreateWindow() {};
	virtual void onDestroyWindow() {};
	virtual void onGainFocus() {};
	virtual void onLostFocus() {};
};

#endif
