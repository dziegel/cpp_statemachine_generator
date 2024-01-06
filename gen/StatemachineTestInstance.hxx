// Statemachine StatemachineTest instance

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const StatemachineTest::StatePtr StatemachineTest::kInitialState = &StatemachineTest::kState_1;

// State State_1
const StatemachineTest::State StatemachineTest::kState_1("State_1", &State_1Handler, nullptr, &kState_2, nullptr, nullptr);
StatemachineTest::Transition StatemachineTest::State_1Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(StatemachineTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State State_2
const StatemachineTest::State StatemachineTest::kState_2("State_2", &State_2Handler, nullptr, nullptr, nullptr, nullptr);
StatemachineTest::Transition StatemachineTest::State_2Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(StatemachineTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State State_3
const StatemachineTest::State StatemachineTest::kState_3("State_3", &State_3Handler, nullptr, nullptr, &Impl::exit, nullptr);
StatemachineTest::Transition StatemachineTest::State_3Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(StatemachineTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State State_4
const StatemachineTest::State StatemachineTest::kState_4("State_4", &State_4Handler, nullptr, nullptr, nullptr, nullptr);
StatemachineTest::Transition StatemachineTest::State_4Handler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(StatemachineTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}