/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_3_Manufacturer.h
 *
 * @remark
 *
 */

#include "AirConditioner_3_Manufacturer.h"

Property * AirConditioner_3_Manufacturer(void)
{
    return Property_NewInstance(3, "homekit-spec", "manufacturer", 0x00000020, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}