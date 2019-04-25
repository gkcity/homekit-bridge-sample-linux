/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_13_TargetTemperature.h
 *
 * @remark
 *
 */

#include "AirConditioner_13_TargetTemperature.h"

static TinyRet AirConditioner_13_TargetTemperature_SetValueRange(Property *thiz)
{
    TinyRet ret = TINY_RET_OK;
    JsonValue * min = NULL;
    JsonValue * max = NULL;
    JsonValue * step = NULL;

    do
    {
        min = JsonValue_NewFloat(10);
        if (min == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        max = JsonValue_NewFloat(38);
        if (max == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        step = JsonValue_NewFloat(0.1);
        if (step == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        thiz->valueRange = ValueRange_New(min, max, step);
        if (thiz->valueRange == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }
    } while (false);

    if (min != NULL)
    {
        JsonValue_Delete(min);
    }

    if (max != NULL)
    {
        JsonValue_Delete(max);
    }

    if (step != NULL)
    {
        JsonValue_Delete(step);
    }

    return ret;
}

Property * AirConditioner_13_TargetTemperature(void)
{
    Property *thiz = NULL;

    do
    {
        thiz = Property_NewInstance(13, "homekit-spec", "target-temperature", 0x00000035, NULL, FORMAT_FLOAT, ACCESS_RWN, HOMEKIT_CELSIUS);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(AirConditioner_13_TargetTemperature_SetValueRange(thiz)))
        {
            Property_Delete(thiz);
            break;
        }
    } while (false);

    return thiz;
}