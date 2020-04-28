#include "pch.h"
#include <iostream>
#include <thread>

#include "Agent.h"
#include "Source.h"
#include "Logger.h"

Agent::Agent() : Agent(nullptr, nullptr, nullptr, nullptr) {

}

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
	delete[] memory;
}

void Agent::start() {
	int length = input->length + source->length + output->length;
	

	memcpy(&memory[0], input->data, input->length);
	memcpy(&memory[input->length], source->data, source->length);
	memcpy(&memory[input->length+source->length], output->data, output->length);

	emulator->run(memory, length);

	memcpy(output->data, &memory[input->length + source->length], output->length);
}

void Agent::init_memory(int length) {
	if (this->memory != nullptr)
		delete[] memory;
	this->memory = new int[length];
}

void Agent::fill_memory(Source** sources, int length) {
	int pos = 0;
	for (int i = 0; i < length; i++) {
		if (sources[i]->length == 0)
			continue;
		memcpy(&memory[pos], sources[i]->data, sources[i]->length);
		pos += sources[i]->length;
	}
}

bool Agent::compile() {
	this->memory_length = this->input->length + this->source->length + this->output->length;
	Source* sources[3] = { input, source, output };
	init_memory(memory_length);
	fill_memory(sources, 3);
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
