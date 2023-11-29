// Statemachine IoArHandlerMain instance

// Include this file in .cxx or in .hxx below implementation declaration
// *******
// Note: All referenced functions must be instance member functions that
// are either public OR IoArHandlerMain must be a friend class of IoArHandlerMain::Impl (add "friend class IoArHandlerMain;" in your class)
// *******

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

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_WriteReq(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestBackup(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_ReadReq(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestPrimary(IoArHandlerMain::kNone);



// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open",
    &OpenHandler, // Handler
    nullptr, // Parent
    &kParameterizing, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_indActions[] = {&IoArHandlerMain::Impl::ArClosed};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_ind(kClosed, IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_indActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiffActions[] = {&IoArHandlerMain::Impl::CheckModuleDiff};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiff(IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiffActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_ReadReqActions[] = {&IoArHandlerMain::Impl::Read};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_ReadReq(IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_ReadReqActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_WriteReqActions[] = {&IoArHandlerMain::Impl::Write};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_WriteReq(IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_WriteReqActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions[] = {&IoArHandlerMain::Impl::PrimarySwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimary(IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackupActions[] = {&IoArHandlerMain::Impl::BackupSwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackup(IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackupActions);



// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kParameterizing("Parameterizing",
    &ParameterizingHandler, // Handler
    &kOpen, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd(kWaitApplicationReady, IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions);
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd(kWaitApplicationReadyCnf);




// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
    &WaitApplicationReadyHandler, // Handler
    &kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Impl::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout(kWaitApplicationReady);
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout(kWaitApplicationReadyCnf);




// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
    &WaitApplicationReadyCnfHandler, // Handler
    &kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::SendApplicationReady, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf(kApplicationReady);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::AbortAr};
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf(IoArHandlerMain::kNone, IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions);



// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady",
    &ApplicationReadyHandler, // Handler
    &kOpen, // Parent
    &kReady, // Initial
    nullptr, // Entry
    nullptr); // Exit



// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
    &ReadyHandler, // Handler
    &kApplicationReady, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[] = {&IoArHandlerMain::Impl::DrPlug};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug(kDrWaitPlugCnf, IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions);
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[] = {&IoArHandlerMain::Impl::DrPull};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull(kDrWaitPullCnf, IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions);



// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning",
    &DynamicReconfigurationRunningHandler, // Handler
    &kApplicationReady, // Parent
    &kDrWaitPlugCnf, // Initial
    &IoArHandlerMain::Impl::StartDynReconfTimer, // Entry
    &IoArHandlerMain::Impl::StopDynReconfTimer); // Exit

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[] = {&IoArHandlerMain::Impl::DynReconfTimeoutAbortArSet};
const IoArHandlerMain::Transition IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf(IoArHandlerMain::kNone, IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions);



// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
    &DrWaitPullCnfHandler, // Handler
    &kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf(kReady, IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions);



// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule",
    &DrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
    &kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf(kReady, IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions);



// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
    &DrWaitApplicationReadyPlugSubmoduleHandler, // Handler
    &kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Impl::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyPlugSubmodule);
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyCnfPlugSubmodule);




// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
    &DrPlugPrmSequenceHandler, // Handler
    &kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd(kDrWaitApplicationReadyPlugSubmodule, IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions);



// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
    &DrWaitPlugCnfHandler, // Handler
    &kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf(kDrPlugPrmSequence);

// State Closed
IoArHandlerMain::Transition IoArHandlerMain::ClosedHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here

    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArOpend_ind):
        return kClosedToOpenByS_PNS_ArOpend_ind;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
        return kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
        return kClosedToClosedByS_PNS_ReadReq;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
        return kClosedToClosedByS_PNS_SwitchoverRequestBackup;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
        return kClosedToClosedByS_PNS_WriteReq;
        
    default:
        return UnhandledEvent();
    }
}

// State Open
IoArHandlerMain::Transition IoArHandlerMain::OpenHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here

    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
        return kOpenToOpenByS_PNS_CheckModuleDiff;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
        return kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
        return kOpenToOpenByS_PNS_ReadReq;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
        return kOpenToOpenByS_PNS_SwitchoverRequestBackup;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
        return kOpenToOpenByS_PNS_WriteReq;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
        return kOpenToClosedByS_PNS_ArClosed_ind;
        
    default:
        return UnhandledEvent();
    }
}

// State Parameterizing
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
        
    default:
        return UnhandledEvent();
    }
}

// State ApplicationReady
IoArHandlerMain::Transition IoArHandlerMain::ApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here

    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    default:
        return UnhandledEvent();
    }
}

// State Ready
IoArHandlerMain::Transition IoArHandlerMain::ReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here

    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
        return kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
        return kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;
        
    default:
        return UnhandledEvent();
    }
}

// State DynamicReconfigurationRunning
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

// State DrWaitPullCnf
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

// State DrWaitApplicationReadyCnfPlugSubmodule
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

// State DrPlugPrmSequence
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

// State DrWaitPlugCnf
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


