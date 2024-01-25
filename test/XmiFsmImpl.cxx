#include <iostream>
#include <source_location>

#include "XmiFsmImpl.hxx"

XmiFsmImpl::XmiFsmImpl()
{
    fsm_.on_handle_event_ = [](XmiTest::Ref fsm, XmiTest::StateRef state, XmiTest::Event event)
    { std::cout << fsm.Name() << " State " << state.Name() << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](XmiTest::Ref fsm, XmiTest::StateRef state)
    { std::cout << fsm.Name() << " Enter " << state.Name() << '\n'; };
    fsm_.on_state_exit_ = [](XmiTest::Ref fsm, XmiTest::StateRef state)
    { std::cout << fsm.Name() << " Exit " << state.Name() << '\n'; };
    fsm_.on_unhandled_event_ = [](XmiTest::Ref fsm, XmiTest::StateRef state, XmiTest::Event event)
    {
        std::cout << fsm.Name() << " Unhandled event " << event << " in state " << state.Name() << '\n';
        fsm.Implementation()->UnhandledEvent();
    };

    fsm_.Init(this, "Xmi", XmiTest::kInitialState);
}

void XmiFsmImpl::Test()
{
    // FSM not started
    CheckAllFalse();
    assert(fsm_.CurrentState() == nullptr);

    // Start FSM. Entry actions of initial states must be called.
    fsm_.Start();
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(state1_on_entry_called_);
    state1_on_entry_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    CheckAllFalse();

    // Send event that is not handled in state
    fsm_.React(EXmiEvent::Transition_3);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Internal transition, action must be called.
    fsm_.React(EXmiEvent::Internal);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(state2_internal_action_called_);
    state2_internal_action_called_ = false;
    CheckAllFalse();

    // Guard returns false, no state change, no entry/exit
    state2_transition3_guard_result_ = false;
    fsm_.React(EXmiEvent::Transition_3);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Guard returns true, state change, entry/exit called
    state2_transition3_guard_result_ = true;
    fsm_.React(EXmiEvent::Transition_3);
    assert(fsm_.CurrentState() == &XmiTest::kState_1StateWithSameName);
    assert(transition3_action1_called_);
    transition3_action1_called_ = false;
    assert(state3_on_entry_called_);
    state3_on_entry_called_ = false;
    CheckAllFalse();

    // Enter history compartment
    fsm_.React(EXmiEvent::Transition_7);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4State_5);
    assert(state3_on_exit_called_);
    state3_on_exit_called_ = false;
    assert(state4_on_entry_called_);
    state4_on_entry_called_ = false;
    CheckAllFalse();

    // Transition in history compartment
    fsm_.React(EXmiEvent::Transition_3);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    CheckAllFalse();

    // Step out of history compartment
    fsm_.React(EXmiEvent::Transition_8);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(state4_on_exit_called_);
    state4_on_exit_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    CheckAllFalse();

    // Reenter history compartment, history must be preserved
    fsm_.React(EXmiEvent::Transition_6);
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    assert(state4_on_entry_called_);
    state4_on_entry_called_ = false;
    CheckAllFalse();
}

void XmiFsmImpl::CheckAllFalse() const
{
    assert(on_unhandled_event_called_ == false);

    assert(state2_internal_action_called_ == false);
    assert(transition3_action1_called_ == false);

    assert(state1_on_entry_called_ == false);
    assert(state2_on_entry_called_ == false);
    assert(state3_on_entry_called_ == false);
    assert(state3_on_exit_called_ == false);
    assert(state4_on_entry_called_ == false);
    assert(state4_on_exit_called_ == false);
}

void XmiFsmImpl::UnhandledEvent()
{
    std::cout << std::source_location::current().function_name() << "\n";
    on_unhandled_event_called_ = true;
}

void XmiFsmImpl::State2InternalAction(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state2_internal_action_called_ = true;
}
void XmiFsmImpl::Transition3Action1(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    transition3_action1_called_ = true;
}

bool XmiFsmImpl::State2Transition3Guard(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return state2_transition3_guard_result_;
}

void XmiFsmImpl::State1OnEntry()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state1_on_entry_called_ = true;
}
void XmiFsmImpl::State2OnEntry()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state2_on_entry_called_ = true;
}
void XmiFsmImpl::State3OnEntry()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state3_on_entry_called_ = true;
}
void XmiFsmImpl::State3OnExit()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state3_on_exit_called_ = true;
}
void XmiFsmImpl::State4OnEntry()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_entry_called_ = true;
}
void XmiFsmImpl::State4OnExit()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_exit_called_ = true;
}
