// Statemachine ScXmlTest declaration
// Generated: 1/17/26, 9:22 PM

#pragma once

class ScXmlTest final : public ScXmlTestBase
{
	public:
	
	// State State_1
	static const State kState_1;
	
	// State State_1::State_2
	static const State kState_1_State_2;
	
	// State State_1::State_3
	static const State kState_1_State_3;
	
	// State State_1::State_4
	static const HistoryState kState_1_State_4;
	
	// State State_1::State_4::State_5
	static const State kState_1_State_4_State_5;
	
	// State State_1::State_4::State_6
	static const State kState_1_State_4_State_6;
	
	inline void Start()
	{
		ScXmlTestBase::Start(&kState_1);
	}
};