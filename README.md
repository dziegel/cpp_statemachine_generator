# cpp_statemachine_generator

## Introduction

This is a C++ statemachine generator that generates statemachines based on https://github.com/dziegel/cpp_event_framework
from an XMI model (e.g. created via Eclipse Papyrus https://www.eclipse.org/papyrus/).
The code generation tool used is Acceleo https://www.eclipse.org/acceleo/.

## Current state

The tool generates the statemachine and state declarations. Handlers (the functions executing the transitions) are NOT (yet) generated.

## License

Apache-2.0

## Author

Dirk Ziegelmeier <dirk@ziegelmeier.net>

