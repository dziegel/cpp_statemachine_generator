// Statemachine IoArHandlerMain instance

// Include this file in .cxx or in .hxx below Owner declaration
// *******
// Note: All referenced functions must be instance member functions that
// are either public OR IoArHandlerMain must be a friend class of IoArHandlerMain::Owner (add "friend class IoArHandlerMain;" in your class)
// *******

#pragma once

// Initial state
const IoArHandlerMain::StatePtr IoArHandlerMain::kInitialState = &IoArHandlerMain::kClosed;

// State Closed
const IoArHandlerMain::State IoArHandlerMain::kClosed("Closed",
    &IoArHandlerMain::Owner::IoArHandlerMainClosedHandler, // Handler
    nullptr, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToOpenByS_PNS_ArOpend_ind(kOpen, std::vector<IoArHandlerMain::Transition::ActionType>({}));

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestBackup(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({}));
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_WriteReq(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({}));
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestPrimary(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({}));
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_ReadReq(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({}));


// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open",
    &IoArHandlerMain::Owner::IoArHandlerMainOpenHandler, // Handler
    nullptr, // Parent
    &IoArHandlerMain::kParameterizing, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_ind(kClosed, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::ArClosed)}));

const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimary(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::PrimarySwitchover)}));
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackup(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::BackupSwitchover)}));
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_ReadReq(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::Read)}));
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_WriteReq(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::Write)}));
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiff(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::CheckModuleDiff)}));


// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kParameterizing("Parameterizing",
    &IoArHandlerMain::Owner::IoArHandlerMainParameterizingHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd(kWaitApplicationReady, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::ApplyConfiguration)}));
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd(kWaitApplicationReadyCnf, std::vector<IoArHandlerMain::Transition::ActionType>({}));




// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
    &IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Owner::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Owner::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout(kWaitApplicationReady, std::vector<IoArHandlerMain::Transition::ActionType>({}));
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout(kWaitApplicationReadyCnf, std::vector<IoArHandlerMain::Transition::ActionType>({}));




// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
    &IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyCnfHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Owner::SendApplicationReady, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf(kApplicationReady, std::vector<IoArHandlerMain::Transition::ActionType>({}));

const IoArHandlerMain::Transition IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::AbortAr)}));


// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady",
    &IoArHandlerMain::Owner::IoArHandlerMainApplicationReadyHandler, // Handler
    &IoArHandlerMain::kOpen, // Parent
    &IoArHandlerMain::kReady, // Initial
    nullptr, // Entry
    nullptr); // Exit



// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
    &IoArHandlerMain::Owner::IoArHandlerMainReadyHandler, // Handler
    &IoArHandlerMain::kApplicationReady, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull(kDrWaitPullCnf, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::DrPull)}));
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug(kDrWaitPlugCnf, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::DrPlug)}));



// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning",
    &IoArHandlerMain::Owner::IoArHandlerMainDynamicReconfigurationRunningHandler, // Handler
    &IoArHandlerMain::kApplicationReady, // Parent
    &IoArHandlerMain::kDrWaitPlugCnf, // Initial
    &IoArHandlerMain::Owner::StartDynReconfTimer, // Entry
    &IoArHandlerMain::Owner::StopDynReconfTimer); // Exit

const IoArHandlerMain::Transition IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf(IoArHandlerMain::kNone, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::DynReconfTimeoutAbortArSet)}));


// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitPullCnfHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf(kReady, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::DrPullDone)}));



// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf(kReady, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::DrPullDone)}));



// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    &IoArHandlerMain::Owner::StartWaitApplicationReadyTimer, // Entry
    &IoArHandlerMain::Owner::StopWaitApplicationReadyTimer); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyPlugSubmodule, std::vector<IoArHandlerMain::Transition::ActionType>({}));
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout(kDrWaitApplicationReadyCnfPlugSubmodule, std::vector<IoArHandlerMain::Transition::ActionType>({}));




// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
    &IoArHandlerMain::Owner::IoArHandlerMainDrPlugPrmSequenceHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd(kDrWaitApplicationReadyPlugSubmodule, std::vector<IoArHandlerMain::Transition::ActionType>({std::mem_fn(&IoArHandlerMain::Owner::ApplyConfiguration)}));



// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitPlugCnfHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning, // Parent
    nullptr, // Initial
    nullptr, // Entry
    nullptr); // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf(kDrPlugPrmSequence, std::vector<IoArHandlerMain::Transition::ActionType>({}));
