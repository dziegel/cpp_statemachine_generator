// Statemachine IoArHandlerMain declaration
// Include this file in .hxx before implementation declaration
//
// Before including this header, add the following using declaration in your file:
// class IoArHandlerMainImpl;
// using IoArHandlerMainBase = cpp_event_framework::Statemachine<IoArHandlerMainImpl, const cpp_event_framework::Signal::SPtr&>;

#pragma once

class IoArHandlerMain : public IoArHandlerMainBase
{
public:
    static const StatePtr kInitialState;

    // State Closed
    static const State kClosed;
    static const Transition::ActionType kClosedToOpenByS_PNS_ArOpend_indActions[];
    static const Transition kClosedToOpenByS_PNS_ArOpend_ind;

    static const Transition::ActionType kClosedToClosedByS_PNS_SwitchoverRequestPrimaryActions[];
    static const Transition kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
    static const Transition::ActionType kClosedToClosedByS_PNS_SwitchoverRequestBackupActions[];
    static const Transition kClosedToClosedByS_PNS_SwitchoverRequestBackup;
    static const Transition::ActionType kClosedToClosedByS_PNS_WriteReqActions[];
    static const Transition kClosedToClosedByS_PNS_WriteReq;
    static const Transition::ActionType kClosedToClosedByS_PNS_ReadReqActions[];
    static const Transition kClosedToClosedByS_PNS_ReadReq;

    // State Open
    static const State kOpen;
    static const Transition::ActionType kOpenToClosedByS_PNS_ArClosed_indActions[];
    static const Transition kOpenToClosedByS_PNS_ArClosed_ind;

    static const Transition::ActionType kOpenToOpenByS_PNS_WriteReqActions[];
    static const Transition kOpenToOpenByS_PNS_WriteReq;
    static const Transition::ActionType kOpenToOpenByS_PNS_SwitchoverRequestBackupActions[];
    static const Transition kOpenToOpenByS_PNS_SwitchoverRequestBackup;
    static const Transition::ActionType kOpenToOpenByS_PNS_CheckModuleDiffActions[];
    static const Transition kOpenToOpenByS_PNS_CheckModuleDiff;
    static const Transition::ActionType kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions[];
    static const Transition kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
    static const Transition::ActionType kOpenToOpenByS_PNS_ReadReqActions[];
    static const Transition kOpenToOpenByS_PNS_ReadReq;

    // State Parameterizing
    static const State kParameterizing;
    static const Transition::ActionType kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndIndActions[];
    static const Transition kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd;
    static const Transition::ActionType kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[];
    static const Transition kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd;


    // State WaitApplicationReady
    static const State kWaitApplicationReady;
    static const Transition::ActionType kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeoutActions[];
    static const Transition kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout;
    static const Transition::ActionType kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeoutActions[];
    static const Transition kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout;


    // State WaitApplicationReadyCnf
    static const State kWaitApplicationReadyCnf;
    static const Transition::ActionType kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnfActions[];
    static const Transition kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;

    static const Transition::ActionType kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[];
    static const Transition kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;

    // State ApplicationReady
    static const State kApplicationReady;


    // State Ready
    static const State kReady;
    static const Transition::ActionType kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[];
    static const Transition kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;
    static const Transition::ActionType kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[];
    static const Transition kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;


    // State DynamicReconfigurationRunning
    static const State kDynamicReconfigurationRunning;

    static const Transition::ActionType kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[];
    static const Transition kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf;

    // State DrWaitPullCnf
    static const State kDrWaitPullCnf;
    static const Transition::ActionType kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[];
    static const Transition kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf;


    // State DrWaitApplicationReadyCnfPlugSubmodule
    static const State kDrWaitApplicationReadyCnfPlugSubmodule;
    static const Transition::ActionType kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[];
    static const Transition kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf;


    // State DrWaitApplicationReadyPlugSubmodule
    static const State kDrWaitApplicationReadyPlugSubmodule;
    static const Transition::ActionType kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeoutActions[];
    static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout;
    static const Transition::ActionType kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeoutActions[];
    static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout;


    // State DrPlugPrmSequence
    static const State kDrPlugPrmSequence;
    static const Transition::ActionType kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[];
    static const Transition kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd;


    // State DrWaitPlugCnf
    static const State kDrWaitPlugCnf;
    static const Transition::ActionType kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnfActions[];
    static const Transition kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf;




    // State Closed
    static IoArHandlerMain::Transition ClosedHandler(ImplPtr impl, Event event);

    // State Open
    static IoArHandlerMain::Transition OpenHandler(ImplPtr impl, Event event);

    // State Parameterizing
    static IoArHandlerMain::Transition ParameterizingHandler(ImplPtr impl, Event event);

    // State WaitApplicationReady
    static IoArHandlerMain::Transition WaitApplicationReadyHandler(ImplPtr impl, Event event);

    // State WaitApplicationReadyCnf
    static IoArHandlerMain::Transition WaitApplicationReadyCnfHandler(ImplPtr impl, Event event);

    // State ApplicationReady
    static IoArHandlerMain::Transition ApplicationReadyHandler(ImplPtr impl, Event event);

    // State Ready
    static IoArHandlerMain::Transition ReadyHandler(ImplPtr impl, Event event);

    // State DynamicReconfigurationRunning
    static IoArHandlerMain::Transition DynamicReconfigurationRunningHandler(ImplPtr impl, Event event);

    // State DrWaitPullCnf
    static IoArHandlerMain::Transition DrWaitPullCnfHandler(ImplPtr impl, Event event);

    // State DrWaitApplicationReadyCnfPlugSubmodule
    static IoArHandlerMain::Transition DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event);

    // State DrWaitApplicationReadyPlugSubmodule
    static IoArHandlerMain::Transition DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event);

    // State DrPlugPrmSequence
    static IoArHandlerMain::Transition DrPlugPrmSequenceHandler(ImplPtr impl, Event event);

    // State DrWaitPlugCnf
    static IoArHandlerMain::Transition DrWaitPlugCnfHandler(ImplPtr impl, Event event);


};
