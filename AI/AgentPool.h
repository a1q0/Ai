#pragma once

#include "Agent.h"

class AgentPool {
public:
	Agent* agents;
	int agents_len;

	Source* target;
	
	AgentPool(Agent agentTemplate, int agents_len);
	AgentPool(Agent* agents, int agents_len);
	AgentPool(Agent* agents, int agents_len, Source* target);
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

