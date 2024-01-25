// Statemachine XmiTest instance

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const XmiTest::StatePtr XmiTest::kInitialState = &XmiTest::kState_1;

// State State_1
const XmiTest::State XmiTest::kState_1("State_1", &State_1Handler, nullptr, &kState_1State_2, &Impl::State1OnEntry, nullptr);
XmiTest::Transition XmiTest::State_1Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State StateWithSameName
const XmiTest::State XmiTest::kState_1StateWithSameName("State_1::StateWithSameName", &State_1StateWithSameNameHandler, &kState_1, nullptr, &Impl::State3OnEntry, &Impl::State3OnExit);
XmiTest::Transition XmiTest::State_1StateWithSameNameHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		if (true)
		{
			return TransitionTo(kState_1State_4);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State State_2
const XmiTest::State XmiTest::kState_1State_2("State_1::State_2", &State_1State_2Handler, &kState_1, nullptr, &Impl::State2OnEntry, nullptr);
XmiTest::Transition XmiTest::State_1State_2Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Internal):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::State2InternalAction};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::Transition3Action1};
			return TransitionTo(kState_1StateWithSameName, kActions);
		}
		return UnhandledEvent();
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_6):
		if (true)
		{
			return TransitionTo(kState_1State_4);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State State_4
const XmiTest::HistoryState XmiTest::kState_1State_4("State_1::State_4", &State_1State_4Handler, &kState_1, &kState_1State_4State_5, &Impl::State4OnEntry, &Impl::State4OnExit);
XmiTest::Transition XmiTest::State_1State_4Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_8):
		if (true)
		{
			return TransitionTo(kState_1State_2);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State StateWithSameName
const XmiTest::State XmiTest::kState_1State_4StateWithSameName("State_1::State_4::StateWithSameName", &State_1State_4StateWithSameNameHandler, &kState_1State_4, nullptr, nullptr, nullptr);
XmiTest::Transition XmiTest::State_1State_4StateWithSameNameHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_4):
		if (true)
		{
			return TransitionTo(kState_1State_4State_5);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State State_5
const XmiTest::State XmiTest::kState_1State_4State_5("State_1::State_4::State_5", &State_1State_4State_5Handler, &kState_1State_4, nullptr, nullptr, nullptr);
XmiTest::Transition XmiTest::State_1State_4State_5Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (true)
		{
			return TransitionTo(kState_1State_4StateWithSameName);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}