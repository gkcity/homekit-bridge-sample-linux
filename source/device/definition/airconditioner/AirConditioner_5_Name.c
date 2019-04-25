/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_5_Name.h
 *
 * @remark
 *
 */

#include "AirConditioner_5_Name.h"

Property * AirConditioner_5_Name(void)
{
    return Property_NewInstance(5, "homekit-spec", "name", 0x00000023, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}