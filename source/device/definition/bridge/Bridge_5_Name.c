/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge_5_Name.h
 *
 * @remark
 *
 */

#include "Bridge_5_Name.h"

Property * Bridge_5_Name(void)
{
    return Property_NewInstance(5, "homekit-spec", "name", 0x00000023, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}