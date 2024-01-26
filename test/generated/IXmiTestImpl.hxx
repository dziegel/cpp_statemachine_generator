// Statemachine XmiTest implementation interface
// Generated: 26.01.24, 17:52

#pragma once

class IXmiTestImpl
{
	public:
	// Actions
	virtual void ChoiceAction1(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction2(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction3(XmiTestBase::Event event) = 0;
	virtual void State2InternalAction(XmiTestBase::Event event) = 0;
	virtual void Transition3Action1(XmiTestBase::Event event) = 0;
	
	// Guards
	virtual bool ChoiceGuard1(XmiTestBase::Event event) = 0;
	virtual bool ChoiceGuard2(XmiTestBase::Event event) = 0;
	virtual bool State2Transition3Guard(XmiTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void State1OnEntry() = 0;
	virtual void State2OnEntry() = 0;
	virtual void State3OnEntry() = 0;
	virtual void State3OnExit() = 0;
	virtual void State4OnEntry() = 0;
	virtual void State4OnExit() = 0;
};