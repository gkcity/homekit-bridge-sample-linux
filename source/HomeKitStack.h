/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2013-11-19
*
* @file   HomeKitStack.h
*
* @remark
*
*/

#ifndef __HomeKitStack_H__
#define __HomeKitStack_H__

#include <product/Product.h>

TINY_BEGIN_DECLS


TinyRet StartHomeKit(Product *product, uint16_t *port);

TinyRet StopHomeKit(void);


TINY_END_DECLS

#endif /* __HomeKitStack_H__ */