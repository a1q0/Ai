#pragma once
#include <thread>

#include "Source.h"
#include "Emulator.h"

///-------------------------------------------------------------------------------------------------
/// Class:	Agent
///
/// The Agent class
///
///-------------------------------------------------------------------------------------------------

class Agent {
public:
	/// Summary:	The agent source.
	Source& source;
	/// Summary:	The agent input.
	Source& input;
	/// Summary:	The agent output.
	Source& output;

	Emulator& emulator;

	///-------------------------------------------------------------------------------------------------
	/// Function:	Agent::Agent
	///
	/// Create an Agent with the provided Source.
	///
	///
	/// Parameters:
	/// source -   	Source that will be used by the agent. 
	/// input -    	The input. 
	/// output -   	The output. 
	///-------------------------------------------------------------------------------------------------

	Agent(Source& source, Source& input, Source& output, Emulator& emulator);

	///-------------------------------------------------------------------------------------------------
	/// Function:	Agent::~Agent
	///
	/// Summary:	Destructor.
	///
	///-------------------------------------------------------------------------------------------------

	~Agent();

	///-------------------------------------------------------------------------------------------------
	/// Function:	run
	///
	/// Run the agent source code.
	///
	/// Returns:	A std::thread.
	///-------------------------------------------------------------------------------------------------

	std::thread run();

	///-------------------------------------------------------------------------------------------------
	/// Function:	fitness
	///
	/// Calculate the fitness score of the Agent.
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