// Statemachine XmiTest implementation interface
// Generated: 5/7/25, 9:04 PM

#pragma once

class IXmiTestImpl
{
	public:
	virtual ~IXmiTestImpl() = default;
	
	// Actions, Entry/Exit
	virtual void ChoiceAction1(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction2(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction3(XmiTestBase::Event event) = 0;
	virtual void ChoiceAction4(XmiTestBase::Event event) = 0;
	virtual void CommaAction2(XmiTestBase::Event event) = 0;
	virtual void State1OnEntry(XmiTestBase::Event event) = 0;
	virtual void State1OnExit(XmiTestBase::Event event) = 0;
	virtual void State2InternalAction(XmiTestBase::Event event) = 0;
	virtual void State2OnEntry(XmiTestBase::Event event) = 0;
	virtual void State3OnEntry(XmiTestBase::Event event) = 0;
	virtual void State3OnExit(XmiTestBase::Event event) = 0;
	virtual void State4OnEntry1(XmiTestBase::Event event) = 0;
	virtual void State4OnEntry2(XmiTestBase::Event event) = 0;
	virtual void State4OnExit1(XmiTestBase::Event event) = 0;
	virtual void State4OnExit2(XmiTestBase::Event event) = 0;
	virtual void Transition3Action1(XmiTestBase::Event event) = 0;
	
	// Guards
	virtual bool ChoiceGuard1(XmiTestBase::Event event) = 0;
	virtual bool ChoiceGuard2(XmiTestBase::Event event) = 0;
	virtual bool ChoiceGuard3(XmiTestBase::Event event) = 0;
	virtual bool CommaGuard(XmiTestBase::Event event) = 0;
	virtual bool State2Transition3Guard(XmiTestBase::Event event) = 0;
};