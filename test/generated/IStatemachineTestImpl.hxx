class IStatemachineTestImpl
{
	public:
	// Actions
	virtual void action(StatemachineTestBase::Event event) = 0;
	virtual void action2(StatemachineTestBase::Event event) = 0;
	
	// Guards
	virtual bool guard(StatemachineTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void entry() = 0;
	virtual void exit() = 0;
};