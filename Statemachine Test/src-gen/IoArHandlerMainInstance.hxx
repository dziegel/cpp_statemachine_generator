// Statemachine IoArHandlerMain instance

// Include this file in .cxx or in .hxx below Owner declaration
// *******
// Note: All referenced functions must be instance member functions that
// are either public OR IoArHandlerMain must be a friend class of IoArHandlerMain::Owner (add "friend class
// IoArHandlerMain;" in your class)
// *******

#pragma once

// Initial state
const IoArHandlerMain::StatePtr IoArHandlerMain::kInitialState = &IoArHandlerMain::kClosed;

// State Closed
const IoArHandlerMain::State IoArHandlerMain::kClosed("Closed",
                                                      &IoArHandlerMain::Owner::IoArHandlerMainClosedHandler, // Handler
                                                      nullptr,                                               // Parent
                                                      nullptr,                                               // Initial
                                                      nullptr,                                               // Entry
                                                      nullptr);                                              // Exit
const IoArHandlerMain::Transition IoArHandlerMain::kClosedToOpenByS_PNS_ArOpend_ind(kOpen);

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_WriteReq(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition
    IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestBackup(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition IoArHandlerMain::kClosedToClosedByS_PNS_ReadReq(IoArHandlerMain::kNone);

const IoArHandlerMain::Transition
    IoArHandlerMain::kClosedToClosedByS_PNS_SwitchoverRequestPrimary(IoArHandlerMain::kNone);

// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open",
                                                    &IoArHandlerMain::Owner::IoArHandlerMainOpenHandler, // Handler
                                                    nullptr,                                             // Parent
                                                    &IoArHandlerMain::kParameterizing,                   // Initial
                                                    nullptr,                                             // Entry
                                                    nullptr);                                            // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_indActions[] = {
    &IoArHandlerMain::Owner::ArClosed};
const IoArHandlerMain::Transition
    IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_ind(kClosed,
                                                       IoArHandlerMain::kOpenToClosedByS_PNS_ArClosed_indActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackupActions[] = {
    &IoArHandlerMain::Owner::BackupSwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackup(
    IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestBackupActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiffActions[] = {
    &IoArHandlerMain::Owner::CheckModuleDiff};
const IoArHandlerMain::Transition
    IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiff(IoArHandlerMain::kNone,
                                                        IoArHandlerMain::kOpenToOpenByS_PNS_CheckModuleDiffActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_WriteReqActions[] = {
    &IoArHandlerMain::Owner::Write};
const IoArHandlerMain::Transition
    IoArHandlerMain::kOpenToOpenByS_PNS_WriteReq(IoArHandlerMain::kNone,
                                                 IoArHandlerMain::kOpenToOpenByS_PNS_WriteReqActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_ReadReqActions[] = {
    &IoArHandlerMain::Owner::Read};
const IoArHandlerMain::Transition
    IoArHandlerMain::kOpenToOpenByS_PNS_ReadReq(IoArHandlerMain::kNone,
                                                IoArHandlerMain::kOpenToOpenByS_PNS_ReadReqActions);

const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions[] = {
    &IoArHandlerMain::Owner::PrimarySwitchover};
const IoArHandlerMain::Transition IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimary(
    IoArHandlerMain::kNone, IoArHandlerMain::kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions);

// State Parameterizing
const IoArHandlerMain::State
    IoArHandlerMain::kParameterizing("Parameterizing",
                                     &IoArHandlerMain::Owner::IoArHandlerMainParameterizingHandler, // Handler
                                     &IoArHandlerMain::kOpen,                                       // Parent
                                     nullptr,                                                       // Initial
                                     nullptr,                                                       // Entry
                                     nullptr);                                                      // Exit
const IoArHandlerMain::Transition::ActionType
    IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[] = {
        &IoArHandlerMain::Owner::ApplyConfiguration};
const IoArHandlerMain::Transition IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd(
    kWaitApplicationReady, IoArHandlerMain::kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions);
const IoArHandlerMain::Transition
    IoArHandlerMain::kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd(kWaitApplicationReadyCnf);

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady(
    "WaitApplicationReady",
    &IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyHandler, // Handler
    &IoArHandlerMain::kOpen,                                             // Parent
    nullptr,                                                             // Initial
    &IoArHandlerMain::Owner::StartWaitApplicationReadyTimer,             // Entry
    &IoArHandlerMain::Owner::StopWaitApplicationReadyTimer);             // Exit
const IoArHandlerMain::Transition
    IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout(kWaitApplicationReady);
const IoArHandlerMain::Transition
    IoArHandlerMain::kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout(kWaitApplicationReadyCnf);

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf(
    "WaitApplicationReadyCnf",
    &IoArHandlerMain::Owner::IoArHandlerMainWaitApplicationReadyCnfHandler, // Handler
    &IoArHandlerMain::kOpen,                                                // Parent
    nullptr,                                                                // Initial
    &IoArHandlerMain::Owner::SendApplicationReady,                          // Entry
    nullptr);                                                               // Exit
const IoArHandlerMain::Transition
    IoArHandlerMain::kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf(kApplicationReady);

const IoArHandlerMain::Transition::ActionType
    IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[] = {
        &IoArHandlerMain::Owner::AbortAr};
const IoArHandlerMain::Transition
    IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf(
        IoArHandlerMain::kNone,
        IoArHandlerMain::kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions);

// State ApplicationReady
const IoArHandlerMain::State
    IoArHandlerMain::kApplicationReady("ApplicationReady",
                                       &IoArHandlerMain::Owner::IoArHandlerMainApplicationReadyHandler, // Handler
                                       &IoArHandlerMain::kOpen,                                         // Parent
                                       &IoArHandlerMain::kReady,                                        // Initial
                                       nullptr,                                                         // Entry
                                       nullptr);                                                        // Exit

// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
                                                     &IoArHandlerMain::Owner::IoArHandlerMainReadyHandler, // Handler
                                                     &IoArHandlerMain::kApplicationReady,                  // Parent
                                                     nullptr,                                              // Initial
                                                     nullptr,                                              // Entry
                                                     nullptr);                                             // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[] = {
    &IoArHandlerMain::Owner::DrPlug};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug(
    kDrWaitPlugCnf, IoArHandlerMain::kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions);
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[] = {
    &IoArHandlerMain::Owner::DrPull};
const IoArHandlerMain::Transition IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPull(
    kDrWaitPullCnf, IoArHandlerMain::kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions);

// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning(
    "DynamicReconfigurationRunning",
    &IoArHandlerMain::Owner::IoArHandlerMainDynamicReconfigurationRunningHandler, // Handler
    &IoArHandlerMain::kApplicationReady,                                          // Parent
    &IoArHandlerMain::kDrWaitPlugCnf,                                             // Initial
    &IoArHandlerMain::Owner::StartDynReconfTimer,                                 // Entry
    &IoArHandlerMain::Owner::StopDynReconfTimer);                                 // Exit

const IoArHandlerMain::Transition::ActionType
    IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[] =
        {&IoArHandlerMain::Owner::DynReconfTimeoutAbortArSet};
const IoArHandlerMain::Transition
    IoArHandlerMain::kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf(
        IoArHandlerMain::kNone,
        IoArHandlerMain::
            kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions);

// State DrWaitPullCnf
const IoArHandlerMain::State
    IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
                                    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitPullCnfHandler, // Handler
                                    &IoArHandlerMain::kDynamicReconfigurationRunning,             // Parent
                                    nullptr,                                                      // Initial
                                    nullptr,                                                      // Entry
                                    nullptr);                                                     // Exit
const IoArHandlerMain::Transition::ActionType IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[] =
    {&IoArHandlerMain::Owner::DrPullDone};
const IoArHandlerMain::Transition IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf(
    kReady, IoArHandlerMain::kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions);

// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule(
    "DrWaitApplicationReadyCnfPlugSubmodule",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning,                                      // Parent
    nullptr,                                                                               // Initial
    nullptr,                                                                               // Entry
    nullptr);                                                                              // Exit
const IoArHandlerMain::Transition::ActionType
    IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[] = {
        &IoArHandlerMain::Owner::DrPullDone};
const IoArHandlerMain::Transition
    IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf(
        kReady, kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions);

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule(
    "DrWaitApplicationReadyPlugSubmodule",
    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler, // Handler
    &IoArHandlerMain::kDynamicReconfigurationRunning,                                   // Parent
    nullptr,                                                                            // Initial
    &IoArHandlerMain::Owner::StartWaitApplicationReadyTimer,                            // Entry
    &IoArHandlerMain::Owner::StopWaitApplicationReadyTimer);                            // Exit
const IoArHandlerMain::Transition
    IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout(
        kDrWaitApplicationReadyPlugSubmodule);
const IoArHandlerMain::Transition
    IoArHandlerMain::kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout(
        kDrWaitApplicationReadyCnfPlugSubmodule);

// State DrPlugPrmSequence
const IoArHandlerMain::State
    IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
                                        &IoArHandlerMain::Owner::IoArHandlerMainDrPlugPrmSequenceHandler, // Handler
                                        &IoArHandlerMain::kDynamicReconfigurationRunning,                 // Parent
                                        nullptr,                                                          // Initial
                                        nullptr,                                                          // Entry
                                        nullptr);                                                         // Exit
const IoArHandlerMain::Transition::ActionType
    IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[] = {
        &IoArHandlerMain::Owner::ApplyConfiguration};
const IoArHandlerMain::Transition
    IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd(
        kDrWaitApplicationReadyPlugSubmodule,
        IoArHandlerMain::kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions);

// State DrWaitPlugCnf
const IoArHandlerMain::State
    IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
                                    &IoArHandlerMain::Owner::IoArHandlerMainDrWaitPlugCnfHandler, // Handler
                                    &IoArHandlerMain::kDynamicReconfigurationRunning,             // Parent
                                    nullptr,                                                      // Initial
                                    nullptr,                                                      // Entry
                                    nullptr);                                                     // Exit
const IoArHandlerMain::Transition
    IoArHandlerMain::kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf(kDrPlugPrmSequence);
