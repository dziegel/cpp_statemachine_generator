#include <iostream>

#include <cpp_event_framework/Statemachine.hxx>
#include <source_location>

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

class IIoArHandlerMainImpl;
using IoArHandlerMainBase = cpp_event_framework::Statemachine<IIoArHandlerMainImpl, EEvent>;

#include "../../gen/IIoArHandlerMainImpl.hxx"
#include "../../gen/IoArHandlerMainDeclaration.hxx"

class IoArHandler : private IIoArHandlerMainImpl
{
public:
    void Init()
    {
        fsm_.on_handle_event_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state,
                                   IoArHandlerMain::Event event) {
            std::cout << fsm.Name() << " State " << state.Name() << " handle event " << static_cast<int>(event) << '\n';
        };
        fsm_.on_state_entry_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state)
        { std::cout << fsm.Name() << " Enter state" << state.Name() << '\n'; };
        fsm_.on_state_exit_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state)
        { std::cout << fsm.Name() << " Exit state" << state.Name() << '\n'; };
        fsm_.on_unhandled_event_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state,
                                      IoArHandlerMain::Event event) {
            std::cout << fsm.Name() << " Unhandled event " << static_cast<int>(event) << " in state " << state.Name()
                      << '\n';
        };

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
    IoArHandlerMain fsm_;

    bool ready_ = false;
    bool CheckApplicationReady(IoArHandlerMain::Event /*event*/) override
    {
        auto old = ready_;
        ready_ = true;
        return old;
    }
    bool success(IoArHandlerMain::Event /*event*/) override
    {
        return true;
    }
    bool FirstInArSetOrPrimary(IoArHandlerMain::Event /*event*/) override
    {
        return true;
    }

    void ArClosed(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << '\n';
    }
    void PrimarySwitchover(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void BackupSwitchover(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void Read(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void Write(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void CheckModuleDiff(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void ApplyConfiguration(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void DynReconfTimeoutAbortArSet(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void DrPullDone(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void AbortAr(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void DrPull(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void DrPlug(IoArHandlerMain::Event /*event*/) override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }

    void StartWaitApplicationReadyTimer() override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void StopWaitApplicationReadyTimer() override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void SendApplicationReady() override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void StartDynReconfTimer() override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
    void StopDynReconfTimer() override
    {
        std::cout << std::source_location::current().function_name() << "\n";
    }
};

#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(e) e
#define IoArHandlerMain_GET_STATIC_EVENT_ID(e) EEvent::e

#include "../../gen/IoArHandlerMainInstance.hxx"

void TestIoArHandler()
{
    IoArHandler h;
    h.Init();
    h.Run();
}