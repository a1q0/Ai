#include "pch.h"
#include <iostream>
#include <thread>

#include "Agent.h"
#include "Source.h"
#include "Logger.h"

Agent::Agent(Source* source, Source* input, Source* output, Emulator* emulator) {
	this->source = source;
	this->input = input;
	this->output = output;
	this->emulator = emulator;
}

Agent::~Agent() {
	delete source;
	delete input;
	delete output;
	delete emulator;
}

void Agent::start() {
	int length = input->length + source->length + output->length;
	int* memory = new int[length];

	memcpy(&memory[0], input->data, input->length);
	memcpy(&memory[input->length], source->data, source->length);
	memcpy(&memory[input->length+source->length], output->data, output->length);

	emulator->run(memory, length);

	memcpy(output->data, &memory[input->length + source->length], output->length);

	delete[length] memory;
}

std::thread Agent::run() {
	return std::thread(&Agent::start, this);
}

float Agent::fitness(Source &target) {
	float fitness = 0;

	if (target.length != output->length) {
		Logger::error("Agent.cpp -> fitness()", " Target length != Output length");
		exit(-1);
	}

	for (int i = 0; i < output->length; i++)
		fitness += target.data[i] == output->data[i] / output->length;
	
	return fitness;
}
