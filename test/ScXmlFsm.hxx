#pragma once

#include <cpp_event_framework/Statemachine.hxx>

enum class EEvent
{
    Transition_1,
    Transition_2,
    Transition_3,
    Transition_7,
    Transition_8,
};

class IStatemachineTestImpl;
using StatemachineTestBase = cpp_event_framework::Statemachine<IStatemachineTestImpl, EEvent>;

#include "generated/IStatemachineTestImpl.hxx"
#include "generated/StatemachineTestDeclaration.hxx"
