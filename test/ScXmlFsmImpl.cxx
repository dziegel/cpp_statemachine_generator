#include <iostream>
#include <source_location>

#include "ScXmlFsmImpl.hxx"

ScXmlFsmImpl::ScXmlFsmImpl()
{
    fsm_.on_handle_event_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state, ScXmlTest::Event event)
    { std::cout << fsm << " State " << state << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state)
    { std::cout << fsm << " Enter " << state << '\n'; };
    fsm_.on_state_exit_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state)
    { std::cout << fsm << " Exit " << state << '\n'; };
    fsm_.on_unhandled_event_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state, ScXmlTest::Event event)
    {
        std::cout << fsm << " Unhandled event " << event << " in state " << state << '\n';
        fsm.Implementation()->UnhandledEvent();
    };

    fsm_.Init(this, "ScXml");
}

void ScXmlFsmImpl::Test()
{
    // FSM not started
    CheckAllFalse();
    assert(fsm_.CurrentState() == nullptr);

    // Start FSM. Entry actions of initial states must be called.
    fsm_.Start();
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    assert(state1_on_entry_called_);
    state1_on_entry_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    CheckAllFalse();

    // Send event that is not handled in state
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Internal transition, action must be called.
    fsm_.React(EScXmlEvent::Internal);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    assert(state2_internal_action_called_);
    state2_internal_action_called_ = false;
    CheckAllFalse();

    // Guard returns false, no state change, no entry/exit
    state2_transition3_guard_result_ = false;
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Guard returns true, state change, entry/exit called
    state2_transition3_guard_result_ = true;
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_3);
    assert(transition3_action1_called_);
    transition3_action1_called_ = false;
    assert(transition3_action2_called_);
    transition3_action2_called_ = false;
    assert(state3_on_entry_called_);
    state3_on_entry_called_ = false;
    CheckAllFalse();

    // Enter history compartment
    fsm_.React(EScXmlEvent::Transition_7);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_4State_5);
    assert(state3_on_exit_called_);
    state3_on_exit_called_ = false;
    assert(state4_on_entry_called_);
    state4_on_entry_called_ = false;
    CheckAllFalse();

    // Transition in history compartment
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_4State_6);
    CheckAllFalse();

    // Step out of history compartment
    fsm_.React(EScXmlEvent::Transition_8);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    assert(state4_on_exit_called_);
    state4_on_exit_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    CheckAllFalse();

    // Reenter history compartment, history must be preserved
    fsm_.React(EScXmlEvent::Transition_6);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_4State_6);
    assert(state4_on_entry_called_);
    state4_on_entry_called_ = false;
    CheckAllFalse();
}

void ScXmlFsmImpl::CheckAllFalse() const
{
    assert(on_unhandled_event_called_ == false);

    assert(state2_internal_action_called_ == false);
    assert(transition3_action1_called_ == false);
    assert(transition3_action2_called_ == false);

    assert(state1_on_entry_called_ == false);
    assert(state2_on_entry_called_ == false);
    assert(state3_on_entry_called_ == false);
    assert(state3_on_exit_called_ == false);
    assert(state4_on_entry_called_ == false);
    assert(state4_on_exit_called_ == false);
}

void ScXmlFsmImpl::UnhandledEvent()
{
    std::cout << std::source_location::current().function_name() << "\n";
    on_unhandled_event_called_ = true;
}

void ScXmlFsmImpl::State2InternalAction(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state2_internal_action_called_ = true;
}
void ScXmlFsmImpl::Transition3Action1(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    transition3_action1_called_ = true;
}
void ScXmlFsmImpl::Transition3Action2(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    transition3_action2_called_ = true;
}

bool ScXmlFsmImpl::State2Transition3Guard(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return state2_transition3_guard_result_;
}

void ScXmlFsmImpl::State1OnEntry(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state1_on_entry_called_ = true;
}
void ScXmlFsmImpl::State2OnEntry(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state2_on_entry_called_ = true;
}
void ScXmlFsmImpl::State3OnEntry(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state3_on_entry_called_ = true;
}
void ScXmlFsmImpl::State3OnExit(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state3_on_exit_called_ = true;
}
void ScXmlFsmImpl::State4OnEntry(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_entry_called_ = true;
}
void ScXmlFsmImpl::State4OnExit(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_exit_called_ = true;
}
