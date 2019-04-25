/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   P_1_7_FirmwareRevision.h
 *
 * @remark
 *
 */

#include "P_1_7_FirmwareRevision.h"

Property * P_1_7_FirmwareRevision(void)
{
    return Property_NewInstance(7, "homekit-spec", "firmware-revision", 0x00000052, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}