#pragma once
#include <string>

class Logger {
public:
	static bool enable_info;
	static bool enable_debug;
	static bool enable_warning;
	static bool enable_error;
	
	static void info(std::string name, std::string message);
	static void debug(std::string name, std::string message);
	static void warning(std::string name, std::string message);
	static void error(std::string name, std::string message);
} Logger;

bool Logger::enable_info = true;
bool Logger::enable_debug = true;
bool Logger::enable_warning = true;
bool Logger::enable_error = true;

