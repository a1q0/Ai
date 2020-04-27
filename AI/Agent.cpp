#include "pch.h"
#include "Agent.h"
#include "Source.h"
#include <iostream>

Agent::Agent(Source source) {
	this->source = source;
}

Agent::~Agent() {
	source.~Source();
}

float Agent::fitness(Source &target) {
	float fitness = 0;

	if (target.length != output.length) {
		std::cout << "Agent.cpp -> fitness: Target length != Output length";
		exit(-1);
	}

	for (int i = 0; i < output.length; i++)
		fitness += target.data[i] == output.data[i] / output.length;
	
	return fitness;
}
