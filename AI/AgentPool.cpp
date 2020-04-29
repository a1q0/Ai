#include "pch.h"
#include "AgentPool.h"

#include <iostream>

AgentPool::AgentPool(Agent* agentTemplate, unsigned int agents_len) : target(nullptr) {
	this->agents = new Agent[agents_len];
	this->agents_len = agents_len;

	std::cout << "agent template : " << agentTemplate->code->length << std::endl;

	for (int i = 0; i < agents_len; i++) {
		this->agents[i] = *(agentTemplate->copy());
	}
}

AgentPool::~AgentPool() {
	for (int i = 0; i < agents_len; i++)
		agents[i].~Agent();
}

AgentPool* AgentPool::setRandomSources() {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		if (agents[i].code == nullptr)
			exit(-1);
		
		agents[i].code->random();
	}
	return this;
}

void AgentPool::run() {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].run();
	}
}

bool AgentPool::compile() {
	for (int i = 0; i < this->agents_len; i++) {
		if (agents[i].compile() == false)
			return false;
	}

	return true;
}

float AgentPool::getFittest(Agent& agent)
{
	return 0.0f;
}

void AgentPool::setTarget(Source* target) {
	this->target = target;

	for (int i = 0; i < agents_len; i++) {
		agents[i].setOutput((new Source(target->length))->random());
	}
}

void AgentPool::setSource(Source* source) {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].code = source;
	}
}

void AgentPool::setInput(Source* input) {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].input = input;
	}
}

void AgentPool::setOutput(Source* output) {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].output = output;
	}
}
