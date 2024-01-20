#include <iostream>
#include <source_location>

#include "ScXmlFsmImpl.hxx"

ScXmlFsmImpl::ScXmlFsmImpl()
{
    fsm_.on_handle_event_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state, ScXmlTest::Event event)
    { std::cout << fsm.Name() << " State " << state.Name() << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state)
    { std::cout << fsm.Name() << " Enter " << state.Name() << '\n'; };
    fsm_.on_state_exit_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state)
    { std::cout << fsm.Name() << " Exit " << state.Name() << '\n'; };
    fsm_.on_unhandled_event_ = [](ScXmlTest::Ref fsm, ScXmlTest::StateRef state, ScXmlTest::Event event)
    { std::cout << fsm.Name() << " Unhandled event " << event << " in state " << state.Name() << '\n'; };

    fsm_.Init(this, "ScXml", ScXmlTest::kInitialState);
}

void ScXmlFsmImpl::Test()
{
    assert(fsm_.CurrentState() == nullptr);
    fsm_.Start();

    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    fsm_.React(EScXmlEvent::Internal);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
    fsm_.React(EScXmlEvent::Transition_3);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_3);
    fsm_.React(EScXmlEvent::Transition_7);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_4);
    fsm_.React(EScXmlEvent::Transition_8);
    assert(fsm_.CurrentState() == &ScXmlTest::kState_1State_2);
}

void ScXmlFsmImpl::entry()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::exit()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::action(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::action2(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::internalaction(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
bool ScXmlFsmImpl::guard(ScXmlTestBase::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return true;
}
