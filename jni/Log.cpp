#include "Log.hpp"
#include <stdarg.h>
#include <android/log.h>

void Log::info(const char* sMessage ...)
{
	va_list args;
	va_start(args, sMessage);

	__android_log_vprint(ANDROID_LOG_INFO, "NATIVE_ACTIVITY", sMessage, args);
	__android_log_print(ANDROID_LOG_INFO, "NATIVE_ACTIVITY", "\n");

	va_end(args);
}

void Log::warning(const char* sMessage ...)
{
	va_list args;
	va_start(args, sMessage);

	__android_log_vprint(ANDROID_LOG_WARN, "NATIVE_ACTIVITY", sMessage, args);
	__android_log_print(ANDROID_LOG_WARN, "NATIVE_ACTIVITY", "\n");

	va_end(args);
}

void Log::error(const char* sMessage ...)
{
	va_list args;
	va_start(args, sMessage);

	__android_log_vprint(ANDROID_LOG_ERROR, "NATIVE_ACTIVITY", sMessage, args);
	__android_log_print(ANDROID_LOG_ERROR, "NATIVE_ACTIVITY", "\n");

	va_end(args);
}

void Log::debug(const char* sMessage ...)
{
	va_list args;
	va_start(args, sMessage);

	__android_log_vprint(ANDROID_LOG_DEBUG, "NATIVE_ACTIVITY", sMessage, args);
	__android_log_print(ANDROID_LOG_DEBUG, "NATIVE_ACTIVITY", "\n");

	va_end(args);
}

