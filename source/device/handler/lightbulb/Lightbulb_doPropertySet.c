/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   Lightbulb_doPropertySet.c
*
* @remark
*
*/

#include "Lightbulb_doPropertySet.h"
#include <status/HapStatus.h>
#include "S_1_AccessoryInformation/S_1_AccessoryInformation_doSet.h"
#include "S_8_Lightbulb/S_8_Lightbulb_doSet.h"
#include "../../definition/lightbulb/LightbulbIID.h"
#include "../../print/PrintValue.h"

void Lightbulb_doPropertySet(PropertyOperation *o)
{
    printf("Lightbulb_doPropertySet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);
    printValue(o->value);

    switch (o->pid.siid)
    {
        case Lightbulb_IID_1_AccessoryInformation:
            S_1_AccessoryInformation_doSet(o);
            break;

        case Lightbulb_IID_8_Lightbulb:
            S_8_Lightbulb_doSet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}