/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge.c
 *
 * @remark
 *
 */

#include <tiny_snprintf.h>
#include "Bridge.h"
#include "Bridge_1_AccessoryInformation.h"
#include "Bridge_8_HapProtocolInformation.h"
#include "../../handler/OnPropertySet.h"
#include "../../handler/OnPropertyGet.h"
#include "../../initializer/InitializeConfiguration.h"

Product * Bridge(const char *did, const char *name, const char *ip, const char *setupCode)
{
    Product *thiz = NULL;

    do
    {
        if (did == NULL || name == NULL || ip == NULL || setupCode == NULL)
        {
            break;
        }

        thiz = Product_New();
        if (thiz == NULL)
        {
            break;
        }

        thiz->onGet = OnPropertyGet;
        thiz->onSet = OnPropertySet;
        thiz->device.index = 1;

        if (RET_FAILED(TinyList_AddTail(&thiz->device.services, Bridge_1_AccessoryInformation())))
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->device.services, Bridge_8_HapProtocolInformation())))
        {
            break;
        }

        InitializeConfiguration(&thiz->config, did, name, ip, setupCode);
    } while (false);

    return thiz;
}