# C++ statemachine generator

## Introduction

This is a C++ statemachine generator that generates statemachines based on <https://github.com/dziegel/cpp_event_framework> from an XMI model (tested with Eclipse Papyrus <https://www.eclipse.org/papyrus> and Catia Magic Cyber-Systems Engineer <https://www.3ds.com/de/produkte-und-services/catia/produkte/catia-magic/magic-cyber-systems-engineer/> support) or an SCXML model (tested with QtCreator <https://www.qt.io/product/development-tools>).

The Eclipse Epsilon <https://eclipse.dev/epsilon> framework is used to implement the generator.

## NOT supported

- Parallel statemachines
- Fork/Join
- Terminate
- Sub statemachines

## Supported

- States
- Hierarchical statemachines (Composite states)
- Transitions
- Transition actions
- Guards
- Entry/exit actions
- Shallow history
- Choice states
- Junction states

## Usage

The generator is a Java JAR file. To generate, call it as follows:

    java -jar StatemachineGenerator-x.y.z.jar <uml> <out_path>

examples:

    java -jar StatemachineGenerator-1.4.0.jar PathToMyDiagram.xmi ./generated
    java -jar StatemachineGenerator-1.4.0.jar PathToMyDiagram.uml ./generated
    java -jar StatemachineGenerator-1.4.0.jar PathToMyDiagram.scxml ./generated

## Catia Magic Cyber-Systems Engineer support

To generate statemachines from an Catia Magic Cyber-Systems Engineer model, export it to Eclipse UML2 5.x XMI (File->Export To->Eclipse UML2...) and generate exported file via command line as usual. 

## License

Apache-2.0

## Author

Dirk Ziegelmeier <dirk@ziegelmeier.net>
