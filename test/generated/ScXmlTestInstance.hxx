// Statemachine ScXmlTest instance
// Generated: 26.01.24, 17:51

#pragma once

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef ScXmlTest_GET_INSTANCE_EVENT_ID
#define ScXmlTest_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef ScXmlTest_GET_STATIC_EVENT_ID
#define ScXmlTest_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const ScXmlTest::StatePtr ScXmlTest::kInitialState = &ScXmlTest::kState_1;

// State State_1
static ScXmlTest::Transition State_1Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::State ScXmlTest::kState_1("State_1", &State_1Handler, nullptr, &ScXmlTest::kState_1State_2, &ScXmlTest::Impl::State1OnEntry, nullptr);

// State State_1::State_2
static ScXmlTest::Transition State_1State_2Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Internal):
		if (true)
		{
			static const auto kActions = std::to_array<ScXmlTest::Transition::ActionType>({&ScXmlTest::Impl::State2InternalAction});
			return ScXmlTest::TransitionTo(ScXmlTest::kNone, kActions);
		}
		return ScXmlTest::UnhandledEvent();
		
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			static const auto kActions = std::to_array<ScXmlTest::Transition::ActionType>({&ScXmlTest::Impl::Transition3Action1, &ScXmlTest::Impl::Transition3Action2});
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_3, kActions);
		}
		return ScXmlTest::UnhandledEvent();
		
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_6):
		if (true)
		{
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_4);
		}
		return ScXmlTest::UnhandledEvent();
		
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::State ScXmlTest::kState_1State_2("State_1::State_2", &State_1State_2Handler, &ScXmlTest::kState_1, nullptr, &ScXmlTest::Impl::State2OnEntry, nullptr);

// State State_1::State_3
static ScXmlTest::Transition State_1State_3Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_7):
		if (true)
		{
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_4);
		}
		return ScXmlTest::UnhandledEvent();
		
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::State ScXmlTest::kState_1State_3("State_1::State_3", &State_1State_3Handler, &ScXmlTest::kState_1, nullptr, &ScXmlTest::Impl::State3OnEntry, &ScXmlTest::Impl::State3OnExit);

// State State_1::State_4
static ScXmlTest::Transition State_1State_4Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_8):
		if (true)
		{
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_2);
		}
		return ScXmlTest::UnhandledEvent();
		
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::HistoryState ScXmlTest::kState_1State_4("State_1::State_4", &State_1State_4Handler, &ScXmlTest::kState_1, &ScXmlTest::kState_1State_4State_5, &ScXmlTest::Impl::State4OnEntry, &ScXmlTest::Impl::State4OnExit);

// State State_1::State_4::State_5
static ScXmlTest::Transition State_1State_4State_5Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_3):
		if (true)
		{
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_4State_6);
		}
		return ScXmlTest::UnhandledEvent();
		
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::State ScXmlTest::kState_1State_4State_5("State_1::State_4::State_5", &State_1State_4State_5Handler, &ScXmlTest::kState_1State_4, nullptr, nullptr, nullptr);

// State State_1::State_4::State_6
static ScXmlTest::Transition State_1State_4State_6Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_4):
		if (true)
		{
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1State_4State_5);
		}
		return ScXmlTest::UnhandledEvent();
		
		default:
		return ScXmlTest::UnhandledEvent();
	}
}
const ScXmlTest::State ScXmlTest::kState_1State_4State_6("State_1::State_4::State_6", &State_1State_4State_6Handler, &ScXmlTest::kState_1State_4, nullptr, nullptr, nullptr);