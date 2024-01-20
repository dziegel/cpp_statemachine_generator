// Statemachine ScXmlTest instance

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const ScXmlTest::StatePtr ScXmlTest::kInitialState = &ScXmlTest::kState_1;

// State State_1
const ScXmlTest::State ScXmlTest::kState_1("State_1", &State_1Handler, nullptr, &kState_1State_2, nullptr, nullptr);
ScXmlTest::Transition ScXmlTest::State_1Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State State_2
const ScXmlTest::HistoryState ScXmlTest::kState_1State_2("State_2", &State_2Handler, &kState_1, nullptr, nullptr, nullptr);
ScXmlTest::Transition ScXmlTest::State_2Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Internal):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::internalaction};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->guard(event))
		{
			static const Transition::ActionContainer<2> kActions = {&Impl::action, &Impl::action2};
			return TransitionTo(kState_1State_3, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State State_3
const ScXmlTest::State ScXmlTest::kState_1State_3("State_3", &State_3Handler, &kState_1, nullptr, &Impl::entry, &Impl::exit);
ScXmlTest::Transition ScXmlTest::State_3Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_7):
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
const ScXmlTest::State ScXmlTest::kState_1State_4("State_4", &State_4Handler, &kState_1, nullptr, nullptr, nullptr);
ScXmlTest::Transition ScXmlTest::State_4Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_8):
		if (true)
		{
			return TransitionTo(kState_1State_2);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}