#include "pch.h"

#include "Agent.h"
#include "Source.h"
#include "ArtificialSelection.h"
#include "Subleq.h"


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
	
	ArtificialSelection* as = new ArtificialSelection();

	Source* target = new Source(new int[2]{ 1, 2 }, 2);
	
	// Agent used as template for all others agents
	Agent* targetAgent = new Agent();

	targetAgent->setInput(new Source(0));
	targetAgent->setCode((new Source(256))->zero());
	targetAgent->setOutput(target);
	targetAgent->setEmulator(new Subleq());

	AgentPool* ap = new AgentPool(targetAgent, 1);
	as->setAgentPool(ap);
	as->setTarget(targetAgent->output);
	
	as->run();

	delete as;
	delete targetAgent;

	return 0;
}