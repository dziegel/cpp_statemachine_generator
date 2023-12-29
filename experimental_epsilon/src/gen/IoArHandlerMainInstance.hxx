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

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToOpenByS_PNS_ArOpend_ind(kOpen);
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_ReadReq(kClosed);
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestBackup(kClosed);
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestPrimary(kClosed);
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_WriteReq(kClosed);

IoArHandlerMain::Transition IoArHandlerMain::ClosedHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArOpend_ind):
		Closed -> Open
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		Closed -> Closed
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		Closed -> Closed
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		Closed -> Closed
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		Closed -> Closed
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_indActions[] = {&IoArHandlerMain::Impl::ArClosed};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_ind(kClosed, kOpenToClosedByS_PNS_ArClosed_indActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiffActions[] = {&IoArHandlerMain::Impl::CheckModuleDiff};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiff(kOpen, kOpenToOpenByS_PNS_CheckModuleDiffActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToOpenByS_PNS_ReadReqActions[] = {&IoArHandlerMain::Impl::Read};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_ReadReq(kOpen, kOpenToOpenByS_PNS_ReadReqActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackupActions[] = {&IoArHandlerMain::Impl::BackupSwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackup(kOpen, kOpenToOpenByS_PNS_SwitchoverRequestBackupActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions[] = {&IoArHandlerMain::Impl::PrimarySwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimary(kOpen, kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kOpenToOpenByS_PNS_WriteReqActions[] = {&IoArHandlerMain::Impl::Write};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_WriteReq(kOpen, kOpenToOpenByS_PNS_WriteReqActions);

IoArHandlerMain::Transition IoArHandlerMain::OpenHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
		Open -> Closed
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
		Open -> Open
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		Open -> Open
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		Open -> Open
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		Open -> Open
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		Open -> Open
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
&StartDynReconfTimer, // Entry
&StopDynReconfTimer); // Exit

const IoArHandlerMain::Transition::Action IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[] = {&IoArHandlerMain::Impl::DynReconfTimeoutAbortArSet};
const IoArHandlerMain::Transition IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf(kDynamicReconfigurationRunning, kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions);

IoArHandlerMain::Transition IoArHandlerMain::DynamicReconfigurationRunningHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnioAppTimeoutDynReconf):
		DynamicReconfigurationRunning -> DynamicReconfigurationRunning
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd(kDrWaitApplicationReadyPlugSubmodule, kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions);

IoArHandlerMain::Transition IoArHandlerMain::DrPlugPrmSequenceHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugParamEndInd):
		DrPlugPrmSequence -> DrWaitApplicationReadyPlugSubmodule
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf(kReady, kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions);

IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugApplicationReady_cnf):
		DrWaitApplicationReadyCnfPlugSubmodule -> Ready
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
&DrWaitApplicationReadyPlugSubmoduleHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
&StartWaitApplicationReadyTimer, // Entry
&StopWaitApplicationReadyTimer); // Exit

const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyCnfPlugSubmodule);
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyPlugSubmodule);

IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		DrWaitApplicationReadyPlugSubmodule -> DrWaitApplicationReadyCnfPlugSubmodule
		DrWaitApplicationReadyPlugSubmodule -> DrWaitApplicationReadyPlugSubmodule
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

const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf(kDrPlugPrmSequence);

IoArHandlerMain::Transition IoArHandlerMain::DrWaitPlugCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugSubmodule_cnf):
		DrWaitPlugCnf -> DrPlugPrmSequence
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf(kReady, kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions);

IoArHandlerMain::Transition IoArHandlerMain::DrWaitPullCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PullSubmodule_cnf):
		DrWaitPullCnf -> Ready
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[] = {&IoArHandlerMain::Impl::DrPlug};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug(kDrWaitPlugCnf, kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[] = {&IoArHandlerMain::Impl::DrPull};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull(kDrWaitPullCnf, kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions);

IoArHandlerMain::Transition IoArHandlerMain::ReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
		Ready -> DrWaitPlugCnf
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
		Ready -> DrWaitPullCnf
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

const IoArHandlerMain::Transition::Action IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd(kWaitApplicationReady, kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions);
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd(kWaitApplicationReadyCnf);

IoArHandlerMain::Transition IoArHandlerMain::ParameterizingHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ParamEndInd):
		Parameterizing -> WaitApplicationReady
		Parameterizing -> WaitApplicationReadyCnf
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
&WaitApplicationReadyHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&StartWaitApplicationReadyTimer, // Entry
&StopWaitApplicationReadyTimer); // Exit

const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout(kWaitApplicationReady);
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout(kWaitApplicationReadyCnf);

IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		WaitApplicationReady -> WaitApplicationReady
		WaitApplicationReady -> WaitApplicationReadyCnf
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
&WaitApplicationReadyCnfHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&SendApplicationReady, // Entry
nullptr); // Exit

const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf(kApplicationReady);
const IoArHandlerMain::Transition::Action IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::AbortAr};
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf(kWaitApplicationReadyCnf, kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions);

IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
		WaitApplicationReadyCnf -> ApplicationReady
		WaitApplicationReadyCnf -> WaitApplicationReadyCnf
		default:
		return UnhandledEvent();
	}
}
