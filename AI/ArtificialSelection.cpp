#include "pch.h"

#include <iostream>

#include "ArtificialSelection.h"
#include "Logger.h"

ArtificialSelection::ArtificialSelection() : ArtificialSelection(nullptr, nullptr) {
	
}

ArtificialSelection::ArtificialSelection(Source* target, AgentPool* agentPool) {
	Logger::info("Artificial Selection", " Initializing ... ");
	
	setTarget(target);
	setAgentPool(agentPool);
}

ArtificialSelection::~ArtificialSelection() {
}

void ArtificialSelection::run() {
	if (agentPool == nullptr) {
		Logger::error("ArtificialSelection", "Agent Poll was not created.");
		exit(-1);
	}

	if (target == nullptr) {
		Logger::error("ArtificialSelection", "Target output was not specified.");
		exit(-1);
	}

	agentPool->run();
}

void ArtificialSelection::setAgentPool(AgentPool* agentPool) {
	this->agentPool = agentPool;
}

void ArtificialSelection::setTarget(Source* target) {
	this->target = target;

	if (agentPool != nullptr) {
		agentPool->setTarget(target);
	}
}



