#include <iostream>
#include <source_location>

#include "ScXmlFsmImpl.hxx"
#include "generated/StatemachineTestDeclaration.hxx"

ScXmlFsmImpl::ScXmlFsmImpl()
{
    fsm_.Init(this, "Scxml", StatemachineTest::kInitialState);
    fsm_.Start();
}

void ScXmlFsmImpl::Test()
{
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
void ScXmlFsmImpl::action(StatemachineTestBase::Event)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::action2(StatemachineTestBase::Event)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void ScXmlFsmImpl::internalaction(StatemachineTestBase::Event)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
bool ScXmlFsmImpl::guard(StatemachineTestBase::Event)
{
    std::cout << std::source_location::current().function_name() << "\n";
    return true;
}
