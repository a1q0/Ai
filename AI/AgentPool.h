#pragma once

#include "Agent.h"

class AgentPool {
public:
	Agent* agents;
	int agents_len;
	
	AgentPool();
	~AgentPool();


	void run();

	void setSources(Source* sources);

	void setOutputs(Source* outputs);

	void setInputs(Source* inputs);

	void setSources(Source& source);

	void setOutputs(Source& output);

	void setInputs(Source& input);

	Source* getSources();

	Source* getOutputs();

	Source* getInputs();
};

