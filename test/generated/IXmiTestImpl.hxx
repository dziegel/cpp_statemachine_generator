class IXmiTestImpl
{
	public:
	// Actions
	virtual void State2InternalAction(XmiTestBase::Event event) = 0;
	virtual void Transition3Action1(XmiTestBase::Event event) = 0;
	
	// Guards
	virtual bool State2Transition3Guard(XmiTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void State1OnEntry() = 0;
	virtual void State2OnEntry() = 0;
	virtual void State3OnEntry() = 0;
	virtual void State3OnExit() = 0;
	virtual void State4OnEntry() = 0;
	virtual void State4OnExit() = 0;
};