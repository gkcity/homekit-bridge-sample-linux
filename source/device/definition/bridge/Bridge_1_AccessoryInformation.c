/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge_1_AccessoryInformation.c
 *
 * @remark
 *
 */

#include "Bridge_1_AccessoryInformation.h"
#include "Bridge_2_Identify.h"
#include "Bridge_3_Manufacturer.h"
#include "Bridge_4_Model.h"
#include "Bridge_5_Name.h"
#include "Bridge_6_SerialNumber.h"
#include "Bridge_7_FirmwareRevision.h"

Service * Bridge_1_AccessoryInformation(void)
{
    Service *thiz = NULL;

    do
    {
        thiz = Service_NewInstance(1, "homekit-spec", "accessory-information", 0x0000003E, NULL);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_2_Identify())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_3_Manufacturer())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_4_Model())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_5_Name())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_6_SerialNumber())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_7_FirmwareRevision())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}