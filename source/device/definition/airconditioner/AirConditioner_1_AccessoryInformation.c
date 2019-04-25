/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   AirConditioner_1_AccessoryInformation.c
 *
 * @remark
 *
 */

#include "AirConditioner_1_AccessoryInformation.h"
#include "AirConditioner_2_Identify.h"
#include "AirConditioner_3_Manufacturer.h"
#include "AirConditioner_4_Model.h"
#include "AirConditioner_5_Name.h"
#include "AirConditioner_6_SerialNumber.h"
#include "AirConditioner_7_FirmwareRevision.h"

Service * AirConditioner_1_AccessoryInformation(void)
{
    Service *thiz = NULL;

    do
    {
        thiz = Service_NewInstance(1, "homekit-spec", "accessory-information", 0x0000003E, NULL);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_2_Identify())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_3_Manufacturer())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_4_Model())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_5_Name())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_6_SerialNumber())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, AirConditioner_7_FirmwareRevision())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}