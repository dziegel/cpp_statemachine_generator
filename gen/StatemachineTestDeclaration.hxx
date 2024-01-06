// Statemachine StatemachineTest declaration

#pragma once

class StatemachineTest : public StatemachineTestBase
{
	public:
	static const StatePtr kInitialState;
	
	// State State_1
	static Transition State_1Handler(ImplPtr impl, Event event);
	static const State kState_1;
	
	// State State_2
	static Transition State_2Handler(ImplPtr impl, Event event);
	static const State kState_2;
	
	// State State_3
	static Transition State_3Handler(ImplPtr impl, Event event);
	static const State kState_3;
	
	// State State_4
	static Transition State_4Handler(ImplPtr impl, Event event);
	static const State kState_4;
};