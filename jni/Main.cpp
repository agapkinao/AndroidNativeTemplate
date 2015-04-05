#include "EventLoop.hpp"
#include "ActivityHandler.hpp"

void android_main(android_app* application)
{
	EventLoop eventLoop(application);
	ActivityHandler activityHandler;

	eventLoop.Run(&activityHandler);
}
