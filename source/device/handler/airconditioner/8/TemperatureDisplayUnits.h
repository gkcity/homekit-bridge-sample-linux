/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   TemperatureDisplayUnits.h
*
* @remark
*
*/

#ifndef __TemperatureDisplayUnits_H__
#define __TemperatureDisplayUnits_H__

#include <tiny_base.h>

TINY_BEGIN_DECLS


typedef enum _TemperatureDisplayUnits
{
    TEMPERATURE_DISPLAY_UNIT_CELSIUS = 0,
    TEMPERATURE_DISPLAY_UNIT_FAHRENHEIT = 1,
} TemperatureDisplayUnits;

TINY_END_DECLS

#endif /* __TemperatureDisplayUnits_H__ */