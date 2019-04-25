/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Lightbulb_doPropertyGet.c
*
* @remark
*
*/

#include "Lightbulb_doPropertyGet.h"
#include <status/HapStatus.h>
#include "S_1_AccessoryInformation/S_1_AccessoryInformation_doGet.h"
#include "S_8_Lightbulb/S_8_Lightbulb_doGet.h"
#include "../../definition/lightbulb/LightbulbIID.h"

void Lightbulb_doPropertyGet(PropertyOperation *o)
{
    printf("Lightbulb_doPropertyGet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);

    switch (o->pid.siid)
    {
        case Lightbulb_IID_1_AccessoryInformation:
            S_1_AccessoryInformation_doGet(o);
            break;

        case Lightbulb_IID_8_Lightbulb:
            S_8_Lightbulb_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}
