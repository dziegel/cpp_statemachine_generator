#pragma once

#include <ostream>

#include <cpp_event_framework/Pool.hxx>
#include <cpp_event_framework/Signal.hxx>
#include <cpp_event_framework/Statemachine.hxx>

class Transition_1 : public cpp_event_framework::SignalBase<Transition_1, 0>
{
};

class Transition_2 : public cpp_event_framework::NextSignal<Transition_2, Transition_1>
{
};
class Transition_3 : public cpp_event_framework::NextSignal<Transition_3, Transition_2>
{
};
class Transition_4 : public cpp_event_framework::NextSignal<Transition_4, Transition_3>
{
};
class Transition_6 : public cpp_event_framework::NextSignal<Transition_6, Transition_4>
{
};
class Transition_7 : public cpp_event_framework::NextSignal<Transition_7, Transition_6>
{
};
class Transition_8 : public cpp_event_framework::NextSignal<Transition_8, Transition_7>
{
};
class Internal : public cpp_event_framework::NextSignal<Internal, Transition_8>
{
};

inline std::ostream& operator<<(std::ostream& os, const cpp_event_framework::Signal::SPtr& event)
{
    switch (event->Id())
    {
    case Transition_1::kId:
        os << "Transition_1";
        break;
    case Transition_2::kId:
        os << "Transition_2";
        break;
    case Transition_3::kId:
        os << "Transition_3";
        break;
    case Transition_4::kId:
        os << "Transition_4";
        break;
    case Transition_6::kId:
        os << "Transition_6";
        break;
    case Transition_7::kId:
        os << "Transition_7";
        break;
    case Transition_8::kId:
        os << "Transition_8";
        break;
    case Internal::kId:
        os << "Internal";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

class IXmiFsmImpl;
using XmiTestBase = cpp_event_framework::Statemachine<IXmiFsmImpl, const cpp_event_framework::Signal::SPtr&>;

#include "generated/IXmiTestImpl.hxx"
#include "generated/XmiTestDeclaration.hxx"

class IXmiFsmImpl : public IXmiTestImpl
{
public:
    virtual void UnhandledEvent() = 0;
};
