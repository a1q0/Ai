#pragma once
#include <string>

namespace Logger {
	extern bool enable_info;
	extern bool enable_debug;
	extern bool enable_warning;
	extern bool enable_error;
	
	void info(std::string name, std::string message);
	void debug(std::string name, std::string message);
	void warning(std::string name, std::string message);
	void error(std::string name, std::string message);
};