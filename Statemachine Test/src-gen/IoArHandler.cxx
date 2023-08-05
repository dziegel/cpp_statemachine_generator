#include <cpp_event_framework/Statemachine.hxx>
#include <iostream>

enum class EEvent
{
    S_PNS_ArOpend_ind,
    S_PNS_ParamEndInd,
    S_PNS_ArClosed_ind,
    S_PNS_SwitchoverRequestPrimary,
    S_PNS_SwitchoverRequestBackup,
    SPnpbAppTimeout,
    S_PNS_PlugParamEndInd,
    S_PNS_PlugSubmodule_cnf,
    S_PNS_PullSubmodule_cnf,
    S_PNS_PlugApplicationReady_cnf,
    SPnioAppTimeoutDynReconf,
    S_PNS_WriteReq,
    S_PNS_ReadReq,
    S_PNS_CheckModuleDiff,
    S_PNS_ApplicationReady_cnf,
    S_PNS_DynReconfPlug,
    S_PNS_DynReconfPull

};

class IoArHandler;
using IoArHandlerMainBase = cpp_event_framework::Statemachine<IoArHandler, EEvent>;

#include "IoArHandlerMainDeclaration.hxx"

class IoArHandler
{
public:
    IoArHandler() = default;

    void Init()
    {
        fsm_.on_handle_event_ = [](IoArHandlerMain::StateRef state, IoArHandlerMain::Event event)
        { std::cout << "State " << state.Name() << " handle event " << static_cast<int>(event) << std::endl; };
        fsm_.on_state_entry_ = [](IoArHandlerMain::StateRef state)
        { std::cout << "Enter state" << state.Name() << std::endl; };
        fsm_.on_state_exit_ = [](IoArHandlerMain::StateRef state)
        { std::cout << "Exit state" << state.Name() << std::endl; };
        fsm_.on_unhandled_event_ = [](IoArHandlerMain::StateRef state, IoArHandlerMain::Event event)
        { std::cout << "Unhandled event " << static_cast<int>(event) << " in state " << state.Name() << std::endl; };

        fsm_.Init(this, "IoArHandlerMain", IoArHandlerMain::kInitialState);
        fsm_.Start();
    }

    void Run()
    {
        fsm_.React(EEvent::S_PNS_ArOpend_ind);
        assert(fsm_.CurrentState() == &IoArHandlerMain::kParameterizing);
        fsm_.React(EEvent::S_PNS_ParamEndInd);
        assert(fsm_.CurrentState() == &IoArHandlerMain::kWaitApplicationReady);
        fsm_.React(EEvent::SPnpbAppTimeout);
        assert(fsm_.CurrentState() == &IoArHandlerMain::kWaitApplicationReady);
        fsm_.React(EEvent::SPnpbAppTimeout);
        assert(fsm_.CurrentState() == &IoArHandlerMain::kWaitApplicationReadyCnf);
        fsm_.React(EEvent::S_PNS_ArClosed_ind);
        assert(fsm_.CurrentState() == &IoArHandlerMain::kClosed);
    }

private:
#include "IoArHandlerMainPrototypes.hxx"

    bool ready_ = false;
    bool CheckApplicationReady(IoArHandlerMain::Event)
    {
        auto old = ready_;
        ready_ = true;
        return old;
    }
    bool success(IoArHandlerMain::Event)
    {
        return true;
    }
    bool FirstInArSetOrPrimary(IoArHandlerMain::Event)
    {
        return true;
    }

    friend class IoArHandlerMain;
    IoArHandlerMain fsm_;

    void ArClosed(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void PrimarySwitchover(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void BackupSwitchover(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void Read(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void Write(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void CheckModuleDiff(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void ApplyConfiguration(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void StartWaitApplicationReadyTimer(IoArHandlerMain::StateRef)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void StopWaitApplicationReadyTimer(IoArHandlerMain::StateRef)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void SendApplicationReady(IoArHandlerMain::StateRef)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void AbortAr(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void DrPull(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void DrPlug(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void StartDynReconfTimer(IoArHandlerMain::StateRef)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void StopDynReconfTimer(IoArHandlerMain::StateRef)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void DynReconfTimeoutAbortArSet(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void DrPullDone(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    void DrPlugDone(IoArHandlerMain::Event)
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};

#include "IoArHandlerMainInstance.hxx"

#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(e) e
#define IoArHandlerMain_GET_STATIC_EVENT_ID(e) EEvent::e

#include "IoArHandlerMainHandlers.hxx"

void TestIoArHandler()
{
    IoArHandler h;
    h.Init();
    h.Run();
}
