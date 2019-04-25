/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Bridge_8_HapProtocolInformation_doGet.c
*
* @remark
*
*/

#include "Bridge_8_HapProtocolInformation_doGet.h"
#include "../../../definition/lightbulb/LightbulbIID.h"
#include "../../../definition/bridge/BridgeIID.h"
#include <status/HapStatus.h>

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_9_Version_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("1.1.0"); // 必须是1.1.0
    o->status = HAP_OK;

    printf("P_9_Version_doGet: %s\n", o->value->data.string->value);
}

void Bridge_8_HapProtocolInformation_doGet(PropertyOperation *o)
{
    printf("Bridge_8_HapProtocolInformation_doGet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case Bridge_IID_9_Version:
            P_9_Version_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}