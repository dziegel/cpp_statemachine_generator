#pragma once

#include "ScXmlFsm.hxx"

class ScXmlFsmImpl : private IScXmlTestImpl
{
public:
    ScXmlFsmImpl();

    void Test();

private:
    ScXmlTest fsm_;

    void entry() override;
    void exit() override;
    void action(ScXmlTestBase::Event event) override;
    void action2(ScXmlTestBase::Event event) override;
    bool guard(ScXmlTestBase::Event event) override;
    void internalaction(ScXmlTestBase::Event event) override;
};