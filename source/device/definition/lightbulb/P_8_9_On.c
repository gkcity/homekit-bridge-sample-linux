/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   P_8_9_On.h
 *
 * @remark
 *
 */

#include "P_8_9_On.h"

Property * P_8_9_On(void)
{
    Property *thiz = Property_NewInstance(9, "homekit-spec", "on", 0x00000025, NULL, FORMAT_BOOL, ACCESS_RWN, NONE);
    printf("===> P_8_9_On\n");
    printf("===> property.format: %d\n", thiz->format);
    return thiz;
}