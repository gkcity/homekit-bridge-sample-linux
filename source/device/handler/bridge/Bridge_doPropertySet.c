/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Bridge_doPropertySet.c
*
* @remark
*
*/

#include "Bridge_doPropertySet.h"
#include <status/HapStatus.h>
#include "../../print/PrintValue.h"
#include "../../definition/bridge/BridgeIID.h"
#include "Bridge_1_AccessoryInformation/Bridge_1_AccessoryInformation_doSet.h"
#include "Bridge_8_HapProtocolInformation/Bridge_8_HapProtocolInformation_doSet.h"

void Bridge_doPropertySet(PropertyOperation *o)
{
    printf("Bridge_doPropertySet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);
    printValue(o->value);

    switch (o->pid.siid)
    {
        case Bridge_IID_1_AccessoryInformation:
            Bridge_1_AccessoryInformation_doSet(o);
            break;

        case Bridge_IID_8_HapProtocolInformation:
            Bridge_8_HapProtocolInformation_doSet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}