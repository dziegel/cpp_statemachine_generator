#pragma once

#include <ostream>

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

inline std::ostream& operator<<(std::ostream& os, EScXmlEvent event)
{
    switch (event)
    {
    case EScXmlEvent::Transition_1:
        os << "Transition_1";
        break;
    case EScXmlEvent::Transition_2:
        os << "Transition_2";
        break;
    case EScXmlEvent::Transition_3:
        os << "Transition_3";
        break;
    case EScXmlEvent::Transition_7:
        os << "Transition_7";
        break;
    case EScXmlEvent::Transition_8:
        os << "Transition_8";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

class IStatemachineTestImpl;
using StatemachineTestBase = cpp_event_framework::Statemachine<IStatemachineTestImpl, EScXmlEvent>;

#include "generated/IStatemachineTestImpl.hxx"
#include "generated/StatemachineTestDeclaration.hxx"
