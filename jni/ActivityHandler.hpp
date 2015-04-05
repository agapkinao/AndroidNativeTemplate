#ifndef _ACTIVITYHANDLER_HPP_
#define _ACTIVITYHANDLER_HPP_

#include "EventHandler.hpp"

class ActivityHandler : public EventHandler
{
public:
	ActivityHandler();
	~ActivityHandler();

protected:
	int onActivate();
	void onDeactivate();
	int onStep();

	void onStart();
	void onResume();
	void onPause();
	void onStop();
	void onDestroy();

	void onSaveState(void** pData, size_t pSize);
	void onConfigurationChanged();
	void onLowMemory();

	void onCreateWindow();
	void onDestroyWindow();
	void onGainFocus();
	void onLostFocus();
};

#endif
