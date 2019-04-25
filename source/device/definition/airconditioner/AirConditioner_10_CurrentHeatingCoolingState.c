/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_10_CurrentHeatingCoolingState.h
 *
 * @remark
 *
 */

#include "AirConditioner_10_CurrentHeatingCoolingState.h"

Property * AirConditioner_10_CurrentHeatingCoolingState(void)
{
    return Property_NewInstance(10, "homekit-spec", "current-heating-cooling-state", 0x0000000F, NULL, FORMAT_UINT8, ACCESS_RN, NONE);
}