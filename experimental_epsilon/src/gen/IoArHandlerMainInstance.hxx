// Statemachine IoArHandlerMain instance

// Override the following defines according to your needs if you are not using cpp_event_framework:

#ifndef IoArHandlerMain_GET_INSTANCE_EVENT_ID
#define IoArHandlerMain_GET_INSTANCE_EVENT_ID(event_instance) event_instance->Id()
#endif

#ifndef IoArHandlerMain_GET_STATIC_EVENT_ID
#define IoArHandlerMain_GET_STATIC_EVENT_ID(event_name) event_name::kId
#endif

// Initial state
const IoArHandlerMain::StatePtr IoArHandlerMain::kInitialState = &IoArHandlerMain::kClosed;

// State Closed
const IoArHandlerMain::State IoArHandlerMain::kClosed("Closed", &ClosedHandler, nullptr, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ClosedHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArOpend_ind):
		if (true)
		{
			return TransitionTo(kOpen);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		if (true)
		{
			return TransitionTo(kNone);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		if (true)
		{
			return TransitionTo(kNone);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		if (true)
		{
			return TransitionTo(kNone);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		if (true)
		{
			return TransitionTo(kNone);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State Open
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open", &OpenHandler, nullptr, &kParameterizing, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::OpenHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::ArClosed};
			return TransitionTo(kClosed, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::CheckModuleDiff};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::Read};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::BackupSwitchover};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::PrimarySwitchover};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::Write};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kApplicationReady("ApplicationReady", &ApplicationReadyHandler, &kOpen, &kReady, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		default:
		return UnhandledEvent();
	}
}

// State DynamicReconfigurationRunning
const IoArHandlerMain::State IoArHandlerMain::kDynamicReconfigurationRunning("DynamicReconfigurationRunning", &DynamicReconfigurationRunningHandler, &kApplicationReady, &kDrWaitPlugCnf, &Impl::StartDynReconfTimer, &Impl::StopDynReconfTimer);
IoArHandlerMain::Transition IoArHandlerMain::DynamicReconfigurationRunningHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnioAppTimeoutDynReconf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::DynReconfTimeoutAbortArSet};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kDrPlugPrmSequence("DrPlugPrmSequence", &DrPlugPrmSequenceHandler, &kDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrPlugPrmSequenceHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugParamEndInd):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::ApplyConfiguration};
			return TransitionTo(kDrWaitApplicationReadyPlugSubmodule, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyCnfPlugSubmodule("DrWaitApplicationReadyCnfPlugSubmodule", &DrWaitApplicationReadyCnfPlugSubmoduleHandler, &kDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugApplicationReady_cnf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::DrPullDone};
			return TransitionTo(kReady, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kDrWaitApplicationReadyPlugSubmodule("DrWaitApplicationReadyPlugSubmodule", &DrWaitApplicationReadyPlugSubmoduleHandler, &kDynamicReconfigurationRunning, nullptr, &Impl::StartWaitApplicationReadyTimer, &Impl::StopWaitApplicationReadyTimer);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return TransitionTo(kDrWaitApplicationReadyCnfPlugSubmodule);
		}
		if (true)
		{
			return TransitionTo(kDrWaitApplicationReadyPlugSubmodule);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPlugCnf("DrWaitPlugCnf", &DrWaitPlugCnfHandler, &kDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPlugCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugSubmodule_cnf):
		if (true)
		{
			return TransitionTo(kDrPlugPrmSequence);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kDrWaitPullCnf("DrWaitPullCnf", &DrWaitPullCnfHandler, &kDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPullCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PullSubmodule_cnf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::DrPullDone};
			return TransitionTo(kReady, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State Ready
const IoArHandlerMain::State IoArHandlerMain::kReady("Ready", &ReadyHandler, &kApplicationReady, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::DrPlug};
			return TransitionTo(kDrWaitPlugCnf, kActions);
		}
		return UnhandledEvent();
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::DrPull};
			return TransitionTo(kDrWaitPullCnf, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kParameterizing("Parameterizing", &ParameterizingHandler, &kOpen, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ParameterizingHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ParamEndInd):
		if (impl->FirstInArSetOrPrimary(event))
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::ApplyConfiguration};
			return TransitionTo(kWaitApplicationReady, kActions);
		}
		if (true)
		{
			return TransitionTo(kWaitApplicationReadyCnf);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReady("WaitApplicationReady", &WaitApplicationReadyHandler, &kOpen, nullptr, &Impl::StartWaitApplicationReadyTimer, &Impl::StopWaitApplicationReadyTimer);
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return TransitionTo(kWaitApplicationReadyCnf);
		}
		if (true)
		{
			return TransitionTo(kWaitApplicationReady);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kWaitApplicationReadyCnf("WaitApplicationReadyCnf", &WaitApplicationReadyCnfHandler, &kOpen, nullptr, &Impl::SendApplicationReady, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
		if (impl->success(event))
		{
			return TransitionTo(kApplicationReady);
		}
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&IoArHandlerMain::Impl::AbortAr};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		default:
		return UnhandledEvent();
	}
}