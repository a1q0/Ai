#pragma once
#include "Source.h"

///-------------------------------------------------------------------------------------------------
/// Class:	Agent
///
/// Summary:	The Agent class
///
/// Author:	Aiko
///
/// Date:	27/04/2020
///-------------------------------------------------------------------------------------------------

class Agent {
public:
	/// Summary:	The agent source.
	Source source;
	/// Summary:	The agent input.
	Source input;
	/// Summary:	The agent output.
	Source output;

	/// Summary:	The program length (source + input + output).
	int length;

	///-------------------------------------------------------------------------------------------------
	/// Function:	Agent::Agent
	///
	/// Summary:	Create an Agent with the provided Source.
	///
	/// Author:	Aiko.
	///
	/// Date:	27/04/2020.
	///
	/// Parameters:
	/// source -   	Source that will be used by the agent. 
	/// input -    	The input. 
	/// output -   	The output. 
	///-------------------------------------------------------------------------------------------------

	Agent(Source source, Source input, Source output);

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
	/// Function:	run
	///
	/// Summary:	Run the agent source code.
	///
	/// Author:	Aiko
	///
	/// Date:	27/04/2020
	///
	/// Returns:	A std::thread.
	///-------------------------------------------------------------------------------------------------

	std::thread run();

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
	void start();
};