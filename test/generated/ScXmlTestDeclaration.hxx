// Statemachine ScXmlTest declaration

#pragma once

class ScXmlTest final : public ScXmlTestBase
{
	public:
	static const StatePtr kInitialState;
	
	// State State_1
	static const State kState_1;
	
	// State State_2
	static const State kState_1State_2;
	
	// State State_3
	static const State kState_1State_3;
	
	// State State_4
	static const HistoryState kState_1State_4;
	
	// State State_5
	static const State kState_1State_4State_5;
	
	// State State_6
	static const State kState_1State_4State_6;
};