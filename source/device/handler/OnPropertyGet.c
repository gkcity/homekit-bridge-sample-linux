/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   OnPropertyGet.c
*
* @remark
*
*/

#include "OnPropertyGet.h"
#include "../definition/lightbulb/LightbulbIID.h"
#include <status/HapStatus.h>
#include "bridge/Bridge_doPropertyGet.h"
#include "lightbulb/Lightbulb_doPropertyGet.h"

void OnPropertyGet(PropertyOperation *o)
{
    printf("OnPropertyGet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);

    switch (o->pid.aid)
    {
        case 1:
            Bridge_doPropertyGet(o);
            break;

        case 2:
        case 3:
        case 4:
            Lightbulb_doPropertyGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}
