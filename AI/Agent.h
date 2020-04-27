#pragma once
#include "Source.h"

class Agent {
public:
	/// Summary:	The agent source.
	Source source;
	/// Summary:	The agent input.
	Source input;
	/// Summary:	The agent output.
	Source output;

	///-------------------------------------------------------------------------------------------------
	/// Function:	Agent::Agent
	///
	/// Summary:	Create an Agent with the provided Source.
	///
	/// Author:	Aiko
	///
	/// Date:	27/04/2020
	///
	/// Parameters:
	/// source - 	Source that will be used by the agent.
	///-------------------------------------------------------------------------------------------------

	Agent(Source source);

	///-------------------------------------------------------------------------------------------------
	/// Function:	Agent::~Agent
	///
	/// Summary:	Destructor.
	///
	/// Author:	Aiko
	///
	/// Date:	27/04/2020
	///-------------------------------------------------------------------------------------------------

	~Agent();

	///-------------------------------------------------------------------------------------------------
	/// Function:	fitness
	///
	/// Summary:	Calculate the fitness score of the Agent.
	///
	/// Author:	Aiko.
	///
	/// Date:	27/04/2020.
	///
	/// Parameters:
	/// target - 	[in,out] Target used for the calculation. 
	///
	/// Returns:	A float.
	///-------------------------------------------------------------------------------------------------

	float fitness(Source &target);

private:

};