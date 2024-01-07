#pragma once

#include <ostream>

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

inline std::ostream& operator<<(std::ostream& os, EXmiEvent event)
{
    switch (event)
    {
    case EXmiEvent::S_PNS_ArOpend_ind:
        os << "S_PNS_ArOpend_ind";
        break;
    case EXmiEvent::S_PNS_ParamEndInd:
        os << "S_PNS_ParamEndInd";
        break;
    case EXmiEvent::S_PNS_ArClosed_ind:
        os << "S_PNS_ArClosed_ind";
        break;
    case EXmiEvent::S_PNS_SwitchoverRequestPrimary:
        os << "S_PNS_SwitchoverRequestPrimary";
        break;
    case EXmiEvent::S_PNS_SwitchoverRequestBackup:
        os << "S_PNS_SwitchoverRequestBackup";
        break;
    case EXmiEvent::SPnpbAppTimeout:
        os << "SPnpbAppTimeout";
        break;
    case EXmiEvent::S_PNS_PlugParamEndInd:
        os << "S_PNS_PlugParamEndInd";
        break;
    case EXmiEvent::S_PNS_PlugSubmodule_cnf:
        os << "S_PNS_PlugSubmodule_cnf";
        break;
    case EXmiEvent::S_PNS_PullSubmodule_cnf:
        os << "S_PNS_PullSubmodule_cnf";
        break;
    case EXmiEvent::S_PNS_PlugApplicationReady_cnf:
        os << "S_PNS_PlugApplicationReady_cnf";
        break;
    case EXmiEvent::SPnioAppTimeoutDynReconf:
        os << "SPnioAppTimeoutDynReconf";
        break;
    case EXmiEvent::S_PNS_WriteReq:
        os << "S_PNS_WriteReq";
        break;
    case EXmiEvent::S_PNS_ReadReq:
        os << "S_PNS_ReadReq";
        break;
    case EXmiEvent::S_PNS_CheckModuleDiff:
        os << "S_PNS_CheckModuleDiff";
        break;
    case EXmiEvent::S_PNS_ApplicationReady_cnf:
        os << "S_PNS_ApplicationReady_cnf";
        break;
    case EXmiEvent::S_PNS_DynReconfPlug:
        os << "S_PNS_DynReconfPlug";
        break;
    case EXmiEvent::S_PNS_DynReconfPull:
        os << "S_PNS_DynReconfPull";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

class IIoArHandlerMainImpl;
using IoArHandlerMainBase = cpp_event_framework::Statemachine<IIoArHandlerMainImpl, EXmiEvent>;

#include "generated/IIoArHandlerMainImpl.hxx"
#include "generated/IoArHandlerMainDeclaration.hxx"
