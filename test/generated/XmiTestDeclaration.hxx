// Statemachine XmiTest declaration
// Generated: 1/17/26, 9:21 PM

#pragma once

class XmiTest final : public XmiTestBase
{
	public:
	
	// State State_1
	static const State kState_1;
	
	// State State_1::StateWithSameName
	static const State kState_1_StateWithSameName;
	
	// State State_1::State_2
	static const State kState_1_State_2;
	
	// State State_1::State_4
	static const HistoryState kState_1_State_4;
	
	// State State_1::State_4::StateWithSameName
	static const State kState_1_State_4_StateWithSameName;
	
	// State State_1::State_4::State_5
	static const State kState_1_State_4_State_5;
	
	inline void Start()
	{
		XmiTestBase::Start(&kState_1);
	}
};