// Statemachine IoArHandlerMain declaration

#pragma once

class IoArHandlerMain : public IoArHandlerMainBase
{
public:
    static const StatePtr kInitialState;
    
    // State Closed
    static Transition ClosedHandler(ImplPtr impl, Event event);
    static const State kClosed;
    
    // State Open
    static Transition OpenHandler(ImplPtr impl, Event event);
    static const State kOpen;
    
    // State ApplicationReady
    static Transition ApplicationReadyHandler(ImplPtr impl, Event event);
    static const State kApplicationReady;
    
    // State DynamicReconfigurationRunning
    static Transition DynamicReconfigurationRunningHandler(ImplPtr impl, Event event);
    static const State kDynamicReconfigurationRunning;
    
    // State DrPlugPrmSequence
    static Transition DrPlugPrmSequenceHandler(ImplPtr impl, Event event);
    static const State kDrPlugPrmSequence;
    
    // State DrWaitApplicationReadyCnfPlugSubmodule
    static Transition DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event);
    static const State kDrWaitApplicationReadyCnfPlugSubmodule;
    
    // State DrWaitApplicationReadyPlugSubmodule
    static Transition DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event);
    static const State kDrWaitApplicationReadyPlugSubmodule;
    
    // State DrWaitPlugCnf
    static Transition DrWaitPlugCnfHandler(ImplPtr impl, Event event);
    static const State kDrWaitPlugCnf;
    
    // State DrWaitPullCnf
    static Transition DrWaitPullCnfHandler(ImplPtr impl, Event event);
    static const State kDrWaitPullCnf;
    
    // State Ready
    static Transition ReadyHandler(ImplPtr impl, Event event);
    static const State kReady;
    
    // State Parameterizing
    static Transition ParameterizingHandler(ImplPtr impl, Event event);
    static const State kParameterizing;
    
    // State WaitApplicationReady
    static Transition WaitApplicationReadyHandler(ImplPtr impl, Event event);
    static const State kWaitApplicationReady;
    
    // State WaitApplicationReadyCnf
    static Transition WaitApplicationReadyCnfHandler(ImplPtr impl, Event event);
    static const State kWaitApplicationReadyCnf;
};