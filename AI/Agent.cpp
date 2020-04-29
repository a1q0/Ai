#include "pch.h"

#include <thread>

#include "Agent.h"
#include "Source.h"
#include "Logger.h"

Agent::Agent() : memory(nullptr), memory_length(0), emulator(nullptr) {
	this->input = new Source(0);
	this->output = new Source(0);
	this->code = new Source(0);
}

Agent::Agent(Source* code, Source* input, Source* output, Emulator* emulator) : memory(nullptr), memory_length(0) {
	this->code = code;
	this->input = input;
	this->output = output;
	this->emulator = emulator;
}

Agent::~Agent() {
	delete code;
	delete input;
	delete output;
	delete emulator;
	delete[] memory;
}

void Agent::start() {
	if (compiled == false)
		Logger::error("Agent", "You must compile the agent before running it.");
		exit(-1);

	emulator->run(memory, memory_length);

	memcpy(output->data, &memory[input->length + code->length], output->length);
}

void Agent::init_memory(unsigned int length) {
	if (this->memory != nullptr)
		delete[] memory;
	this->memory = new unsigned int[length];
}

void Agent::fill_memory(Source** sources, unsigned int length) {
	int pos = 0;
	for (unsigned int i = 0; i < length; i++) {
		if (sources[i]->length == 0)
			continue;
		memcpy(&memory[pos], sources[i]->data, sources[i]->length);
		pos += sources[i]->length;
	}
}

bool Agent::compile() {
	this->memory_length = this->input->length + this->code->length + this->output->length;
	Source* sources[3] = { input, code, output };
	init_memory(memory_length);
	fill_memory(sources, 3);
	return (this->compiled = true);
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

	for (unsigned int i = 0; i < output->length; i++)
		fitness += target.data[i] == output->data[i] / output->length;
	
	return fitness;
}

Agent* Agent::setInput(Source* source) {
	if (input != nullptr)
		delete input;
	this->input = source;
	return this;
}

Agent* Agent::setCode(Source* source) {
	if (code != nullptr)
		delete code;
	this->code = source;
	return this;
}

Agent* Agent::setOutput(Source* source) {
	if (output != nullptr)
		delete output;
	this->output = source;
	return this;
}

Agent* Agent::copy() {
	Agent* agent = new Agent(code->copy(), input->copy(), output->copy(), emulator);
	agent->memory = new unsigned int[memory_length];
	agent->memory_length = this->memory_length;
	memcpy(agent->memory, this->memory, memory_length);
	agent->compiled = this->compiled;
	return agent;
}