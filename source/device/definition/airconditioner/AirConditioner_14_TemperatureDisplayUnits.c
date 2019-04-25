/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_14_TemperatureDisplayUnits.h
 *
 * @remark
 *
 */

#include "AirConditioner_14_TemperatureDisplayUnits.h"

Property * AirConditioner_14_TemperatureDisplayUnits(void)
{
    return Property_NewInstance(14, "homekit-spec", "temperature-display-units", 0x00000036, NULL, FORMAT_UINT8, ACCESS_RWN, NONE);
}