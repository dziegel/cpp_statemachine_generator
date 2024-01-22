// Statemachine ScXmlTest declaration

#pragma once

class ScXmlTest final : public ScXmlTestBase
{
	public:
	static const StatePtr kInitialState;
	
	// State State_1
	static Transition State_1Handler(ImplPtr impl, Event event);
	static const State kState_1;
	
	// State State_2
	static Transition State_2Handler(ImplPtr impl, Event event);
	static const State kState_1State_2;
	
	// State State_3
	static Transition State_3Handler(ImplPtr impl, Event event);
	static const State kState_1State_3;
	
	// State State_4
	static Transition State_4Handler(ImplPtr impl, Event event);
	static const HistoryState kState_1State_4;
	
	// State State_5
	static Transition State_5Handler(ImplPtr impl, Event event);
	static const State kState_1State_4State_5;
	
	// State State_6
	static Transition State_6Handler(ImplPtr impl, Event event);
	static const State kState_1State_4State_6;
};