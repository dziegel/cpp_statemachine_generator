
// Statemachine IoArHandlerMain declaration

#pragma once

class IoArHandlerMain : public IoArHandlerMainBase
{
	public:
	static const StatePtr kInitialState;
	
	// State Closed
	static Transition ClosedHandler(ImplPtr impl, Event event);
	static const State kClosed;
	// Transition S_PNS_SwitchoverRequestBackup: Closed -> Closed
	static const Transition::ActionType kClosedToClosedByS_PNS_SwitchoverRequestBackupActions[];
	static const Transition kClosedToClosedByS_PNS_SwitchoverRequestBackup;
	// Transition S_PNS_WriteReq: Closed -> Closed
	static const Transition::ActionType kClosedToClosedByS_PNS_WriteReqActions[];
	static const Transition kClosedToClosedByS_PNS_WriteReq;
	// Transition S_PNS_ArOpend_ind: Closed -> Open
	static const Transition::ActionType kClosedToOpenByS_PNS_ArOpend_indActions[];
	static const Transition kClosedToOpenByS_PNS_ArOpend_ind;
	// Transition S_PNS_SwitchoverRequestPrimary: Closed -> Closed
	static const Transition::ActionType kClosedToClosedByS_PNS_SwitchoverRequestPrimaryActions[];
	static const Transition kClosedToClosedByS_PNS_SwitchoverRequestPrimary;
	// Transition S_PNS_ReadReq: Closed -> Closed
	static const Transition::ActionType kClosedToClosedByS_PNS_ReadReqActions[];
	static const Transition kClosedToClosedByS_PNS_ReadReq;
	
	// State Open
	static Transition OpenHandler(ImplPtr impl, Event event);
	static const State kOpen;
	// Transition S_PNS_ArClosed_ind: Open -> Closed
	static const Transition::ActionType kOpenToClosedByS_PNS_ArClosed_indActions[];
	static const Transition kOpenToClosedByS_PNS_ArClosed_ind;
	// Transition S_PNS_WriteReq: Open -> Open
	static const Transition::ActionType kOpenToOpenByS_PNS_WriteReqActions[];
	static const Transition kOpenToOpenByS_PNS_WriteReq;
	// Transition S_PNS_ReadReq: Open -> Open
	static const Transition::ActionType kOpenToOpenByS_PNS_ReadReqActions[];
	static const Transition kOpenToOpenByS_PNS_ReadReq;
	// Transition S_PNS_SwitchoverRequestPrimary: Open -> Open
	static const Transition::ActionType kOpenToOpenByS_PNS_SwitchoverRequestPrimaryActions[];
	static const Transition kOpenToOpenByS_PNS_SwitchoverRequestPrimary;
	// Transition S_PNS_CheckModuleDiff: Open -> Open
	static const Transition::ActionType kOpenToOpenByS_PNS_CheckModuleDiffActions[];
	static const Transition kOpenToOpenByS_PNS_CheckModuleDiff;
	// Transition S_PNS_SwitchoverRequestBackup: Open -> Open
	static const Transition::ActionType kOpenToOpenByS_PNS_SwitchoverRequestBackupActions[];
	static const Transition kOpenToOpenByS_PNS_SwitchoverRequestBackup;
	
	// State ApplicationReady
	static Transition ApplicationReadyHandler(ImplPtr impl, Event event);
	static const State kApplicationReady;
	
	// State DynamicReconfigurationRunning
	static Transition DynamicReconfigurationRunningHandler(ImplPtr impl, Event event);
	static const State kDynamicReconfigurationRunning;
	// Transition SPnioAppTimeoutDynReconf: DynamicReconfigurationRunning -> DynamicReconfigurationRunning
	static const Transition::ActionType kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconfActions[];
	static const Transition kDynamicReconfigurationRunningToDynamicReconfigurationRunningBySPnioAppTimeoutDynReconf;
	
	// State DrPlugPrmSequence
	static Transition DrPlugPrmSequenceHandler(ImplPtr impl, Event event);
	static const State kDrPlugPrmSequence;
	// Transition S_PNS_PlugParamEndInd: DrPlugPrmSequence -> DrWaitApplicationReadyPlugSubmodule
	static const Transition::ActionType kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndIndActions[];
	static const Transition kDrPlugPrmSequenceToDrWaitApplicationReadyPlugSubmoduleByS_PNS_PlugParamEndInd;
	
	// State DrWaitApplicationReadyCnfPlugSubmodule
	static Transition DrWaitApplicationReadyCnfPlugSubmoduleHandler(ImplPtr impl, Event event);
	static const State kDrWaitApplicationReadyCnfPlugSubmodule;
	// Transition S_PNS_PlugApplicationReady_cnf: DrWaitApplicationReadyCnfPlugSubmodule -> Ready
	static const Transition::ActionType kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnfActions[];
	static const Transition kDrWaitApplicationReadyCnfPlugSubmoduleToReadyByS_PNS_PlugApplicationReady_cnf;
	
	// State DrWaitApplicationReadyPlugSubmodule
	static Transition DrWaitApplicationReadyPlugSubmoduleHandler(ImplPtr impl, Event event);
	static const State kDrWaitApplicationReadyPlugSubmodule;
	// Transition SPnpbAppTimeout: DrWaitApplicationReadyPlugSubmodule -> DrWaitApplicationReadyCnfPlugSubmodule
	static const Transition::ActionType kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeoutActions[];
	static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyCnfPlugSubmoduleBySPnpbAppTimeout;
	// Transition SPnpbAppTimeout: DrWaitApplicationReadyPlugSubmodule -> DrWaitApplicationReadyPlugSubmodule
	static const Transition::ActionType kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeoutActions[];
	static const Transition kDrWaitApplicationReadyPlugSubmoduleToDrWaitApplicationReadyPlugSubmoduleBySPnpbAppTimeout;
	
	// State DrWaitPlugCnf
	static Transition DrWaitPlugCnfHandler(ImplPtr impl, Event event);
	static const State kDrWaitPlugCnf;
	// Transition S_PNS_PlugSubmodule_cnf: DrWaitPlugCnf -> DrPlugPrmSequence
	static const Transition::ActionType kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnfActions[];
	static const Transition kDrWaitPlugCnfToDrPlugPrmSequenceByS_PNS_PlugSubmodule_cnf;
	
	// State DrWaitPullCnf
	static Transition DrWaitPullCnfHandler(ImplPtr impl, Event event);
	static const State kDrWaitPullCnf;
	// Transition S_PNS_PullSubmodule_cnf: DrWaitPullCnf -> Ready
	static const Transition::ActionType kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnfActions[];
	static const Transition kDrWaitPullCnfToReadyByS_PNS_PullSubmodule_cnf;
	
	// State Ready
	static Transition ReadyHandler(ImplPtr impl, Event event);
	static const State kReady;
	// Transition S_PNS_DynReconfPull: Ready -> DrWaitPullCnf
	static const Transition::ActionType kReadyToDrWaitPullCnfByS_PNS_DynReconfPullActions[];
	static const Transition kReadyToDrWaitPullCnfByS_PNS_DynReconfPull;
	// Transition S_PNS_DynReconfPlug: Ready -> DrWaitPlugCnf
	static const Transition::ActionType kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlugActions[];
	static const Transition kReadyToDrWaitPlugCnfByS_PNS_DynReconfPlug;
	
	// State Parameterizing
	static Transition ParameterizingHandler(ImplPtr impl, Event event);
	static const State kParameterizing;
	// Transition S_PNS_ParamEndInd: Parameterizing -> WaitApplicationReady
	static const Transition::ActionType kParameterizingToWaitApplicationReadyByS_PNS_ParamEndIndActions[];
	static const Transition kParameterizingToWaitApplicationReadyByS_PNS_ParamEndInd;
	// Transition S_PNS_ParamEndInd: Parameterizing -> WaitApplicationReadyCnf
	static const Transition::ActionType kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndIndActions[];
	static const Transition kParameterizingToWaitApplicationReadyCnfByS_PNS_ParamEndInd;
	
	// State WaitApplicationReady
	static Transition WaitApplicationReadyHandler(ImplPtr impl, Event event);
	static const State kWaitApplicationReady;
	// Transition SPnpbAppTimeout: WaitApplicationReady -> WaitApplicationReadyCnf
	static const Transition::ActionType kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeoutActions[];
	static const Transition kWaitApplicationReadyToWaitApplicationReadyCnfBySPnpbAppTimeout;
	// Transition SPnpbAppTimeout: WaitApplicationReady -> WaitApplicationReady
	static const Transition::ActionType kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeoutActions[];
	static const Transition kWaitApplicationReadyToWaitApplicationReadyBySPnpbAppTimeout;
	
	// State WaitApplicationReadyCnf
	static Transition WaitApplicationReadyCnfHandler(ImplPtr impl, Event event);
	static const State kWaitApplicationReadyCnf;
	// Transition S_PNS_ApplicationReady_cnf: WaitApplicationReadyCnf -> ApplicationReady
	static const Transition::ActionType kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnfActions[];
	static const Transition kWaitApplicationReadyCnfToApplicationReadyByS_PNS_ApplicationReady_cnf;
	// Transition S_PNS_ApplicationReady_cnf: WaitApplicationReadyCnf -> WaitApplicationReadyCnf
	static const Transition::ActionType kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnfActions[];
	static const Transition kWaitApplicationReadyCnfToWaitApplicationReadyCnfByS_PNS_ApplicationReady_cnf;
};
