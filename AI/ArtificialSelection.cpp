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
	delete agentPool;
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

	if (!agentPool->compile()) {
		Logger::error("ArtificialSelection", "Could not compile agents from the Agent Pool.");
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



