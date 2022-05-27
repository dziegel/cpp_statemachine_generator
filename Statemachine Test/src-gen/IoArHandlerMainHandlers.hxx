// Statemachine IoArHandlerMain handlers
// Include this file in .cxx or in .hxx below Owner declaration

#pragma once

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// State Closed
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainClosedHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
        return IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestBackup;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
        return IoArHandlerMain::kClosedToClosedByS_PNS_WriteReq;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
        return IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArOpend_ind):
        return IoArHandlerMain::kClosedToOpenByS_PNS_ArOpend_ind;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
        return IoArHandlerMain::kClosedToClosedByS_PNS_ReadReq;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State Open
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainOpenHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
        return IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackup;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
        return IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_ind;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
        return IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
        return IoArHandlerMain::kOpenToOpenByS_PNS_WriteReq;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
        return IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiff;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
        return IoArHandlerMain::kOpenToOpenByS_PNS_ReadReq;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State Parameterizing
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainParameterizingHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ParamEndInd):
        if (FirstInArSetOrPrimary)
        {
            return IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd;
        }
        return IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State WaitApplicationReady
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
        if (CheckApplicationReady())
        {
            return IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout;
        }
        return IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State WaitApplicationReadyCnf
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyCnfHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
        if (success)
        {
            return IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;
        }
        
        return IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State ApplicationReady
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainApplicationReadyHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State Ready
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainReadyHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
        return IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;
        
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
        return IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DynamicReconfigurationRunning
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDynamicReconfigurationRunningHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnioAppTimeoutDynReconf):
        return IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DrWaitPullCnf
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDrWaitPullCnfHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PullSubmodule_cnf):
        return IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DrWaitApplicationReadyCnfPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugApplicationReady_cnf):
        return IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DrWaitApplicationReadyPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
        if (CheckApplicationReady())
        {
            return IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout;
        }
        return IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DrPlugPrmSequence
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDrPlugPrmSequenceHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugParamEndInd):
        return IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}

// State DrWaitPlugCnf
IoArHandlerMain::Transition IoArHandlerMain::Owner::IoArHandlerMainDrWaitPlugCnfHandler(IoArHandlerMain::StatePtr /* state */, IoArHandlerMain::Event event)
{
    switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
    {
    case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugSubmodule_cnf):
        return IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf;
        
    default:
        return IoArHandlerMain::UnhandledEvent();
    }
}


