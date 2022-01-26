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

    void ArClosed(IoArHandlerMain::Event)
    {
    }
    void PrimarySwitchover(IoArHandlerMain::Event)
    {
    }
    void BackupSwitchover(IoArHandlerMain::Event)
    {
    }
    void Read(IoArHandlerMain::Event)
    {
    }
    void Write(IoArHandlerMain::Event)
    {
    }
    void CheckModuleDiff(IoArHandlerMain::Event)
    {
    }
    void ApplyConfiguration(IoArHandlerMain::Event)
    {
    }
    void StartWaitApplicationReadyTimer(IoArHandlerMain::StatePtr)
    {
    }
    void StartWaitApplicationReadyTimer2(IoArHandlerMain::Event)
    {
    }
    void StopWaitApplicationReadyTimer(IoArHandlerMain::StatePtr)
    {
    }
    void SendApplicationReady(IoArHandlerMain::StatePtr)
    {
    }
    void AbortAr(IoArHandlerMain::Event)
    {
    }
    void DrPull(IoArHandlerMain::Event)
    {
    }
    void DrPlug(IoArHandlerMain::Event)
    {
    }
    void StartDynReconfTimer(IoArHandlerMain::StatePtr)
    {
    }
    void StopDynReconfTimer(IoArHandlerMain::StatePtr)
    {
    }
    void DynReconfTimeoutAbortArSet(IoArHandlerMain::Event)
    {
    }
    void DrPullDone(IoArHandlerMain::Event)
    {
    }
    void DrPlugDone(IoArHandlerMain::Event)
    {
    }
};

#include "IoArHandlerMainInstance.hxx"

#include "IoArHandlerMainHandlers.hxx"

int main()
{
}