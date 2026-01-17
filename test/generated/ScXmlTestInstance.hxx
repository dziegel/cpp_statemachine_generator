// Statemachine ScXmlTest instance
// Generated: 1/17/26, 9:22 PM

#pragma once

#include <array>

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef ScXmlTest_GET_INSTANCE_EVENT_ID
#define ScXmlTest_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef ScXmlTest_GET_STATIC_EVENT_ID
#define ScXmlTest_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif


// State State_1
static ScXmlTest::Transition State_1Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	(void) event; // No outgoing transitions
	return ScXmlTest::UnhandledEvent();
}
static const auto ScXmlTest_State_1_entry = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State1OnEntry});
const ScXmlTest::State ScXmlTest::kState_1("State_1", &State_1Handler, nullptr, &ScXmlTest::kState_1_State_2, ScXmlTest_State_1_entry, {});

// State State_1::State_2
static ScXmlTest::Transition State_1_State_2Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Internal):
		static const auto kActions1 = std::to_array<ScXmlTest::ActionType>({&ScXmlTest::Impl::State2InternalAction});
		return ScXmlTest::NoTransition(kActions1);
		break;
		
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			static const auto kActions2 = std::to_array<ScXmlTest::ActionType>({&ScXmlTest::Impl::Transition3Action1, &ScXmlTest::Impl::Transition3Action2});
			return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_3, kActions2);
		}
		break;
		
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_6):
		return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_4);
		break;
		
		default:
		break;
	}
	return ScXmlTest::UnhandledEvent();
}
static const auto ScXmlTest_State_1_State_2_entry = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State2OnEntry});
const ScXmlTest::State ScXmlTest::kState_1_State_2("State_1::State_2", &State_1_State_2Handler, &ScXmlTest::kState_1, nullptr, ScXmlTest_State_1_State_2_entry, {});

// State State_1::State_3
static ScXmlTest::Transition State_1_State_3Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_7):
		return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_4);
		break;
		
		default:
		break;
	}
	return ScXmlTest::UnhandledEvent();
}
static const auto ScXmlTest_State_1_State_3_entry = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State3OnEntry});
static const auto ScXmlTest_State_1_State_3_exit = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State3OnExit});
const ScXmlTest::State ScXmlTest::kState_1_State_3("State_1::State_3", &State_1_State_3Handler, &ScXmlTest::kState_1, nullptr, ScXmlTest_State_1_State_3_entry, ScXmlTest_State_1_State_3_exit);

// State State_1::State_4
static ScXmlTest::Transition State_1_State_4Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_8):
		return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_2);
		break;
		
		default:
		break;
	}
	return ScXmlTest::UnhandledEvent();
}
static const auto ScXmlTest_State_1_State_4_entry = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State4OnEntry});
static const auto ScXmlTest_State_1_State_4_exit = std::to_array<ScXmlTest::State::EntryExitType>({&ScXmlTest::Impl::State4OnExit});
const ScXmlTest::HistoryState ScXmlTest::kState_1_State_4("State_1::State_4", &State_1_State_4Handler, &ScXmlTest::kState_1, &ScXmlTest::kState_1_State_4_State_5, ScXmlTest_State_1_State_4_entry, ScXmlTest_State_1_State_4_exit);

// State State_1::State_4::State_5
static ScXmlTest::Transition State_1_State_4_State_5Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_3):
		return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_4_State_6);
		break;
		
		default:
		break;
	}
	return ScXmlTest::UnhandledEvent();
}
const ScXmlTest::State ScXmlTest::kState_1_State_4_State_5("State_1::State_4::State_5", &State_1_State_4_State_5Handler, &ScXmlTest::kState_1_State_4, nullptr, {}, {});

// State State_1::State_4::State_6
static ScXmlTest::Transition State_1_State_4_State_6Handler(ScXmlTest::ImplPtr impl, ScXmlTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(ScXmlTest_GET_INSTANCE_EVENT_ID(event))
	{
		case ScXmlTest_GET_STATIC_EVENT_ID(Transition_4):
		return ScXmlTest::TransitionTo(ScXmlTest::kState_1_State_4_State_5);
		break;
		
		default:
		break;
	}
	return ScXmlTest::UnhandledEvent();
}
const ScXmlTest::State ScXmlTest::kState_1_State_4_State_6("State_1::State_4::State_6", &State_1_State_4_State_6Handler, &ScXmlTest::kState_1_State_4, nullptr, {}, {});