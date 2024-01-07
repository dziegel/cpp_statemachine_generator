#include <iostream>
#include <source_location>

#include "ScXmlFsmImpl.hxx"
#include "generated/StatemachineTestDeclaration.hxx"

ScXmlFsmImpl::ScXmlFsmImpl()
{
    fsm_.on_handle_event_ =
        [](StatemachineTest::Ref fsm, StatemachineTest::StateRef state, StatemachineTest::Event event)
    { std::cout << fsm.Name() << " State " << state.Name() << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](StatemachineTest::Ref fsm, StatemachineTest::StateRef state)
    { std::cout << fsm.Name() << " Enter state" << state.Name() << '\n'; };
    fsm_.on_state_exit_ = [](StatemachineTest::Ref fsm, StatemachineTest::StateRef state)
    { std::cout << fsm.Name() << " Exit state" << state.Name() << '\n'; };
    fsm_.on_unhandled_event_ =
        [](StatemachineTest::Ref fsm, StatemachineTest::StateRef state, StatemachineTest::Event event)
    { std::cout << fsm.Name() << " Unhandled event " << event << " in state " << state.Name() << '\n'; };

    fsm_.Init(this, "ScXml", StatemachineTest::kInitialState);
}

void ScXmlFsmImpl::Test()
{
    assert(fsm_.CurrentState() == nullptr);
    fsm_.Start();

    assert(fsm_.CurrentState() == &StatemachineTest::kState_2);
    fsm_.React(EScXmlEvent::Internal);
    assert(fsm_.CurrentState() == &StatemachineTest::kState_2);
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &StatemachineTest::kState_3);
    fsm_.React(EScXmlEvent::Transition_7);
    assert(fsm_.CurrentState() == &StatemachineTest::kState_4);
    fsm_.React(EScXmlEvent::Transition_8);
    assert(fsm_.CurrentState() == &StatemachineTest::kState_2);
}

void ScXmlFsmImpl::entry()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::exit()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::action(StatemachineTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::action2(StatemachineTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::internalaction(StatemachineTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
bool ScXmlFsmImpl::guard(StatemachineTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return true;
}
