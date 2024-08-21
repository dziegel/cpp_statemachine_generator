// Statemachine XmiTest instance
// Generated: 21.08.24, 08:12

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
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
const XmiTest::State XmiTest::kState_1("State_1", &State_1Handler, nullptr, &XmiTest::kState_1State_2, &XmiTest::Impl::State1OnEntry, nullptr);

// State State_1::StateWithSameName
static XmiTest::Transition State_1StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
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
const XmiTest::State XmiTest::kState_1StateWithSameName("State_1::StateWithSameName", &State_1StateWithSameNameHandler, &XmiTest::kState_1, nullptr, &XmiTest::Impl::State3OnEntry, &XmiTest::Impl::State3OnExit);

// State State_1::State_2
static XmiTest::Transition State_1State_2Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Internal):
		impl->State2InternalAction(event);
		return XmiTest::NoTransition();
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_3):
		if (impl->State2Transition3Guard(event))
		{
			impl->Transition3Action1(event);
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName);        
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
const XmiTest::State XmiTest::kState_1State_2("State_1::State_2", &State_1State_2Handler, &XmiTest::kState_1, nullptr, &XmiTest::Impl::State2OnEntry, nullptr);

// State State_1::State_4
static XmiTest::Transition State_1State_4Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_8):
		
		return XmiTest::TransitionTo(XmiTest::kState_1State_2);        
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
const XmiTest::HistoryState XmiTest::kState_1State_4("State_1::State_4", &State_1State_4Handler, &XmiTest::kState_1, &XmiTest::kState_1State_4State_5, &XmiTest::Impl::State4OnEntry, &XmiTest::Impl::State4OnExit);

// State State_1::State_4::StateWithSameName
static XmiTest::Transition State_1State_4StateWithSameNameHandler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
	switch(XmiTest_GET_INSTANCE_EVENT_ID(event))
	{
		case XmiTest_GET_STATIC_EVENT_ID(Transition_4):
		
		return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5);        
		break;
		
		case XmiTest_GET_STATIC_EVENT_ID(Transition_7):
		if (impl->ChoiceGuard1(event))
		{
			impl->ChoiceAction1(event);
			if (impl->ChoiceGuard2(event))
			{
				impl->ChoiceAction2(event);
				return XmiTest::TransitionTo(XmiTest::kState_1State_4State_5);        
			}
			impl->ChoiceAction3(event);
			return XmiTest::TransitionTo(XmiTest::kState_1StateWithSameName);        
		}
		break;
		
		default:
		break;
	}
	return XmiTest::UnhandledEvent();
}
const XmiTest::State XmiTest::kState_1State_4StateWithSameName("State_1::State_4::StateWithSameName", &State_1State_4StateWithSameNameHandler, &XmiTest::kState_1State_4, nullptr, nullptr, nullptr);

// State State_1::State_4::State_5
static XmiTest::Transition State_1State_4State_5Handler(XmiTest::ImplPtr impl, XmiTest::Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function or action being called in here
	
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
const XmiTest::State XmiTest::kState_1State_4State_5("State_1::State_4::State_5", &State_1State_4State_5Handler, &XmiTest::kState_1State_4, nullptr, nullptr, nullptr);