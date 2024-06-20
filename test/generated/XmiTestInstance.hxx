// Statemachine XmiTest instance
// Generated: 20.06.24, 10:59

#pragma once

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
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::State XmiTest::kState_1("State_1", &State_1Handler, nullptr, &XmiTest::kState_1State_2, &XmiTest::Impl::State1OnEntry, nullptr);

// State State_1::StateWithSameName
static XmiTest::Transition State_1StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		if (true)
		{
			return XmiTest::TransitionTo(XmiTest::kState_1State_4);
		}
		return XmiTest::UnhandledEvent();
		
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::State XmiTest::kState_1StateWithSameName("State_1::StateWithSameName", &State_1StateWithSameNameHandler, &XmiTest::kState_1, nullptr, &XmiTest::Impl::State3OnEntry, &XmiTest::Impl::State3OnExit);

// State State_1::State_2
static XmiTest::Transition State_1State_2Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Internal):
		if (true)
		{
			static const auto kActions = std::to_array<XmiTest::Transition::ActionType>({&XmiTest::Impl::State2InternalAction});
			return XmiTest::TransitionTo(XmiTest::kNone, kActions);
		}
		return XmiTest::UnhandledEvent();
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			static const auto kActions = std::to_array<XmiTest::Transition::ActionType>({&XmiTest::Impl::Transition3Action1});
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName, kActions);
		}
		return XmiTest::UnhandledEvent();
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_6):
		if (true)
		{
			return XmiTest::TransitionTo(XmiTest::kState_1State_4);
		}
		return XmiTest::UnhandledEvent();
		
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::State XmiTest::kState_1State_2("State_1::State_2", &State_1State_2Handler, &XmiTest::kState_1, nullptr, &XmiTest::Impl::State2OnEntry, nullptr);

// State State_1::State_4
static XmiTest::Transition State_1State_4Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_8):
		if (true)
		{
			return XmiTest::TransitionTo(XmiTest::kState_1State_2);
		}
		return XmiTest::UnhandledEvent();
		
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::HistoryState XmiTest::kState_1State_4("State_1::State_4", &State_1State_4Handler, &XmiTest::kState_1, &XmiTest::kState_1State_4State_5, &XmiTest::Impl::State4OnEntry, &XmiTest::Impl::State4OnExit);

// State State_1::State_4::StateWithSameName
static XmiTest::Transition State_1State_4StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_4):
		if (true)
		{
			return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5);
		}
		return XmiTest::UnhandledEvent();
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		if (impl->ChoiceGuard1(event) && impl->ChoiceGuard2(event))
		{
			static const auto kActions = std::to_array<XmiTest::Transition::ActionType>({&XmiTest::Impl::ChoiceAction1, &XmiTest::Impl::ChoiceAction2});
			return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5, kActions);
		}
		if (impl->ChoiceGuard1(event))
		{
			static const auto kActions = std::to_array<XmiTest::Transition::ActionType>({&XmiTest::Impl::ChoiceAction1, &XmiTest::Impl::ChoiceAction3});
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName, kActions);
		}
		return XmiTest::UnhandledEvent();
		
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::State XmiTest::kState_1State_4StateWithSameName("State_1::State_4::StateWithSameName", &State_1State_4StateWithSameNameHandler, &XmiTest::kState_1State_4, nullptr, nullptr, nullptr);

// State State_1::State_4::State_5
static XmiTest::Transition State_1State_4State_5Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (true)
		{
			return XmiTest::TransitionTo(XmiTest::kState_1State_4StateWithSameName);
		}
		return XmiTest::UnhandledEvent();
		
		default:
		return XmiTest::UnhandledEvent();
	}
}
const XmiTest::State XmiTest::kState_1State_4State_5("State_1::State_4::State_5", &State_1State_4State_5Handler, &XmiTest::kState_1State_4, nullptr, nullptr, nullptr);