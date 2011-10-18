/* 
 * File:   base_lib.h
 * Author: zhenka
 *
 * Created on July 4, 2011, 3:56 PM
 */

#ifndef BASE64LIB_H
#define	BASE64LIB_H

#include "ebase_tables.h"
#include <stdint.h>

int base64_decode_block(const char*, const uint32_t, char*, const uint32_t, const char*);
int base64_encode_block(const char*, const uint32_t, char*, const uint32_t, const char*);

#endif	/* BASE64LIB_H */

