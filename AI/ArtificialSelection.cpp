#include "pch.h"

#include <iostream>

#include "ArtificialSelection.h"
#include "Logger.h"



ArtificialSelection::ArtificialSelection() {
	Logger::info("Artificial Selection", " Initializing ... ");
	
}

ArtificialSelection::ArtificialSelection(Source * target, AgentPool * agentPool) {
	this->target = target;
	this->agentPool = agentPool;

	ArtificialSelection();
}

ArtificialSelection::~ArtificialSelection() {
}

void ArtificialSelection::run() {
	if (agentPool == nullptr) {}
}

void ArtificialSelection::setAgentPool(AgentPool* agentPool) {
	this->agentPool = agentPool;
}

void ArtificialSelection::setTarget(Source* target) {
	this->target = target;
}



