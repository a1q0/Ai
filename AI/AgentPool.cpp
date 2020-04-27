#include "pch.h"
#include "AgentPool.h"


AgentPool::AgentPool() {
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

void AgentPool::setSources(Source* source) {
	for (int i = 0; i < this->agents_len; i++) {
		agents[i].source = source;
	}
}
