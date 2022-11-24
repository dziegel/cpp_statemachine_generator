# cpp_statemachine_generator

## Introduction

This is a C++ statemachine generator that generates statemachines based on https://github.com/dziegel/cpp_event_framework
from an XMI model (e.g. created via Eclipse Papyrus https://www.eclipse.org/papyrus/).
The code generation tool used is Acceleo https://www.eclipse.org/acceleo/.

## Current state

The tool generates the statemachine, state declarations and state handlers. Choice states are supported.

## Function signatures

- Entry/Exit actions. Same as for handlers - the signature allows to use class member functions
    as action. Also, the argument "state" allows to use the same action function for multiple states.

        void (*)(Fsm::OwnerPtr owner, Fsm::StatePtr state) // delegate
        void (Fsm::OwnerPtr)(Fsm::StatePtr state)          // C++

- Transition actions. The signature allows to use class member functions and delegates as actions.
    The argument "event" may be useful in actions because the action may depend on the event type or attributes
    of the event.

        void (*)(Fsm::OwnerPtr owner, Fsm::Event event) // delegate
        void (Fsm::OwnerPtr)(Fsm::Event event)          // C++

- Guards. The signature allows to use class member functions and delegates as guards.

        bool (*)(Fsm::OwnerPtr owner, Fsm::Event event) // delegate
        bool (Fsm::OwnerPtr)(Fsm::Event event)          // C++

## License

Apache-2.0

## Author

Dirk Ziegelmeier <dirk@ziegelmeier.net>

