/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner.c
 *
 * @remark
 *
 */

#include <tiny_snprintf.h>
#include "AirConditioner.h"
#include "AirConditioner_1_AccessoryInformation.h"
#include "AirConditioner_8_Thermostat.h"

Device * AirConditioner(uint16_t aid)
{
    Device *thiz = NULL;

    do
    {
        thiz = Device_New();
        if (thiz == NULL)
        {
            break;
        }

        thiz->index = aid;

        if (RET_FAILED(TinyList_AddTail(&thiz->services, AirConditioner_1_AccessoryInformation())))
        {
            Device_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->services, AirConditioner_8_Thermostat())))
        {
            Device_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}