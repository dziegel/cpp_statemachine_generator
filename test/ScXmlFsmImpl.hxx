#pragma once

#include "ScXmlFsm.hxx"

class ScXmlFsmImpl final : private IScXmlFsmImpl
{
public:
    ScXmlFsmImpl();

    void Test();

private:
    ScXmlTest fsm_;

    bool on_unhandled_event_called_ = false;
    void UnhandledEvent() override;

    bool state2_internal_action_called_ = false;
    void State2InternalAction(ScXmlTestBase::Event event) override;
    bool transition3_action1_called_ = false;
    void Transition3Action1(ScXmlTestBase::Event event) override;
    bool transition3_action2_called_ = false;
    void Transition3Action2(ScXmlTestBase::Event event) override;

    bool state2_transition3_guard_result_ = false;
    bool State2Transition3Guard(ScXmlTestBase::Event event) override;

    bool state1_on_entry_called_ = false;
    void State1OnEntry() override;
    bool state2_on_entry_called_ = false;
    void State2OnEntry() override;
    bool state3_on_entry_called_ = false;
    void State3OnEntry() override;
    bool state3_on_exit_called_ = false;
    void State3OnExit() override;
    bool state4_on_entry_called_ = false;
    void State4OnEntry() override;
    bool state4_on_exit_called_ = false;
    void State4OnExit() override;

    void CheckAllFalse() const;
};