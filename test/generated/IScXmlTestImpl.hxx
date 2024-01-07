class IScXmlTestImpl
{
	public:
	// Actions
	virtual void action(ScXmlTestBase::Event event) = 0;
	virtual void action2(ScXmlTestBase::Event event) = 0;
	virtual void internalaction(ScXmlTestBase::Event event) = 0;
	
	// Guards
	virtual bool guard(ScXmlTestBase::Event event) = 0;
	
	// Entry/Exit
	virtual void entry() = 0;
	virtual void exit() = 0;
};