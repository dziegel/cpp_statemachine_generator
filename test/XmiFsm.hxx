#pragma once

#include <cpp_event_framework/Pool.hxx>
#include <cpp_event_framework/Signal.hxx>
#include <cpp_event_framework/Statemachine.hxx>

class EventPoolAllocator : public cpp_event_framework::CustomAllocator<EventPoolAllocator>
{
};

class Transition_1
    : public cpp_event_framework::SignalBase<Transition_1, 0, cpp_event_framework::Signal, EventPoolAllocator>
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

using PoolSizeCalculator =
    cpp_event_framework::SignalPoolElementSizeCalculator<Transition_1, Transition_2, Transition_3, Transition_4,
                                                         Transition_6, Transition_7, Transition_8, Internal>;

class IXmiFsmImpl;
using XmiTestBase = cpp_event_framework::Statemachine<IXmiFsmImpl, const cpp_event_framework::Signal::SPtr&>;

#include "generated/IXmiTestImpl.hxx"
#include "generated/XmiTestDeclaration.hxx"

class IXmiFsmImpl : public IXmiTestImpl
{
public:
    virtual void UnhandledEvent() = 0;
};
