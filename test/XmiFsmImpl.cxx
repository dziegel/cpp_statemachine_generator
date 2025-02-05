#include <cstddef>
#include <iostream>
#include <source_location>

#include "XmiFsm.hxx"
#include "XmiFsmImpl.hxx"

constexpr size_t kPoolSize = 10;

XmiFsmImpl::XmiFsmImpl()
    : pool_(cpp_event_framework::Pool<>::MakeShared(PoolSizeCalculator::kSptrSize, kPoolSize, "EventPool"))
{
    EventPoolAllocator::SetAllocator(pool_);

    fsm_.on_handle_event_ = [](XmiTest::Ref fsm, XmiTest::StateRef state, XmiTest::Event event)
    { std::cout << fsm << " State " << state << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](XmiTest::Ref fsm, XmiTest::StateRef state)
    { std::cout << fsm << " Enter " << state << '\n'; };
    fsm_.on_state_exit_ = [](XmiTest::Ref fsm, XmiTest::StateRef state)
    { std::cout << fsm << " Exit " << state << '\n'; };
    fsm_.on_unhandled_event_ = [](XmiTest::Ref fsm, XmiTest::StateRef state, XmiTest::Event event)
    {
        std::cout << fsm << " Unhandled event " << event << " in state " << state << '\n';
        fsm.Implementation()->UnhandledEvent();
    };

    fsm_.Init(this, "Xmi");
}

void XmiFsmImpl::Test()
{
    assert(pool_->FillLevel() == kPoolSize);

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
    fsm_.React(Transition_3::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Internal transition, action must be called.
    fsm_.React(Internal::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(state2_internal_action_called_);
    state2_internal_action_called_ = false;
    CheckAllFalse();

    // Guard returns false, no state change, no entry/exit
    state2_transition3_guard_result_ = false;
    fsm_.React(Transition_3::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Guard returns true, state change, entry/exit called
    state2_transition3_guard_result_ = true;
    fsm_.React(Transition_3::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1StateWithSameName);
    assert(transition3_action1_called_);
    transition3_action1_called_ = false;
    assert(state3_on_entry_called_);
    state3_on_entry_called_ = false;
    CheckAllFalse();

    // Enter history compartment
    fsm_.React(Transition_7::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4State_5);
    assert(state3_on_exit_called_);
    state3_on_exit_called_ = false;
    assert(state4_on_entry1_called_);
    state4_on_entry1_called_ = false;
    assert(state4_on_entry2_called_);
    state4_on_entry2_called_ = false;
    CheckAllFalse();

    // Transition in history compartment
    fsm_.React(Transition_3::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    CheckAllFalse();

    // Step out of history compartment
    fsm_.React(Transition_8::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(state4_on_exit1_called_);
    state4_on_exit1_called_ = false;
    assert(state4_on_exit2_called_);
    state4_on_exit2_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    CheckAllFalse();

    // Reenter history compartment, history must be preserved
    fsm_.React(Transition_6::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    assert(state4_on_entry1_called_);
    state4_on_entry1_called_ = false;
    assert(state4_on_entry2_called_);
    state4_on_entry2_called_ = false;
    CheckAllFalse();

    // Choice: No guards return true
    fsm_.React(Transition_7::MakeShared());
    assert(on_unhandled_event_called_);
    on_unhandled_event_called_ = false;
    CheckAllFalse();

    // Choice: One guard return true
    choice_guard1_result_ = true;
    choice_guard2_result_ = false;
    choice_guard3_result_ = false;
    fsm_.React(Transition_7::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1StateWithSameName);
    assert(choice_action1_called_);
    choice_action1_called_ = false;
    assert(choice_action3_called_);
    choice_action3_called_ = false;
    assert(state3_on_entry_called_);
    state3_on_entry_called_ = false;
    assert(state4_on_exit1_called_);
    state4_on_exit1_called_ = false;
    assert(state4_on_exit2_called_);
    state4_on_exit2_called_ = false;
    assert(comma_action_called_);
    comma_action_called_ = false;
    CheckAllFalse();

    // Return to State_1::State_4::StateWithSameName
    fsm_.React(Transition_7::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    assert(state3_on_exit_called_);
    state3_on_exit_called_ = false;
    assert(state4_on_entry1_called_);
    state4_on_entry1_called_ = false;
    assert(state4_on_entry2_called_);
    state4_on_entry2_called_ = false;
    CheckAllFalse();

    // Choice: Two guards return true
    choice_guard1_result_ = true;
    choice_guard2_result_ = true;
    choice_guard3_result_ = false;
    fsm_.React(Transition_7::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4State_5);
    assert(choice_action1_called_);
    choice_action1_called_ = false;
    assert(choice_action2_called_);
    choice_action2_called_ = false;
    assert(comma_action_called_);
    comma_action_called_ = false;
    CheckAllFalse();

    // Return to State_1::State_4::StateWithSameName
    fsm_.React(Transition_3::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_4StateWithSameName);
    CheckAllFalse();

    // Choice: Two guards return true, part 2
    choice_guard1_result_ = true;
    choice_guard2_result_ = false;
    choice_guard3_result_ = true;
    fsm_.React(Transition_7::MakeShared());
    assert(fsm_.CurrentState() == &XmiTest::kState_1State_2);
    assert(choice_action1_called_);
    choice_action1_called_ = false;
    assert(choice_action3_called_);
    choice_action3_called_ = false;
    assert(choice_action4_called_);
    choice_action4_called_ = false;
    assert(state2_on_entry_called_);
    state2_on_entry_called_ = false;
    assert(state4_on_exit1_called_);
    state4_on_exit1_called_ = false;
    assert(state4_on_exit2_called_);
    state4_on_exit2_called_ = false;
    assert(comma_action_called_);
    comma_action_called_ = false;
    CheckAllFalse();

    assert(pool_->FillLevel() == kPoolSize);
}

void XmiFsmImpl::CheckAllFalse() const
{
    assert(on_unhandled_event_called_ == false);

    assert(choice_action1_called_ == false);
    assert(choice_action2_called_ == false);
    assert(choice_action3_called_ == false);
    assert(choice_action4_called_ == false);
    assert(state2_internal_action_called_ == false);
    assert(transition3_action1_called_ == false);
    assert(comma_action_called_ == false);

    assert(state1_on_entry_called_ == false);
    assert(state2_on_entry_called_ == false);
    assert(state3_on_entry_called_ == false);
    assert(state3_on_exit_called_ == false);
    assert(state4_on_entry1_called_ == false);
    assert(state4_on_entry2_called_ == false);
    assert(state4_on_exit1_called_ == false);
    assert(state4_on_exit2_called_ == false);
}

void XmiFsmImpl::UnhandledEvent()
{
    std::cout << std::source_location::current().function_name() << "\n";
    on_unhandled_event_called_ = true;
}

void XmiFsmImpl::ChoiceAction1(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    choice_action1_called_ = true;
}
void XmiFsmImpl::ChoiceAction2(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    choice_action2_called_ = true;
}
void XmiFsmImpl::ChoiceAction3(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    choice_action3_called_ = true;
}
void XmiFsmImpl::ChoiceAction4(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    choice_action4_called_ = true;
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
void XmiFsmImpl::CommaAction2(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    comma_action_called_ = true;
}

bool XmiFsmImpl::ChoiceGuard1(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return choice_guard1_result_;
}
bool XmiFsmImpl::ChoiceGuard2(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return choice_guard2_result_;
}
bool XmiFsmImpl::ChoiceGuard3(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return choice_guard3_result_;
}
bool XmiFsmImpl::State2Transition3Guard(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return state2_transition3_guard_result_;
}
bool XmiFsmImpl::CommaGuard(XmiTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return true;
}

void XmiFsmImpl::State1OnEntry()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state1_on_entry_called_ = true;
}
void XmiFsmImpl::State1OnExit()
{
    std::cout << std::source_location::current().function_name() << "\n";
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
void XmiFsmImpl::State4OnEntry1()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_entry1_called_ = true;
}
void XmiFsmImpl::State4OnEntry2()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_entry2_called_ = true;
}
void XmiFsmImpl::State4OnExit1()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_exit1_called_ = true;
}
void XmiFsmImpl::State4OnExit2()
{
    std::cout << std::source_location::current().function_name() << "\n";
    state4_on_exit2_called_ = true;
}
