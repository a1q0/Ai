#pragma once

#include "Source.h"
#include "AgentPool.h"

class ArtificialSelection {
public:
	Source* target;
	
	AgentPool* agentPool;

	ArtificialSelection();
	ArtificialSelection(Source* target, AgentPool* agentPool);
	~ArtificialSelection();


	void run();

	void setTarget(Source* target);
	void setAgentPool(AgentPool* agentPool);

};

