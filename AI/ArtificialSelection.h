#pragma once

#include "Source.h"
#include "AgentPool.h"

class ArtificialSelection {
public:
	Source* target;
	Source* source;

	AgentPool agentPool;

	ArtificialSelection();
	~ArtificialSelection();

	void setTarget(Source& target);

	void train();

};

