// Statemachine IoArHandlerMain prototypes
// Include this file in your class declaration

#pragma once

// State Closed
IoArHandlerMain::Transition IoArHandlerMainClosedHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State Open
IoArHandlerMain::Transition IoArHandlerMainOpenHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State Parameterizing
IoArHandlerMain::Transition IoArHandlerMainParameterizingHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State WaitApplicationReady
IoArHandlerMain::Transition IoArHandlerMainWaitApplicationReadyHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State WaitApplicationReadyCnf
IoArHandlerMain::Transition IoArHandlerMainWaitApplicationReadyCnfHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State ApplicationReady
IoArHandlerMain::Transition IoArHandlerMainApplicationReadyHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State Ready
IoArHandlerMain::Transition IoArHandlerMainReadyHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DynamicReconfigurationRunning
IoArHandlerMain::Transition IoArHandlerMainDynamicReconfigurationRunningHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DrWaitPullCnf
IoArHandlerMain::Transition IoArHandlerMainDrWaitPullCnfHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DrWaitApplicationReadyCnfPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DrWaitApplicationReadyPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DrPlugPrmSequence
IoArHandlerMain::Transition IoArHandlerMainDrPlugPrmSequenceHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);

// State DrWaitPlugCnf
IoArHandlerMain::Transition IoArHandlerMainDrWaitPlugCnfHandler(IoArHandlerMain::StatePtr state, IoArHandlerMain::Event event);


