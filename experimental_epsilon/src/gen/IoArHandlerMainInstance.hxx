// Statemachine IoArHandlerMain instance

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const IoArHandlerMain::StatePtr IoArHandlerMain::kInitialState = &IoArHandlerMain::kClosed;

// State Closed
const IoArHandlerMain::State IoArHandlerMain::kClosed("Closed",
&ClosedHandler, // Handler
nullptr, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Closed
!TRANSITION! Closed
!TRANSITION! Closed
!TRANSITION! Open
!TRANSITION! Closed
IoArHandlerMain::Transition IoArHandlerMain::ClosedHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArOpend_ind):
		return kClosedToOpenByS_PNS_ArOpend_ind;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		return kClosedToClosedByS_PNS_ReadReq;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		return kClosedToClosedByS_PNS_SwitchoverRequestBackup;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		return kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		return kClosedToClosedByS_PNS_WriteReq;
		default:
		return UnhandledEvent();
	}
}

// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open",
&OpenHandler, // Handler
nullptr, // Parent
&kParameterizing, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Closed
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Open
IoArHandlerMain::Transition IoArHandlerMain::OpenHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
		return kOpenToClosedByS_PNS_ArClosed_ind;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
		return kOpenToOpenByS_PNS_CheckModuleDiff;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		return kOpenToOpenByS_PNS_ReadReq;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		return kOpenToOpenByS_PNS_SwitchoverRequestBackup;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		return kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		return kOpenToOpenByS_PNS_WriteReq;
		default:
		return UnhandledEvent();
	}
}

// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady",
&ApplicationReadyHandler, // Handler
&kOpen, // Parent
&kReady, // Initial
nullptr, // Entry
nullptr); // Exit
IoArHandlerMain::Transition IoArHandlerMain::ApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning",
&DynamicReconfigurationRunningHandler, // Handler
&kApplicationReady, // Parent
&kDrWaitPlugCnf, // Initial
&IoArHandlerMain::Impl::StopDynReconfTimer, // Entry
nullptr); // Exit
!TRANSITION! DynamicReconfigurationRunning
IoArHandlerMain::Transition IoArHandlerMain::DynamicReconfigurationRunningHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnioAppTimeoutDynReconf):
		return kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf;
		default:
		return UnhandledEvent();
	}
}

// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
&DrPlugPrmSequenceHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrWaitApplicationReadyPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMain::DrPlugPrmSequenceHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugParamEndInd):
		return kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd;
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule",
&DrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Ready
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugApplicationReady_cnf):
		return kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf;
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
&DrWaitApplicationReadyPlugSubmoduleHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::StopWaitApplicationReadyTimer, // Entry
nullptr); // Exit
!TRANSITION! 
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout;
		}
		return kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout;
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
&DrWaitPlugCnfHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrPlugPrmSequence
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPlugCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugSubmodule_cnf):
		return kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf;
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
&DrWaitPullCnfHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Ready
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPullCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PullSubmodule_cnf):
		return kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf;
		default:
		return UnhandledEvent();
	}
}

// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
&ReadyHandler, // Handler
&kApplicationReady, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrWaitPlugCnf
!TRANSITION! DrWaitPullCnf
IoArHandlerMain::Transition IoArHandlerMain::ReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
		return kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
		return kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;
		default:
		return UnhandledEvent();
	}
}

// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kParameterizing("Parameterizing",
&ParameterizingHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! 
IoArHandlerMain::Transition IoArHandlerMain::ParameterizingHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ParamEndInd):
		if (impl->FirstInArSetOrPrimary(event))
		{
			return kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd;
		}
		return kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd;
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
&WaitApplicationReadyHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::StopWaitApplicationReadyTimer, // Entry
nullptr); // Exit
!TRANSITION! 
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout;
		}
		return kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout;
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
&WaitApplicationReadyCnfHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::SendApplicationReady, // Entry
nullptr); // Exit
!TRANSITION! ApplicationReady
!TRANSITION! WaitApplicationReadyCnf
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
		if (impl->success(event))
		{
			return kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;
		}
		return kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
		if (impl->success(event))
		{
			return kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;
		}
		return kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;
		default:
		return UnhandledEvent();
	}
}
