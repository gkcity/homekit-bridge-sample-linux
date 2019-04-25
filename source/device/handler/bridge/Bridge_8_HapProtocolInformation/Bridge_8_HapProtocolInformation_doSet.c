/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Bridge_8_HapProtocolInformation_doSet.c
*
* @remark
*
*/

#include "Bridge_8_HapProtocolInformation_doSet.h"
#include "../../../definition/lightbulb/LightbulbIID.h"
#include <status/HapStatus.h>


void Bridge_8_HapProtocolInformation_doSet(PropertyOperation *o)
{
    printf("Bridge_8_HapProtocolInformation_doSet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}