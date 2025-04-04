// Statemachine XmiTest implementation interface
// Generated: 05.02.25, 22:34

#pragma once

class IXmiTestImpl
{
	public:
	virtual ~IXmiTestImpl() = default;
	
	// Actions
	virtual void ChoiceAction1(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction2(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction3(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction4(XmiTestBase::Event event) = 0;
	virtual void CommaAction2(XmiTestBase::Event event) = 0;
	virtual void State2InternalAction(XmiTestBase::Event event) = 0;
	virtual void Transition3Action1(XmiTestBase::Event event) = 0;
	
	// Guards
	virtual bool ChoiceGuard1(XmiTestBase::Event event) = 0;
	virtual bool ChoiceGuard2(XmiTestBase::Event event) = 0;
	virtual bool ChoiceGuard3(XmiTestBase::Event event) = 0;
	virtual bool CommaGuard(XmiTestBase::Event event) = 0;
	virtual bool State2Transition3Guard(XmiTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void State1OnEntry() = 0;
	virtual void State1OnExit() = 0;
	virtual void State2OnEntry() = 0;
	virtual void State3OnEntry() = 0;
	virtual void State3OnExit() = 0;
	virtual void State4OnEntry1() = 0;
	virtual void State4OnEntry2() = 0;
	virtual void State4OnExit1() = 0;
	virtual void State4OnExit2() = 0;
};