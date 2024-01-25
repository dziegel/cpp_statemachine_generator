// Statemachine XmiTest declaration

#pragma once

class XmiTest final : public XmiTestBase
{
	public:
	static const StatePtr kInitialState;
	
	// State State_1
	static const State kState_1;
	
	// State StateWithSameName
	static const State kState_1StateWithSameName;
	
	// State State_2
	static const State kState_1State_2;
	
	// State State_4
	static const HistoryState kState_1State_4;
	
	// State StateWithSameName
	static const State kState_1State_4StateWithSameName;
	
	// State State_5
	static const State kState_1State_4State_5;
};