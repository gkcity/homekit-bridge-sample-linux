/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2018-11-12
*
* @file   S_1_AccessoryInformation_doGet.c
*
* @remark
*
*/

#include "S_1_AccessoryInformation_doGet.h"
#include "../../../definition/lightbulb/LightbulbIID.h"
#include <status/HapStatus.h>

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_3_Manufacturer_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("tinyhap"); // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;

    printf("P_3_Manufacturer_doGet: %s\n", o->value->data.string->value);
}

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_4_Model_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("2018"); // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;

    printf("P_4_Model_doGet: %s\n", o->value->data.string->value);
}

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_5_Name_doGet(PropertyOperation *o)
{
    // 必须和Bonjour里发布的name保持一致
    o->value = JsonValue_NewString("demo"); // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;

    printf("P_5_Name_doGet: %s\n", o->value->data.string->value);
}

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_6_SerialNumber_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("20181120"); // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;

    printf("P_6_SerialNumber_doGet: %s\n", o->value->data.string->value);
}

/**
 * 格式: JsonValue_NewString(字符串)　
 * 取值: 字符串，没有限制取值范围
 */
static void P_7_FirmwareRevision_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("1.0.0"); // TODO: 这里需要读到属性真正的值
    o->status = HAP_OK;

    printf("P_7_FirmwareRevision_doGet: %s\n", o->value->data.string->value);
}

void S_1_AccessoryInformation_doGet(PropertyOperation *o)
{
    printf("S_1_AccessoryInformation_doGet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case Lightbulb_IID_3_Manufacturer:
            P_3_Manufacturer_doGet(o);
            break;

        case Lightbulb_IID_4_Model:
            P_4_Model_doGet(o);
            break;

        case Lightbulb_IID_5_Name:
            P_5_Name_doGet(o);
            break;

        case Lightbulb_IID_6_SerialNumber:
            P_6_SerialNumber_doGet(o);
            break;

        case Lightbulb_IID_7_FirmwareRevision:
            P_7_FirmwareRevision_doGet(o);
            break;

        default:
            o->status = HAP_OUT_OF_RESOURCES;
            break;
    }
}