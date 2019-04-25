/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   AirConditioner_8_Thermostat_doGet.c
*
* @remark
*
*/

#include "AirConditioner_8_Thermostat_doGet.h"
#include <status/HapStatus.h>
#include "../../../definition/airconditioner/AirConditioner_IID.h"
#include "HeatingCoolingState.h"
#include "TemperatureDisplayUnits.h"

/**
 * 格式: JsonValue_NewString
 * 取值: 字符串，没有限制取值范围
 */
static void AirConditioner_9_Name_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("ac");
    o->status = HAP_OK;
    printf("AirConditioner_9_Name_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

/**
 * 格式: JsonValue_NewInteger(整数)　
 * 取值: HeatingCoolingState
 */
static void AirConditioner_10_CurrentHeatingCoolingState_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewInteger(HEATING_COOLING_STATE_HEATING); // 当前状态：制热
    o->status = HAP_OK;
    printf("AirConditioner_10_CurrentHeatingCoolingState_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

/**
 * 格式: JsonValue_NewInteger(整数)　
 * 取值: HeatingCoolingState
 */
static void AirConditioner_11_TargetHeatingCoolingState_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewInteger(HEATING_COOLING_STATE_COOLING); // 目标状态：制冷
    o->status = HAP_OK;
    printf("AirConditioner_11_TargetHeatingCoolingState_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

/**
 * 格式: JsonValue_NewFloat(浮点数)　
 * 取值: 最小值: 0, 最大值: 100, 步长: 0.1
 */
static void AirConditioner_12_CurrentTemperature_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewFloat(28);     // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;
    printf("AirConditioner_12_CurrentTemperature_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

/**
 * 格式: JsonValue_NewFloat(浮点数)　
 * 取值: 最小值: 10, 最大值: 38, 步长: 0.1
 */
static void AirConditioner_13_TargetTemperature_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewInteger(24);     // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;
    printf("AirConditioner_13_TargetTemperature_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

/**
 * 格式: JsonValue_NewInteger(整数)　
 * 取值: TemperatureDisplayUnits
 */
static void AirConditioner_14_TemperatureDisplayUnits_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewInteger(TEMPERATURE_DISPLAY_UNIT_CELSIUS);     // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;
    printf("AirConditioner_14_TemperatureDisplayUnits_doGet: %d\n", (int) o->value->data.number->value.intValue);
}

void AirConditioner_8_Thermostat_doGet(PropertyOperation *o)
{
    printf("AirConditioner_8_Thermostat_doGet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case AirConditioner_IID_9_Name:
            AirConditioner_9_Name_doGet(o);
            break;

        case AirConditioner_IID_10_CurrentHeatingCoolingState:
            AirConditioner_10_CurrentHeatingCoolingState_doGet(o);
            break;

        case AirConditioner_IID_11_TargetHeatingCoolingState:
            AirConditioner_11_TargetHeatingCoolingState_doGet(o);
            break;

        case AirConditioner_IID_12_CurrentTemperature:
            AirConditioner_12_CurrentTemperature_doGet(o);
            break;

        case AirConditioner_IID_13_TargetTemperature:
            AirConditioner_13_TargetTemperature_doGet(o);
            break;

        case AirConditioner_IID_14_TemperatureDisplayUnits:
            AirConditioner_14_TemperatureDisplayUnits_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}