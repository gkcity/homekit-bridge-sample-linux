/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   AirConditioner_doPropertyGet.c
*
* @remark
*
*/

#include "AirConditioner_doPropertyGet.h"
#include <status/HapStatus.h>
#include "1/AirConditioner_1_AccessoryInformation_doGet.h"
#include "8/AirConditioner_8_Thermostat_doGet.h"
#include "../../definition/airconditioner/AirConditioner_IID.h"

void AirConditioner_doPropertyGet(PropertyOperation *o)
{
    printf("AirConditioner_doPropertyGet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);

    switch (o->pid.siid)
    {
        case AirConditioner_IID_1_AccessoryInformation:
            AirConditioner_1_AccessoryInformation_doGet(o);
            break;

        case AirConditioner_IID_8_Thermostat:
            AirConditioner_8_Thermostat_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}
