// Statemachine IoArHandlerMain prototypes
// Include this file in your class declaration

#pragma once

// State Closed
IoArHandlerMain::Transition IoArHandlerMainClosedHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State Open
IoArHandlerMain::Transition IoArHandlerMainOpenHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State Parameterizing
IoArHandlerMain::Transition IoArHandlerMainParameterizingHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State WaitApplicationReady
IoArHandlerMain::Transition IoArHandlerMainWaitApplicationReadyHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State WaitApplicationReadyCnf
IoArHandlerMain::Transition IoArHandlerMainWaitApplicationReadyCnfHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State ApplicationReady
IoArHandlerMain::Transition IoArHandlerMainApplicationReadyHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State Ready
IoArHandlerMain::Transition IoArHandlerMainReadyHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DynamicReconfigurationRunning
IoArHandlerMain::Transition IoArHandlerMainDynamicReconfigurationRunningHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DrWaitPullCnf
IoArHandlerMain::Transition IoArHandlerMainDrWaitPullCnfHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DrWaitApplicationReadyCnfPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMainDrWaitApplicationReadyCnfPlugSubmoduleHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DrWaitApplicationReadyPlugSubmodule
IoArHandlerMain::Transition IoArHandlerMainDrWaitApplicationReadyPlugSubmoduleHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DrPlugPrmSequence
IoArHandlerMain::Transition IoArHandlerMainDrPlugPrmSequenceHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);

// State DrWaitPlugCnf
IoArHandlerMain::Transition IoArHandlerMainDrWaitPlugCnfHandler(IoArHandlerMain::StateRef state, IoArHandlerMain::Event event);


