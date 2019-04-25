/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   AirConditioner_doPropertySet.c
*
* @remark
*
*/

#include "AirConditioner_doPropertySet.h"
#include <status/HapStatus.h>
#include "1/AirConditioner_1_AccessoryInformation_doSet.h"
#include "8/AirConditioner_8_Thermostat_doSet.h"
#include "../../definition/airconditioner/AirConditioner_IID.h"
#include "../../print/PrintValue.h"

void AirConditioner_doPropertySet(PropertyOperation *o)
{
    printf("AirConditioner_doPropertySet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);
    printValue(o->value);

    switch (o->pid.siid)
    {
        case AirConditioner_IID_1_AccessoryInformation:
            AirConditioner_1_AccessoryInformation_doSet(o);
            break;

        case AirConditioner_IID_8_Thermostat:
            AirConditioner_8_Thermostat_doSet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}