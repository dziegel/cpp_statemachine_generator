// Statemachine ScXmlTest declaration
// Generated: 20.06.24, 10:59

#pragma once

class ScXmlTest final : public ScXmlTestBase
{
	public:
	
	// State State_1
	static const State kState_1;
	
	// State State_1::State_2
	static const State kState_1State_2;
	
	// State State_1::State_3
	static const State kState_1State_3;
	
	// State State_1::State_4
	static const HistoryState kState_1State_4;
	
	// State State_1::State_4::State_5
	static const State kState_1State_4State_5;
	
	// State State_1::State_4::State_6
	static const State kState_1State_4State_6;
	
	void Start()
	{
		ScXmlTestBase::Start(&kState_1);
	}
};