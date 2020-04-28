#pragma once
#include <thread>

#include "Source.h"
#include "Emulator.h"

class Agent {
public:
	Source* source;
	Source* input;
	Source* output;

	Emulator* emulator;

	Agent();
	Agent(Source* source, Source* input, Source* output, Emulator* emulator);

	~Agent();

	bool compile();
	std::thread run();

	float fitness(Source &target);

private:
	void start();
};