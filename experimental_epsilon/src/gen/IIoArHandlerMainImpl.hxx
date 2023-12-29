class IIoArHandlerMainImpl
{
	public:
	// Actions
	virtual void ApplyConfiguration(IoArHandlerMainBase::Event event) = 0;
	virtual void DrPullDone(IoArHandlerMainBase::Event event) = 0;
	virtual void DynReconfTimeoutAbortArSet(IoArHandlerMainBase::Event event) = 0;
	virtual void DrPlug(IoArHandlerMainBase::Event event) = 0;
	virtual void DrPull(IoArHandlerMainBase::Event event) = 0;
	virtual void AbortAr(IoArHandlerMainBase::Event event) = 0;
	virtual void ArClosed(IoArHandlerMainBase::Event event) = 0;
	virtual void CheckModuleDiff(IoArHandlerMainBase::Event event) = 0;
	virtual void Read(IoArHandlerMainBase::Event event) = 0;
	virtual void BackupSwitchover(IoArHandlerMainBase::Event event) = 0;
	virtual void PrimarySwitchover(IoArHandlerMainBase::Event event) = 0;
	virtual void Write(IoArHandlerMainBase::Event event) = 0;
	
	// Guards
	virtual bool CheckApplicationReady(IoArHandlerMainBase::Event event) = 0;
	virtual bool FirstInArSetOrPrimary(IoArHandlerMainBase::Event event) = 0;
	virtual bool success(IoArHandlerMainBase::Event event) = 0;
	
	// Entry/Exit
	virtual void StartDynReconfTimer() = 0;
	virtual void StopDynReconfTimer() = 0;
	virtual void StartWaitApplicationReadyTimer() = 0;
	virtual void StopWaitApplicationReadyTimer() = 0;
	virtual void SendApplicationReady() = 0;
};