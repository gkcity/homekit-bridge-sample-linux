/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   OnPropertySet.c
*
* @remark
*
*/

#include "OnPropertySet.h"
#include <status/HapStatus.h>
#include "../definition/lightbulb/LightbulbIID.h"
#include "../print/PrintValue.h"
#include "bridge/Bridge_doPropertySet.h"
#include "lightbulb/Lightbulb_doPropertySet.h"

void OnPropertySet(PropertyOperation *o)
{
    printf("OnPropertySet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);
    printValue(o->value);

    switch (o->pid.aid)
    {
        case 1:
            Bridge_doPropertySet(o);
            break;

        case 2:
        case 3:
            Lightbulb_doPropertySet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}