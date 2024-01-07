#pragma once

#include <cpp_event_framework/Statemachine.hxx>

enum class EXmiEvent
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
using IoArHandlerMainBase = cpp_event_framework::Statemachine<IIoArHandlerMainImpl, EXmiEvent>;

#include "generated/IIoArHandlerMainImpl.hxx"
#include "generated/IoArHandlerMainDeclaration.hxx"
