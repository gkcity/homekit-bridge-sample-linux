/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Bridge_doPropertyGet.c
*
* @remark
*
*/

#include "Bridge_doPropertyGet.h"
#include <status/HapStatus.h>
#include "../../definition/bridge/BridgeIID.h"
#include "1/Bridge_1_AccessoryInformation_doGet.h"
#include "8/Bridge_8_HapProtocolInformation_doGet.h"

void Bridge_doPropertyGet(PropertyOperation *o)
{
    printf("Bridge_doPropertyGet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);

    switch (o->pid.siid)
    {
        case Bridge_IID_1_AccessoryInformation:
            Bridge_1_AccessoryInformation_doGet(o);
            break;

        case Bridge_IID_8_HapProtocolInformation:
            Bridge_8_HapProtocolInformation_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}
