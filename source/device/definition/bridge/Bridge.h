/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2018-11-12
 *
 * @file   Bridge.h
 *
 * @remark
 *
 */

#ifndef __Bridge_H__
#define __Bridge_H__

#include <product/Product.h>

TINY_BEGIN_DECLS


Product * Bridge(const char *did, const char *name, const char *ip, const char *setupCode);


TINY_END_DECLS

#endif /* __Bridge_H__ */
