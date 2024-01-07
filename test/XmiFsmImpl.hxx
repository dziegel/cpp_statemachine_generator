#pragma once

#include "XmiFsm.hxx"

class XmiFsmImpl final : private IIoArHandlerMainImpl
{
public:
    XmiFsmImpl();

    void Test();

private:
    IoArHandlerMain fsm_;

    bool ready_ = false;

    void AbortAr(IoArHandlerMainBase::Event event) override;
    void ApplyConfiguration(IoArHandlerMainBase::Event event) override;
    void ArClosed(IoArHandlerMainBase::Event event) override;
    void BackupSwitchover(IoArHandlerMainBase::Event event) override;
    void CheckModuleDiff(IoArHandlerMainBase::Event event) override;
    void DrPlug(IoArHandlerMainBase::Event event) override;
    void DrPull(IoArHandlerMainBase::Event event) override;
    void DrPullDone(IoArHandlerMainBase::Event event) override;
    void DynReconfTimeoutAbortArSet(IoArHandlerMainBase::Event event) override;
    void PrimarySwitchover(IoArHandlerMainBase::Event event) override;
    void Read(IoArHandlerMainBase::Event event) override;
    void Write(IoArHandlerMainBase::Event event) override;

    bool CheckApplicationReady(IoArHandlerMainBase::Event event) override;
    bool FirstInArSetOrPrimary(IoArHandlerMainBase::Event event) override;
    bool success(IoArHandlerMainBase::Event event) override;

    void SendApplicationReady() override;
    void StartDynReconfTimer() override;
    void StartWaitApplicationReadyTimer() override;
    void StopDynReconfTimer() override;
    void StopWaitApplicationReadyTimer() override;
};