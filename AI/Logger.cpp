#include "pch.h"
#include "Logger.h"
#include <iostream>

void Logger::info(std::string name, std::string message) {
	if (!enable_info)
		return;
	if (name != "")
		std::cout << "[" << name << "] ";
	std::cout << message << std::endl;
}

void Logger::debug(std::string name, std::string message) {
	if (!enable_debug)
		return;
	std::cout << "[Debug]";
	if (name != "")
		std::cout << "[" << name << "] ";
	std::cout << message << std::endl;

}

void Logger::warning(std::string name, std::string message) {
	if (!enable_warning)
		return;
	std::cout << "[Warning]";
	if (name != "")
		std::cout << "[" << name << "] ";
	std::cout << message << std::endl;

}

void Logger::error(std::string name, std::string message) {
	if (!enable_error)
		return;
	std::cout << "[Error]";
	if (name != "")
		std::cout << "[" << name << "] ";
	std::cout << message << std::endl;
}
