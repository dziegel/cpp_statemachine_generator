#include <iostream>
#include <source_location>

#include "XmiFsmImpl.hxx"

XmiFsmImpl::XmiFsmImpl()
{
    fsm_.on_handle_event_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state, IoArHandlerMain::Event event)
    { std::cout << fsm.Name() << " State " << state.Name() << " handle event " << event << '\n'; };
    fsm_.on_state_entry_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state)
    { std::cout << fsm.Name() << " Enter state" << state.Name() << '\n'; };
    fsm_.on_state_exit_ = [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state)
    { std::cout << fsm.Name() << " Exit state" << state.Name() << '\n'; };
    fsm_.on_unhandled_event_ =
        [](IoArHandlerMain::Ref fsm, IoArHandlerMain::StateRef state, IoArHandlerMain::Event event)
    { std::cout << fsm.Name() << " Unhandled event " << event << " in state " << state.Name() << '\n'; };

    fsm_.Init(this, "Xmi", IoArHandlerMain::kInitialState);
}

void XmiFsmImpl::Test()
{
    assert(fsm_.CurrentState() == nullptr);
    fsm_.Start();

    assert(fsm_.CurrentState() == &IoArHandlerMain::kClosed);
    fsm_.React(EXmiEvent::S_PNS_ArOpend_ind);
    assert(fsm_.CurrentState() == &IoArHandlerMain::kOpenParameterizing);
    fsm_.React(EXmiEvent::S_PNS_ParamEndInd);
    assert(fsm_.CurrentState() == &IoArHandlerMain::kOpenWaitApplicationReady);
    fsm_.React(EXmiEvent::SPnpbAppTimeout);
    assert(fsm_.CurrentState() == &IoArHandlerMain::kOpenWaitApplicationReady);
    fsm_.React(EXmiEvent::SPnpbAppTimeout);
    assert(fsm_.CurrentState() == &IoArHandlerMain::kOpenWaitApplicationReadyCnf);
    fsm_.React(EXmiEvent::S_PNS_ArClosed_ind);
    assert(fsm_.CurrentState() == &IoArHandlerMain::kClosed);
}

bool XmiFsmImpl::CheckApplicationReady(IoArHandlerMain::Event /*event*/)
{
    auto old = ready_;
    ready_ = true;
    return old;
}
bool XmiFsmImpl::success(IoArHandlerMain::Event /*event*/)
{
    return true;
}
bool XmiFsmImpl::FirstInArSetOrPrimary(IoArHandlerMain::Event /*event*/)
{
    return true;
}

void XmiFsmImpl::ArClosed(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << '\n';
}
void XmiFsmImpl::PrimarySwitchover(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::BackupSwitchover(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::Read(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::Write(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::CheckModuleDiff(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::ApplyConfiguration(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::DynReconfTimeoutAbortArSet(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::DrPullDone(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::AbortAr(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::DrPull(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::DrPlug(IoArHandlerMain::Event /*event*/)
{
    std::cout << std::source_location::current().function_name() << "\n";
}

void XmiFsmImpl::StartWaitApplicationReadyTimer()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::StopWaitApplicationReadyTimer()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::SendApplicationReady()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::StartDynReconfTimer()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
void XmiFsmImpl::StopDynReconfTimer()
{
    std::cout << std::source_location::current().function_name() << "\n";
}
