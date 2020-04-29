#pragma once

#include "Agent.h"

class AgentPool {
public:
	Agent* agents;
	unsigned int agents_len;

	Source* target;
	
	AgentPool(Agent* agentTemplate, unsigned int agents_len);
	
	~AgentPool();

	AgentPool* setRandomSources();

	void run();

	bool compile();

	float getFittest(Agent& agent);
	void setTarget(Source* target);
	void setSource(Source* source);
	void setInput(Source* input);
	void setOutput(Source* output);
};

