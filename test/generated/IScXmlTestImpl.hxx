// Statemachine ScXmlTest implementation interface
// Generated: 5/7/25, 9:13 PM

#pragma once

class IScXmlTestImpl
{
	public:
	virtual ~IScXmlTestImpl() = default;
	
	// Actions, Entry/Exit
	virtual void State1OnEntry(ScXmlTestBase::Event event) = 0;
	virtual void State2InternalAction(ScXmlTestBase::Event event) = 0;
	virtual void State2OnEntry(ScXmlTestBase::Event event) = 0;
	virtual void State3OnEntry(ScXmlTestBase::Event event) = 0;
	virtual void State3OnExit(ScXmlTestBase::Event event) = 0;
	virtual void State4OnEntry(ScXmlTestBase::Event event) = 0;
	virtual void State4OnExit(ScXmlTestBase::Event event) = 0;
	virtual void Transition3Action1(ScXmlTestBase::Event event) = 0;
	virtual void Transition3Action2(ScXmlTestBase::Event event) = 0;
	
	// Guards
	virtual bool State2Transition3Guard(ScXmlTestBase::Event event) = 0;
};