// Statemachine XmiTest declaration
// Generated: 21.08.24, 21:03

#pragma once

class XmiTest final : public XmiTestBase
{
	public:
	
	// State State_1
	static const State kState_1;
	
	// State State_1::StateWithSameName
	static const State kState_1StateWithSameName;
	
	// State State_1::State_2
	static const State kState_1State_2;
	
	// State State_1::State_4
	static const HistoryState kState_1State_4;
	
	// State State_1::State_4::StateWithSameName
	static const State kState_1State_4StateWithSameName;
	
	// State State_1::State_4::State_5
	static const State kState_1State_4State_5;
	
	inline void Start()
	{
		XmiTestBase::Start(&kState_1);
	}
};