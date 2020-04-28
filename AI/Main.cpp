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
	
	Source* target = new Source(1);
	target->data = new int[2] {1, 2};
	ArtificialSelection as;

	as.setTarget(target);
	
	as.setAgentPool((new AgentPool(*new Agent(), 256))->setRandomSources());

	as.run();
	

	return 0;
}