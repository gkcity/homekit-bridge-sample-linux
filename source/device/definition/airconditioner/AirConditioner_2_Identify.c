/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_2_Identify.h
 *
 * @remark
 *
 */

#include "AirConditioner_2_Identify.h"

Property * AirConditioner_2_Identify(void)
{
    return Property_NewInstance(2, "homekit-spec", "identify", 0x00000014, NULL, FORMAT_BOOL, ACCESS_WRITE, NONE);
}