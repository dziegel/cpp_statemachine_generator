#pragma once

#include <cpp_event_framework/Statemachine.hxx>

enum class EScXmlEvent
{
    Transition_1,
    Transition_2,
    Transition_3,
    Transition_7,
    Transition_8,
    Internal
};

class IStatemachineTestImpl;
using StatemachineTestBase = cpp_event_framework::Statemachine<IStatemachineTestImpl, EScXmlEvent>;

#include "generated/IStatemachineTestImpl.hxx"
#include "generated/StatemachineTestDeclaration.hxx"
