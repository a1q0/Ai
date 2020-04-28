#pragma once
#include <thread>

#include "Source.h"
#include "Emulator.h"

class Agent {
public:
	Source* code;
	Source* input;
	Source* output;

	Emulator* emulator;

	int* memory;
	int memory_length;
	bool compiled = false;

	Agent();
	Agent(Source* source, Source* input, Source* output, Emulator* emulator);

	~Agent();

	bool compile();
	std::thread run();

	float fitness(Source &target);

	Agent* setInput(Source* source);

	Agent* setCode(Source* source);

	Agent* setOutput(Source* source);

	Agent* copy();

private:
	void start();
	void init_memory(int length);

	void fill_memory(Source** sources, int length);

};