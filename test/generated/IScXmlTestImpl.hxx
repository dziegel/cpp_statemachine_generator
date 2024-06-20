// Statemachine ScXmlTest implementation interface
// Generated: 20.06.24, 10:59

#pragma once

class IScXmlTestImpl
{
	public:
	virtual ~IScXmlTestImpl() = default;
	
	// Actions
	virtual void State2InternalAction(ScXmlTestBase::Event event) = 0;
	virtual void Transition3Action1(ScXmlTestBase::Event event) = 0;
	virtual void Transition3Action2(ScXmlTestBase::Event event) = 0;
	
	// Guards
	virtual bool State2Transition3Guard(ScXmlTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void State1OnEntry() = 0;
	virtual void State2OnEntry() = 0;
	virtual void State3OnEntry() = 0;
	virtual void State3OnExit() = 0;
	virtual void State4OnEntry() = 0;
	virtual void State4OnExit() = 0;
};