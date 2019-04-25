/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_4_Model.h
 *
 * @remark
 *
 */

#include "AirConditioner_4_Model.h"

Property * AirConditioner_4_Model(void)
{
    return Property_NewInstance(4, "homekit-spec", "model", 0x00000021, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}