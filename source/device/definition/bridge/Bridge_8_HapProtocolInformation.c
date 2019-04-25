/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge_8_HapProtocolInformation.c
 *
 * @remark
 *
 */

#include "Bridge_8_HapProtocolInformation.h"
#include "Bridge_9_Version.h"

Service * Bridge_8_HapProtocolInformation(void)
{
    Service *thiz = NULL;

    do
    {
        thiz = Service_NewInstance(8, "homekit-spec", "hap-protocol-information", 0x000000A2, NULL);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, Bridge_9_Version())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}