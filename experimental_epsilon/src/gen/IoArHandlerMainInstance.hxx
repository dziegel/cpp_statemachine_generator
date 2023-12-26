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
!TRANSITION! Open
!TRANSITION! Closed
!TRANSITION! Closed
!TRANSITION! Closed
!TRANSITION! Closed
!HANDLER! Closed

// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open",
&OpenHandler, // Handler
nullptr, // Parent
&kParameterizing, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Open
!TRANSITION! Closed
!TRANSITION! Open
!HANDLER! Open

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady",
&WaitApplicationReadyHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::StopWaitApplicationReadyTimer, // Entry
nullptr); // Exit
!TRANSITION! 
!HANDLER! WaitApplicationReady

// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kParameterizing("Parameterizing",
&ParameterizingHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! 
!HANDLER! Parameterizing

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf",
&WaitApplicationReadyCnfHandler, // Handler
&kOpen, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::SendApplicationReady, // Entry
nullptr); // Exit
!TRANSITION! ApplicationReady
!TRANSITION! WaitApplicationReadyCnf
!HANDLER! WaitApplicationReadyCnf

// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady",
&ApplicationReadyHandler, // Handler
&kOpen, // Parent
&kReady, // Initial
nullptr, // Entry
nullptr); // Exit
!HANDLER! ApplicationReady

// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning",
&DynamicReconfigurationRunningHandler, // Handler
&kApplicationReady, // Parent
&kDrWaitPlugCnf, // Initial
&IoArHandlerMain::Impl::StopDynReconfTimer, // Entry
nullptr); // Exit
!TRANSITION! DynamicReconfigurationRunning
!HANDLER! DynamicReconfigurationRunning

// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule",
&DrWaitApplicationReadyCnfPlugSubmoduleHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Ready
!HANDLER! DrWaitApplicationReadyCnfPlugSubmodule

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule",
&DrWaitApplicationReadyPlugSubmoduleHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
&IoArHandlerMain::Impl::StopWaitApplicationReadyTimer, // Entry
nullptr); // Exit
!TRANSITION! 
!HANDLER! DrWaitApplicationReadyPlugSubmodule

// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf",
&DrWaitPlugCnfHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrPlugPrmSequence
!HANDLER! DrWaitPlugCnf

// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf",
&DrWaitPullCnfHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! Ready
!HANDLER! DrWaitPullCnf

// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence",
&DrPlugPrmSequenceHandler, // Handler
&kDynamicReconfigurationRunning, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrWaitApplicationReadyPlugSubmodule
!HANDLER! DrPlugPrmSequence

// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready",
&ReadyHandler, // Handler
&kApplicationReady, // Parent
nullptr, // Initial
nullptr, // Entry
nullptr); // Exit
!TRANSITION! DrWaitPullCnf
!TRANSITION! DrWaitPlugCnf
!HANDLER! Ready
