#pragma once

#include "Agent.h"

class AgentPool {
public:
	Agent* agents;
	int agents_len;
	

	AgentPool();
	AgentPool(int agents_len);
	AgentPool(Agent* agents, int agents_len);
	~AgentPool();

	void random();

	void run();

	bool compile();

	void setTarget(Source* target);
	void setSource(Source* source);
	void setInput(Source* input);
	void setOutput(Source* output);
};

