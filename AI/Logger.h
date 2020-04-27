#pragma once
#include <string>

class Logger {
public:
	static bool enable_info;
	static bool enable_debug;
	static bool enable_warning;
	static bool enable_error;
	std::string name = "";
	
	Logger();
	~Logger();

	void info(std::string message);
	void debug(std::string message);
	void warning(std::string message);
	void error(std::string message);
};

bool Logger::enable_info = true;
bool Logger::enable_debug = true;
bool Logger::enable_warning = true;
bool Logger::enable_error = true;

