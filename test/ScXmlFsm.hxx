#pragma once

#include <ostream>

#include <cpp_event_framework/Statemachine.hxx>

enum class EScXmlEvent
{
    Transition_1,
    Transition_2,
    Transition_3,
    Transition_4,
    Transition_6,
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
    case EScXmlEvent::Transition_4:
        os << "Transition_4";
        break;
    case EScXmlEvent::Transition_6:
        os << "Transition_6";
        break;
    case EScXmlEvent::Transition_7:
        os << "Transition_7";
        break;
    case EScXmlEvent::Transition_8:
        os << "Transition_8";
        break;
    case EScXmlEvent::Internal:
        os << "Internal";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

class IScXmlFsmImpl;
using ScXmlTestBase = cpp_event_framework::Statemachine<IScXmlFsmImpl, EScXmlEvent>;

#include "generated/IScXmlTestImpl.hxx"
#include "generated/ScXmlTestDeclaration.hxx"

class IScXmlFsmImpl : public IScXmlTestImpl
{
public:
    virtual void UnhandledEvent() = 0;
};
