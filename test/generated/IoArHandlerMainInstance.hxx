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
const IoArHandlerMain::State IoArHandlerMain::kOpen("Open", &OpenHandler, nullptr, &kOpenParameterizing, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::OpenHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ArClosed_ind):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::ArClosed};
			return TransitionTo(kClosed, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_CheckModuleDiff):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::CheckModuleDiff};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ReadReq):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::Read};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestBackup):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::BackupSwitchover};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_SwitchoverRequestPrimary):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::PrimarySwitchover};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_WriteReq):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::Write};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State ApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReady("Open::ApplicationReady", &ApplicationReadyHandler, &kOpen, &kOpenApplicationReadyReady, nullptr, nullptr);
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
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunning("Open::ApplicationReady::DynamicReconfigurationRunning", &DynamicReconfigurationRunningHandler, &kOpenApplicationReady, &kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPlugCnf, &Impl::StartDynReconfTimer, &Impl::StopDynReconfTimer);
IoArHandlerMain::Transition IoArHandlerMain::DynamicReconfigurationRunningHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnioAppTimeoutDynReconf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::DynReconfTimeoutAbortArSet};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State DrPlugPrmSequence
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunningDrPlugPrmSequence("Open::ApplicationReady::DynamicReconfigurationRunning::DrPlugPrmSequence", &DrPlugPrmSequenceHandler, &kOpenApplicationReadyDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrPlugPrmSequenceHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugParamEndInd):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::ApplyConfiguration};
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyPlugSubmodule, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyCnfPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyCnfPlugSubmodule("Open::ApplicationReady::DynamicReconfigurationRunning::DrWaitApplicationReadyCnfPlugSubmodule", &DrWaitApplicationReadyCnfPlugSubmoduleHandler, &kOpenApplicationReadyDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugApplicationReady_cnf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::DrPullDone};
			return TransitionTo(kOpenApplicationReadyReady, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State DrWaitApplicationReadyPlugSubmodule
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyPlugSubmodule("Open::ApplicationReady::DynamicReconfigurationRunning::DrWaitApplicationReadyPlugSubmodule", &DrWaitApplicationReadyPlugSubmoduleHandler, &kOpenApplicationReadyDynamicReconfigurationRunning, nullptr, &Impl::StartWaitApplicationReadyTimer, &Impl::StopWaitApplicationReadyTimer);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyCnfPlugSubmodule);
		}
		if (true)
		{
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrWaitApplicationReadyPlugSubmodule);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPlugCnf
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPlugCnf("Open::ApplicationReady::DynamicReconfigurationRunning::DrWaitPlugCnf", &DrWaitPlugCnfHandler, &kOpenApplicationReadyDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPlugCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PlugSubmodule_cnf):
		if (true)
		{
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrPlugPrmSequence);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State DrWaitPullCnf
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPullCnf("Open::ApplicationReady::DynamicReconfigurationRunning::DrWaitPullCnf", &DrWaitPullCnfHandler, &kOpenApplicationReadyDynamicReconfigurationRunning, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::DrWaitPullCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_PullSubmodule_cnf):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::DrPullDone};
			return TransitionTo(kOpenApplicationReadyReady, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State Ready
const IoArHandlerMain::State IoArHandlerMain::kOpenApplicationReadyReady("Open::ApplicationReady::Ready", &ReadyHandler, &kOpenApplicationReady, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPlug):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::DrPlug};
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPlugCnf, kActions);
		}
		return UnhandledEvent();
		
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_DynReconfPull):
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::DrPull};
			return TransitionTo(kOpenApplicationReadyDynamicReconfigurationRunningDrWaitPullCnf, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State Parameterizing
const IoArHandlerMain::State IoArHandlerMain::kOpenParameterizing("Open::Parameterizing", &ParameterizingHandler, &kOpen, nullptr, nullptr, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::ParameterizingHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ParamEndInd):
		if (impl->FirstInArSetOrPrimary(event))
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::ApplyConfiguration};
			return TransitionTo(kOpenWaitApplicationReady, kActions);
		}
		if (true)
		{
			return TransitionTo(kOpenWaitApplicationReadyCnf);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReady
const IoArHandlerMain::State IoArHandlerMain::kOpenWaitApplicationReady("Open::WaitApplicationReady", &WaitApplicationReadyHandler, &kOpen, nullptr, &Impl::StartWaitApplicationReadyTimer, &Impl::StopWaitApplicationReadyTimer);
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(SPnpbAppTimeout):
		if (impl->CheckApplicationReady(event))
		{
			return TransitionTo(kOpenWaitApplicationReadyCnf);
		}
		if (true)
		{
			return TransitionTo(kOpenWaitApplicationReady);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}

// State WaitApplicationReadyCnf
const IoArHandlerMain::State IoArHandlerMain::kOpenWaitApplicationReadyCnf("Open::WaitApplicationReadyCnf", &WaitApplicationReadyCnfHandler, &kOpen, nullptr, &Impl::SendApplicationReady, nullptr);
IoArHandlerMain::Transition IoArHandlerMain::WaitApplicationReadyCnfHandler(ImplPtr impl, Event event)
{
	(void)impl; // impl parameter is unused when there is no guard function being called in here
	
	switch(IoArHandlerMain_GET_INSTANCE_EVENT_ID(event))
	{
		case IoArHandlerMain_GET_STATIC_EVENT_ID(S_PNS_ApplicationReady_cnf):
		if (impl->success(event))
		{
			return TransitionTo(kOpenApplicationReady);
		}
		if (true)
		{
			static const Transition::ActionContainer<1> kActions = {&Impl::AbortAr};
			return TransitionTo(kNone, kActions);
		}
		return UnhandledEvent();
		
		default:
		return UnhandledEvent();
	}
}