// Statemachine IoArHandlerMain declaration
// Include this file in .hxx before Owner declaration
//
// Before including this header, add the following using declaration in your file:
// class MyClassContainingThisStatemachine;
// using IoArHandlerMainBase = cpp_event_framework::Statemachine<MyClassContainingThisStatemachine, const cpp_event_framework::Signal::SPtr&>;

#pragma once

class IoArHandlerMain : public IoArHandlerMainBase
{
public:
    static const StatePtr kInitialState;

    // State Closed
    static const State kClosed;
    static const Transition kClosedToOpenByS_PNS_ArOpend_ind;

    static const Transition kClosedToClosedByS_PNS_SwitchoverRequestBackup;
    static const Transition kClosedToClosedByS_PNS_WriteReq;
    static const Transition kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
    static const Transition kClosedToClosedByS_PNS_ReadReq;

    // State Open
    static const State kOpen;
    static const Transition kOpenToClosedByS_PNS_ArClosed_ind;

    static const Transition kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
    static const Transition kOpenToOpenByS_PNS_ReadReq;
    static const Transition kOpenToOpenByS_PNS_CheckModuleDiff;
    static const Transition kOpenToOpenByS_PNS_WriteReq;
    static const Transition kOpenToOpenByS_PNS_SwitchoverRequestBackup;

    // State Parameterizing
    static const State kParameterizing;
    static const Transition kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd;
    static const Transition kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd;


    // State WaitApplicationReady
    static const State kWaitApplicationReady;
    static const Transition kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout;
    static const Transition kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout;


    // State WaitApplicationReadyCnf
    static const State kWaitApplicationReadyCnf;
    static const Transition kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;

    static const Transition kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;

    // State ApplicationReady
    static const State kApplicationReady;


    // State Ready
    static const State kReady;
    static const Transition kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;
    static const Transition kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;


    // State DynamicReconfigurationRunning
    static const State kDynamicReconfigurationRunning;

    static const Transition kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf;

    // State DrWaitPullCnf
    static const State kDrWaitPullCnf;
    static const Transition kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf;


    // State DrWaitApplicationReadyCnfPlugSubmodule
    static const State kDrWaitApplicationReadyCnfPlugSubmodule;
    static const Transition kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf;


    // State DrWaitApplicationReadyPlugSubmodule
    static const State kDrWaitApplicationReadyPlugSubmodule;
    static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout;
    static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout;


    // State DrPlugPrmSequence
    static const State kDrPlugPrmSequence;
    static const Transition kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd;


    // State DrWaitPlugCnf
    static const State kDrWaitPlugCnf;
    static const Transition kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf;



};
