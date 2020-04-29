#include "pch.h"

#include "Agent.h"
#include "Source.h"
#include "ArtificialSelection.h"

int main(int argc, char *argv[]) {
	/**
	
	step 1
		generate source randomly 

		Agent.cpp

	step 2
		calculate fit score

		Agent.cpp
	step 3
		select best agents

		AgentGenPool
	step 4
		go to step 2 until fit score is high enough

	*/
	
	ArtificialSelection as;

	Source* target = new Source(1);
	target->data = new int[2] {1, 2};
	as.setTarget(target);
	
	// Agent used as template for all others agents
	Agent* agent = new Agent();

	agent->setInput(new Source(0));
	agent->setCode((new Source(256))->zero());
	agent->setOutput((new Source(2))->zero());

	AgentPool* ap = new AgentPool(agent, 256);

	delete ap;
	delete agent;

	//as.setAgentPool();

	//as.run();
	
	return 0;
}