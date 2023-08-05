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

        void (Fsm::ImplPtr)(Fsm::StateRef state)

- Transition actions. The signature allows to use class member functions as actions.
    The argument "event" may be useful in actions because the action may depend on the event type or attributes
    of the event.

        void (Fsm::ImplPtr)(Fsm::Event event)

- Guards. The signature allows to use class member functions as guards.

        bool (Fsm::ImplPtr)(Fsm::Event event)

## License

Apache-2.0

## Author

Dirk Ziegelmeier <dirk@ziegelmeier.net>

