/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   HomeKitStack.c
 *
 * @remark
 *
 */

#include <tiny_malloc.h>
#include <tiny_log.h>
#include <IotLauncher.h>
#include <HapServerRuntime.h>
#include <TinyThread.h>
#include "HomeKitStack.h"
#include "persistence/HapPersistenceImpl.h"

#define TAG "HomeKitStack"

static TinyThread *_thread = NULL;

static void _loop(void *param)
{
    TinyRet ret = IotLauncher_Run((IotLauncher *) param);
    if (RET_FAILED(ret))
    {
        LOG_D(TAG, "IotLauncher_Run FAILED: %d", ret);
    }
}

TinyRet StartHomeKit(Product *product, uint16_t *port)
{
    TinyRet ret = TINY_RET_OK;
    IotLauncher *launcher = NULL;

    do
    {
        if (_thread != NULL)
        {
            ret = TINY_RET_E_STARTED;
            break;
        }

        _thread = TinyThread_New();
        if (_thread == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        IotRuntime *runtime = HapServerRuntime_New(HapPersistenceImpl_GetInstance());
        if (runtime == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        launcher = IotLauncher_NewRuntime(product, runtime, NULL, NULL, NULL);
        if (launcher == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyThread_Initialize(_thread, _loop, launcher, "stack");
        if (RET_FAILED(ret))
        {
            IotLauncher_Delete(launcher);
            break;
        }

        if (! TinyThread_Start(_thread))
        {
            ret = TINY_RET_E_INTERNAL;
            break;
        }
    } while (false);

    return ret;
}

TinyRet StopHomeKit(void)
{
    TinyRet ret = TINY_RET_OK;

    do
    {
        if (_thread == NULL)
        {
            ret = TINY_RET_E_STOPPED;
            break;
        }

        if (_thread->status != ThreadRunning)
        {
            ret = TINY_RET_E_STATUS;
            break;
        }

        ret = IotLauncher_Stop((IotLauncher *) (_thread->thread_param));
        if (RET_FAILED(ret))
        {
            break;
        }

        if (!TinyThread_Join(_thread))
        {
            ret = TINY_RET_E_INTERNAL;
        }
    } while (false);

    return ret;
}