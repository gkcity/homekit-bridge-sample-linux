/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_11_TargetHeatingCoolingState.h
 *
 * @remark
 *
 */

#include "AirConditioner_11_TargetHeatingCoolingState.h"

Property * AirConditioner_11_TargetHeatingCoolingState(void)
{
    return Property_NewInstance(11, "homekit-spec", "target-heating-cooling-state", 0x00000033, NULL, FORMAT_UINT8, ACCESS_RWN, NONE);
}