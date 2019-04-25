/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_8_Thermostat.c
 *
 * @remark
 *
 */

#include "AirConditioner_8_Thermostat.h"
#include "AirConditioner_9_Name.h"
#include "AirConditioner_10_CurrentHeatingCoolingState.h"
#include "AirConditioner_11_TargetHeatingCoolingState.h"
#include "AirConditioner_12_CurrentTemperature.h"
#include "AirConditioner_13_TargetTemperature.h"
#include "AirConditioner_14_TemperatureDisplayUnits.h"

Service * AirConditioner_8_Thermostat(void)
{
    Service *thiz = NULL;

    do
    {
        thiz = Service_NewInstance(8, "homekit-spec", "thermostat", 0x0000004A, NULL);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_9_Name())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_10_CurrentHeatingCoolingState())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_11_TargetHeatingCoolingState())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_12_CurrentTemperature())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_13_TargetTemperature())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_14_TemperatureDisplayUnits())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}