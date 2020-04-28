#include "pch.h"
#include "AgentPool.h"

AgentPool::AgentPool(Agent agentTemplate, int agents_len) : target(nullptr) {
	this->agents = new Agent[agents_len];
	this->agents_len = agents_len;

	for (int i = 0; i < agents_len; i++) {
		this->agents[i] = *agentTemplate.copy();
	}
}

AgentPool::AgentPool(Agent* agents, int agents_len) : target(nullptr) {
	this->agents = agents;
	this->agents_len = agents_len;
}

AgentPool::AgentPool(Agent* agents, int agents_len, Source* target) {
	this->agents = agents;
	this->agents_len = agents_len;
	this->target = target;
}


AgentPool::~AgentPool() {
	for (int i = 0; i < agents_len; i++)
		agents[i].~Agent();
}

AgentPool* AgentPool::setRandomSources() {
	for (int i = 0; i < this->agents_len; i++) {
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
