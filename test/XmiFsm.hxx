#pragma once

#include <ostream>

#include <cpp_event_framework/Statemachine.hxx>

enum class EXmiEvent
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

inline std::ostream& operator<<(std::ostream& os, EXmiEvent event)
{
    switch (event)
    {
    case EXmiEvent::Transition_1:
        os << "Transition_1";
        break;
    case EXmiEvent::Transition_2:
        os << "Transition_2";
        break;
    case EXmiEvent::Transition_3:
        os << "Transition_3";
        break;
    case EXmiEvent::Transition_4:
        os << "Transition_4";
        break;
    case EXmiEvent::Transition_6:
        os << "Transition_6";
        break;
    case EXmiEvent::Transition_7:
        os << "Transition_7";
        break;
    case EXmiEvent::Transition_8:
        os << "Transition_8";
        break;
    case EXmiEvent::Internal:
        os << "Internal";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

class IXmiFsmImpl;
using XmiTestBase = cpp_event_framework::Statemachine<IXmiFsmImpl, EXmiEvent>;

#include "generated/IXmiTestImpl.hxx"
#include "generated/XmiTestDeclaration.hxx"

class IXmiFsmImpl : public IXmiTestImpl
{
public:
    virtual void UnhandledEvent() = 0;
};
