#include <cpp_event_framework/Signal.hxx>
#include <cpp_event_framework/Statemachine.hxx>

class IoArHandler;
using IoArHandlerMainBase = cpp_event_framework::Statemachine<IoArHandler, const cpp_event_framework::Signal::SPtr&>;

#include "IoArHandlerMainDeclaration.hxx"

class IoArHandler
{
#include "IoArHandlerMainPrototypes.hxx"

    friend class IoArHandlerMain;
    IoArHandlerMain fsm_;

    void ArClosed(IoArHandlerMain::Event event);
    void PrimarySwitchover(IoArHandlerMain::Event event);
    void BackupSwitchover(IoArHandlerMain::Event event);
    void Read(IoArHandlerMain::Event event);
    void Write(IoArHandlerMain::Event event);
    void CheckModuleDiff(IoArHandlerMain::Event event);
    void ApplyConfiguration(IoArHandlerMain::Event event);
    void StartTimer(IoArHandlerMain::StatePtr event);
    void StopTimer(IoArHandlerMain::StatePtr event);
};

#include "IoArHandlerMainInstance.hxx"
