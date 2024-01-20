// Statemachine IoArHandlerMain declaration

#pragma once

class IoArHandlerMain final : public IoArHandlerMainBase
{
	public:
	static const StatePtr kInitialState;
	
	// State Closed
	static Transition ClosedHandler(ImplPtr impl, Event event);
	static const State kClosed;
	
	// State Open
	static Transition OpenHandler(ImplPtr impl, Event event);
	static const State kOpen;
	
	// State ApplicationReady
	static Transition ApplicationReadyHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReady;
	
	// State DynamicReconfigurationRunning
	static Transition DynamicReconfigurationRunningHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunning;
	
	// State DrPlugPrmSequence
	static Transition DrPlugPrmSequenceHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunningDrPlugPrmSequence;
	
	// State DrWaitApplicationReadyCnfPlugSubmodule
	static Transition DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyCnfPlugSubmodule;
	
	// State DrWaitApplicationReadyPlugSubmodule
	static Transition DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyPlugSubmodule;
	
	// State DrWaitPlugCnf
	static Transition DrWaitPlugCnfHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPlugCnf;
	
	// State DrWaitPullCnf
	static Transition DrWaitPullCnfHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPullCnf;
	
	// State Ready
	static Transition ReadyHandler(ImplPtr impl, Event event);
	static const State kOpenApplicationReadyReady;
	
	// State Parameterizing
	static Transition ParameterizingHandler(ImplPtr impl, Event event);
	static const State kOpenParameterizing;
	
	// State WaitApplicationReady
	static Transition WaitApplicationReadyHandler(ImplPtr impl, Event event);
	static const State kOpenWaitApplicationReady;
	
	// State WaitApplicationReadyCnf
	static Transition WaitApplicationReadyCnfHandler(ImplPtr impl, Event event);
	static const State kOpenWaitApplicationReadyCnf;
};