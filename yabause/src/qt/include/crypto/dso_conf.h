/*
 * Copyright 2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_DSO_CONF_H
# define HEADER_DSO_CONF_H
# define DSO_EXTENSION ".dll"
/* #undef DSO_NONE */
#define DSO_WIN32
/* #undef DSO_DLFCN */
#define HAVE_DLFCN_H
#endif
