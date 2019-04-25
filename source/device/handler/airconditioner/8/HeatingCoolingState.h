/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   HeatingCoolingState.h
*
* @remark
*
*/

#ifndef __HeatingCoolingState_H__
#define __HeatingCoolingState_H__

#include <tiny_base.h>

TINY_BEGIN_DECLS


typedef enum _HeatingCoolingState
{
    HEATING_COOLING_STATE_INACTIVE  = 0,
    HEATING_COOLING_STATE_IDLE      = 1,
    HEATING_COOLING_STATE_HEATING   = 2,
    HEATING_COOLING_STATE_COOLING   = 3,
} HeatingCoolingState;

TINY_END_DECLS

#endif /* __HeatingCoolingState_H__ */