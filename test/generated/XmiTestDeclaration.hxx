// Statemachine XmiTest declaration

#pragma once

class XmiTest final : public XmiTestBase
{
	public:
	static const StatePtr kInitialState;
	
	// State State_1
	static Transition State_1Handler(ImplPtr impl, Event event);
	static const State kState_1;
	
	// State StateWithSameName
	static Transition State_1StateWithSameNameHandler(ImplPtr impl, Event event);
	static const State kState_1StateWithSameName;
	
	// State State_2
	static Transition State_1State_2Handler(ImplPtr impl, Event event);
	static const State kState_1State_2;
	
	// State State_4
	static Transition State_1State_4Handler(ImplPtr impl, Event event);
	static const HistoryState kState_1State_4;
	
	// State StateWithSameName
	static Transition State_1State_4StateWithSameNameHandler(ImplPtr impl, Event event);
	static const State kState_1State_4StateWithSameName;
	
	// State State_5
	static Transition State_1State_4State_5Handler(ImplPtr impl, Event event);
	static const State kState_1State_4State_5;
};