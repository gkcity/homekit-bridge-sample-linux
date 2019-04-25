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
#include <status/HapStatus.h>
#include "bridge/Bridge_doPropertyGet.h"
#include "airconditioner/AirConditioner_doPropertyGet.h"

void OnPropertyGet(PropertyOperation *o)
{
    printf("OnPropertyGet: %d.%d.%d\n", o->pid.aid, o->pid.siid, o->pid.iid);

    switch (o->pid.aid)
    {
        case 1:
            Bridge_doPropertyGet(o);
            break;

        default:
            AirConditioner_doPropertyGet(o);
            break;
    }
}
