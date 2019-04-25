/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Lightbulb.c
 *
 * @remark
 *
 */

#include <tiny_snprintf.h>
#include "Lightbulb.h"
#include "S_1_AccessoryInformation.h"
#include "S_8_Lightbulb.h"

Device * Lightbulb(uint16_t aid)
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

        if (RET_FAILED(TinyList_AddTail(&thiz->services, S_1_AccessoryInformation())))
        {
            Device_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->services, S_8_Lightbulb())))
        {
            Device_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}