#include "pch.h"
#include "AgentPool.h"

#include "Logger.h"

AgentPool::AgentPool(Agent* agentTemplate, unsigned int agents_len) : target(nullptr) {
	this->agents = new Agent[agents_len];
	this->agents_len = agents_len;

	for (unsigned int i = 0; i < agents_len; i++) {
		this->agents[i] = *(agentTemplate->copy());
	}

	setTarget(agentTemplate->output);
}

AgentPool::~AgentPool() {
	for (unsigned int i = 0; i < agents_len; i++)
		agents[i].~Agent();
}

AgentPool* AgentPool::setRandomSources() {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		if (agents[i].code == nullptr)
			Logger::error("AgentPool", "nullptr");
			exit(-1);
		
		agents[i].code->random();
	}
	return this;
}

void AgentPool::run() {
	Logger::info("AgentPool", "Running Agents ...");

	for (unsigned int i = 0; i < this->agents_len; i++) {
		agents[i].run();
	}
}

bool AgentPool::compile() {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		if (agents[i].compile() == false)
			return false;
	}

	std::stringstream ss;
	ss << agents_len << " Agents compiled." << std::endl;
	Logger::info("AgentPool", ss.str());
	return true;
}

float AgentPool::getFittest(Agent& agent)
{
	return 0.0f;
}

void AgentPool::setTarget(Source* target) {
	this->target = target;

	for (unsigned int i = 0; i < agents_len; i++) {
		agents[i].setOutput((new Source(target->length))->random());
	}
}

void AgentPool::setSource(Source* source) {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		agents[i].code = source;
	}
}

void AgentPool::setInput(Source* input) {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		agents[i].input = input;
	}
}

void AgentPool::setOutput(Source* output) {
	for (unsigned int i = 0; i < this->agents_len; i++) {
		agents[i].output = output;
	}
}
