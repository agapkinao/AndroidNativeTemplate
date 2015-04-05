#ifndef _LOG_HPP_
#define _LOG_HPP_

class Log
{
public:
	static void info(const char* sMessage ...);
	static void warning(const char* sMessage ...);
	static void error(const char* sMessage ...);
	static void debug(const char* sMessage ...);
};

#endif
