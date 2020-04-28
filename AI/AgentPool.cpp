#include "pch.h"
#include "AgentPool.h"

AgentPool::AgentPool(int agents_len) : AgentPool(new Agent[agents_len], agents_len) {

}

AgentPool::AgentPool() : AgentPool(nullptr, 0) {
}


AgentPool::AgentPool(Agent* agents, int agents_len) {
	this->agents = agents;
	this->agents_len = agents_len;
}


AgentPool::~AgentPool() {
	for (int i = 0; i < agents_len; i++)
		agents[i].~Agent();
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

void AgentPool::setTarget(Source* target) {
	this->setTarget = target;
}

void AgentPool::setSource(Source* source) {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].source = source;
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
