#include "pch.h"

#include <string>
#include <iostream> 
#include <sstream>   

#include "Logger.h"

namespace Logger {
	bool enable_info = true;
	bool enable_debug = true;
	bool enable_warning = true;
	bool enable_error = true;

	void info(std::string name, std::string message) {
		if (!enable_info)
			return;
		if (name != "")
			std::cout << "[" << name << "] ";
		std::cout << message << std::endl;
	}

	void debug(std::string name, std::string message) {
		if (!enable_debug)
			return;
		std::cout << "[Debug]";
		if (name != "")
			std::cout << "[" << name << "] ";
		std::cout << message << std::endl;

	}

	void warning(std::string name, std::string message) {
		if (!enable_warning)
			return;
		std::cout << "[Warning]";
		if (name != "")
			std::cout << "[" << name << "] ";
		std::cout << message << std::endl;

	}

	void error(std::string name, std::string message) {
		if (!enable_error)
			return;
		std::cout << "[Error]";
		if (name != "")
			std::cout << "-> " << name << " : ";
		std::cout << message << std::endl;
	}

	void info(std::string name, std::stringstream message) {
		if (!enable_info)
			return;
		info(name, message.str());
	}

	void debug(std::string name, std::stringstream message) {
		if (!enable_debug)
			return;
		debug(name, message.str());

	}

	void warning(std::string name, std::stringstream message) {
		if (!enable_warning)
			return;
		warning(name, message.str());
	}

	void error(std::string name, std::stringstream message) {
		if (!enable_error)
			return;
		error(name, message.str());
	}
};