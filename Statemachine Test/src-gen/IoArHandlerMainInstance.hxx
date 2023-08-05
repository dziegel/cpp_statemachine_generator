// Statemachine IoArHandlerMain instance

// Include this file in .cxx or in .hxx below implementation declaration
// *******
// Note: All referenced functions must be instance member functions that
// are either public OR IoArHandlerMain must be a friend class of IoArHandlerMain::Impl (add "friend class IoArHandlerMain;" in your class)
// *******

#pragma once

// Initial state
const IoArHandlerMain::StatePtr IoArHandlerMain::kInitialState = &IoArHandlerMain::kClosed;

// State Closed
const IoArHandlerMain::State IoArHandlerMain::kClosed("Closed",
    &IoArHandlerMain::Impl::IoArHandlerMainClosedHandler, // Handler
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
    &IoArHandlerMain::Impl::IoArHandlerMainOpenHandler, // Handler
    nullptr, // Parent
    &IoArHandlerMain::kParameterizing, // Initial
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
    &IoArHandlerMain::Impl::IoArHandlerMainParameterizingHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd(kWaitApplicationReady, IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions);
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd(kWaitApplicationReadyCnf);




// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
    &IoArHandlerMain::Impl::IoArHandlerMainWaitApplicationReadyHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Impl::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout(kWaitApplicationReady);
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout(kWaitApplicationReadyCnf);




// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
    &IoArHandlerMain::Impl::IoArHandlerMainWaitApplicationReadyCnfHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::SendApplicationReady, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf(kApplicationReady);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::AbortAr};
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf(IoArHandlerMain::kNone, IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions);



// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady",
    &IoArHandlerMain::Impl::IoArHandlerMainApplicationReadyHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    &IoArHandlerMain::kReady, // Initial
    nullptr, // Entry
    nullptr); // Exit



// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
    &IoArHandlerMain::Impl::IoArHandlerMainReadyHandler, // Handler
    &IoArHandlerMain::kApplicationReady, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[] = {&IoArHandlerMain::Impl::DrPlug};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug(kDrWaitPlugCnf, IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions);
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[] = {&IoArHandlerMain::Impl::DrPull};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull(kDrWaitPullCnf, IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions);



// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning",
    &IoArHandlerMain::Impl::IoArHandlerMainDynamicReconfigurationRunningHandler, // Handler
    &IoArHandlerMain::kApplicationReady, // Parent
    &IoArHandlerMain::kDrWaitPlugCnf, // Initial
    &IoArHandlerMain::Impl::StartDynReconfTimer, // Entry
    &IoArHandlerMain::Impl::StopDynReconfTimer); // Exit

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[] = {&IoArHandlerMain::Impl::DynReconfTimeoutAbortArSet};
const IoArHandlerMain::Transition IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf(IoArHandlerMain::kNone, IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions);



// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
    &IoArHandlerMain::Impl::IoArHandlerMainDrWaitPullCnfHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf(kReady, IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions);



// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule",
    &IoArHandlerMain::Impl::IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[] = {&IoArHandlerMain::Impl::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf(kReady, IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions);



// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
    &IoArHandlerMain::Impl::IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Impl::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Impl::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyPlugSubmodule);
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyCnfPlugSubmodule);




// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
    &IoArHandlerMain::Impl::IoArHandlerMainDrPlugPrmSequenceHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[] = {&IoArHandlerMain::Impl::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd(kDrWaitApplicationReadyPlugSubmodule, IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions);



// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
    &IoArHandlerMain::Impl::IoArHandlerMainDrWaitPlugCnfHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf(kDrPlugPrmSequence);
