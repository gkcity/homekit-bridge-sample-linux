/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   AirConditioner_1_AccessoryInformation_doSet.c
*
* @remark
*
*/

#include "AirConditioner_1_AccessoryInformation_doSet.h"
#include "../../../definition/airconditioner/AirConditioner_IID.h"
#include <status/HapStatus.h>

/**
 * 值: o->value->data.boolean->value;
 * 取值: true 或　false
 */
static void AirConditioner_2_Identify_doSet(PropertyOperation *o)
{
    // TODO: 执行写操作，通常是点亮设备的指示灯，或者让设备闪几下，或者发出一段声音。
    printf("AirConditioner_2_Identify_doSet: %d\n", o->value->data.boolean->value);
    o->status = HAP_OK;
}

void AirConditioner_1_AccessoryInformation_doSet(PropertyOperation *o)
{
    printf("AirConditioner_1_AccessoryInformation_doSet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case AirConditioner_IID_2_Identify:
            AirConditioner_2_Identify_doSet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}