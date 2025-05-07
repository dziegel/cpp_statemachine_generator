// Statemachine XmiTest instance
// Generated: 5/7/25, 9:04 PM

#pragma once

#include <array>

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef XmiTest_GET_INSTANCE_EVENT_ID
#define XmiTest_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef XmiTest_GET_STATIC_EVENT_ID
#define XmiTest_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif


// State State_1
static XmiTest::Transition State_1Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(SelfTransition):
		return XmiTest::TransitionTo(XmiTest::kState_1);
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
static const auto XmiTest_State_1_entry = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State1OnEntry});
static const auto XmiTest_State_1_exit = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State1OnExit});
const XmiTest::State XmiTest::kState_1("State_1", &State_1Handler, nullptr, &XmiTest::kState_1State_2, XmiTest_State_1_entry, XmiTest_State_1_exit);

// State State_1::StateWithSameName
static XmiTest::Transition State_1StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		return XmiTest::TransitionTo(XmiTest::kState_1State_4);
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
static const auto XmiTest_StateWithSameName_entry = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State3OnEntry});
static const auto XmiTest_StateWithSameName_exit = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State3OnExit});
const XmiTest::State XmiTest::kState_1StateWithSameName("State_1::StateWithSameName", &State_1StateWithSameNameHandler, &XmiTest::kState_1, nullptr, XmiTest_StateWithSameName_entry, XmiTest_StateWithSameName_exit);

// State State_1::State_2
static XmiTest::Transition State_1State_2Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Internal):
		static const auto kActions1 = std::to_array<XmiTest::ActionType>({&XmiTest::Impl::State2InternalAction});
		return XmiTest::NoTransition(kActions1);
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			static const auto kActions2 = std::to_array<XmiTest::ActionType>({&XmiTest::Impl::Transition3Action1});
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName, kActions2);
		}
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_6):
		return XmiTest::TransitionTo(XmiTest::kState_1State_4);
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
static const auto XmiTest_State_2_entry = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State2OnEntry});
const XmiTest::State XmiTest::kState_1State_2("State_1::State_2", &State_1State_2Handler, &XmiTest::kState_1, nullptr, XmiTest_State_2_entry, {});

// State State_1::State_4
static XmiTest::Transition State_1State_4Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(SelfTransition):
		return XmiTest::TransitionTo(XmiTest::kState_1State_4);
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_8):
		return XmiTest::TransitionTo(XmiTest::kState_1State_2);
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
static const auto XmiTest_State_4_entry = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State4OnEntry1, &XmiTest::Impl::State4OnEntry2});
static const auto XmiTest_State_4_exit = std::to_array<XmiTest::State::EntryExitType>({&XmiTest::Impl::State4OnExit1, &XmiTest::Impl::State4OnExit2});
const XmiTest::HistoryState XmiTest::kState_1State_4("State_1::State_4", &State_1State_4Handler, &XmiTest::kState_1, &XmiTest::kState_1State_4State_5, XmiTest_State_4_entry, XmiTest_State_4_exit);

// State State_1::State_4::StateWithSameName
static XmiTest::Transition State_1State_4StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_4):
		return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5);
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		if (impl->ChoiceGuard1(event) && impl->CommaGuard(event))
		{
			if (impl->ChoiceGuard2(event))
			{
				static const auto kActions1 = std::to_array<XmiTest::ActionType>({&XmiTest::Impl::ChoiceAction1, &XmiTest::Impl::CommaAction2, &XmiTest::Impl::ChoiceAction2});
				return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5, kActions1);
			}
			if (impl->ChoiceGuard3(event))
			{
				static const auto kActions2 = std::to_array<XmiTest::ActionType>({&XmiTest::Impl::ChoiceAction1, &XmiTest::Impl::CommaAction2, &XmiTest::Impl::ChoiceAction3, &XmiTest::Impl::ChoiceAction4});
				return XmiTest::TransitionTo(XmiTest::kState_1State_2, kActions2);
			}
			static const auto kActions3 = std::to_array<XmiTest::ActionType>({&XmiTest::Impl::ChoiceAction1, &XmiTest::Impl::CommaAction2, &XmiTest::Impl::ChoiceAction3});
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName, kActions3);
		}
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
const XmiTest::State XmiTest::kState_1State_4StateWithSameName("State_1::State_4::StateWithSameName", &State_1State_4StateWithSameNameHandler, &XmiTest::kState_1State_4, nullptr, {}, {});

// State State_1::State_4::State_5
static XmiTest::Transition State_1State_4State_5Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		return XmiTest::TransitionTo(XmiTest::kState_1State_4StateWithSameName);
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
const XmiTest::State XmiTest::kState_1State_4State_5("State_1::State_4::State_5", &State_1State_4State_5Handler, &XmiTest::kState_1State_4, nullptr, {}, {});