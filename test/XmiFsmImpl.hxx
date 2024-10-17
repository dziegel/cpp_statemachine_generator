#pragma once

#include "XmiFsm.hxx"

class XmiFsmImpl final : private IXmiFsmImpl
{
public:
    XmiFsmImpl();

    void Test();

private:
    XmiTest fsm_;
    cpp_event_framework::Pool<>::SPtr pool_;

    bool on_unhandled_event_called_ = false;
    void UnhandledEvent() override;

    bool choice_action1_called_ = false;
    void ChoiceAction1(XmiTestBase::Event event) override;
    bool choice_action2_called_ = false;
    void ChoiceAction2(XmiTestBase::Event event) override;
    bool choice_action3_called_ = false;
    void ChoiceAction3(XmiTestBase::Event event) override;
    bool choice_action4_called_ = false;
    void ChoiceAction4(XmiTestBase::Event event) override;
    bool state2_internal_action_called_ = false;
    void State2InternalAction(XmiTestBase::Event event) override;
    bool transition3_action1_called_ = false;
    void Transition3Action1(XmiTestBase::Event event) override;
    bool comma_action_called_ = false;
    void CommaAction2(XmiTestBase::Event event) override;

    bool choice_guard1_result_ = false;
    bool ChoiceGuard1(XmiTestBase::Event event) override;
    bool choice_guard2_result_ = false;
    bool ChoiceGuard2(XmiTestBase::Event event) override;
    bool choice_guard3_result_ = false;
    bool ChoiceGuard3(XmiTestBase::Event event) override;
    bool CommaGuard(XmiTestBase::Event event) override;
    bool state2_transition3_guard_result_ = false;
    bool State2Transition3Guard(XmiTestBase::Event event) override;

    bool state1_on_entry_called_ = false;
    void State1OnEntry() override;
    void State1OnExit() override;
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