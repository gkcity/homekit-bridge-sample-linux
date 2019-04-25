/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   AirConditioner_8_Thermostat_doSet.c
*
* @remark
*
*/

#include "AirConditioner_8_Thermostat_doSet.h"
#include <status/HapStatus.h>
#include "../../../definition/airconditioner/AirConditioner_IID.h"
#include "HeatingCoolingState.h"
#include "TemperatureDisplayUnits.h"

/**
 * 值: o->value->data.number->value.intValue;
 * 取值: HeatingCoolingState
 */
static void AirConditioner_11_TargetHeatingCoolingState_doSet(PropertyOperation *o)
{
    o->status = HAP_OK;
    printf("AirConditioner_11_TargetHeatingCoolingState_doSet: %d\n", (int) o->value->data.number->value.intValue);

    switch (o->value->data.number->value.intValue)
    {
        case HEATING_COOLING_STATE_INACTIVE:
            // TODO: 关闭空调
            break;

        case HEATING_COOLING_STATE_IDLE:
            // TODO: 空闲状态？
            break;

        case HEATING_COOLING_STATE_HEATING:
            // TODO: 制热
            break;

        case HEATING_COOLING_STATE_COOLING:
            // TODO: 制冷
            break;

        default:
            o->status = HAP_INVALID_VALUE;
            break;
    }
}

/**
 * 值: o->value->data.number->value.floatValue;
 * 取值: 最小值: 10, 最大值: 38, 步长: 0.1
 */
static void AirConditioner_13_TargetTemperature_doSet(PropertyOperation *o)
{
    // TODO: 执行写操作
    o->status = HAP_OK;
    printf("AirConditioner_13_TargetTemperature_doSet: %d\n", (int) o->value->data.number->value.floatValue);
}

/**
 * 值: o->value->data.number->value.intValue;
 * 取值: TemperatureDisplayUnits
 */
static void AirConditioner_14_TemperatureDisplayUnits_doSet(PropertyOperation *o)
{
    o->status = HAP_OK;

    printf("AirConditioner_14_TemperatureDisplayUnits_doSet: %d\n", (int) o->value->data.number->value.intValue);

    switch (o->value->data.number->value.intValue)
    {
        case TEMPERATURE_DISPLAY_UNIT_CELSIUS:
            // TODO: 温度显示单位：摄氏度
            break;

        case TEMPERATURE_DISPLAY_UNIT_FAHRENHEIT:
            // TODO: 温度显示单位：华氏度
            break;

        default:
            o->status = HAP_INVALID_VALUE;
            break;
    }
}

void AirConditioner_8_Thermostat_doSet(PropertyOperation *o)
{
    printf("AirConditioner_8_Thermostat_doSet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case AirConditioner_IID_9_Name:
            o->status = HAP_CANNOT_WRITE;
            break;

        case AirConditioner_IID_10_CurrentHeatingCoolingState:
            o->status = HAP_CANNOT_WRITE;
            break;

        case AirConditioner_IID_11_TargetHeatingCoolingState:
            AirConditioner_11_TargetHeatingCoolingState_doSet(o);
            break;

        case AirConditioner_IID_12_CurrentTemperature:
            o->status = HAP_CANNOT_WRITE;
            break;

        case AirConditioner_IID_13_TargetTemperature:
            AirConditioner_13_TargetTemperature_doSet(o);
            break;

        case AirConditioner_IID_14_TemperatureDisplayUnits:
            AirConditioner_14_TemperatureDisplayUnits_doSet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}