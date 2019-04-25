/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge_9_Version.h
 *
 * @remark
 *
 */

#include "Bridge_9_Version.h"

Property * Bridge_9_Version(void)
{
    return Property_NewInstance(9, "homekit-spec", "version", 0x00000037, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}