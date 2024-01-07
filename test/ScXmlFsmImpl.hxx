#pragma once

#include "ScXmlFsm.hxx"

class ScXmlFsmImpl : private IStatemachineTestImpl
{
public:
    ScXmlFsmImpl();

    void Test();

private:
    StatemachineTest fsm_;

    void entry() override;
    void exit() override;
    void action(StatemachineTestBase::Event event) override;
    void action2(StatemachineTestBase::Event event) override;
    bool guard(StatemachineTestBase::Event event) override;
    void internalaction(StatemachineTestBase::Event event) override;
};