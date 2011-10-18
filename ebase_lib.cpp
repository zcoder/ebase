
#include "base_lib.h"

#include <stdio.h>

using namespace std;
/*
 * Function base64_decode_block   [block for 4 byte]
 * IO:      const char* in                  - input buffer with src_data for decode
 *          const uint32_t in_size          - input buffer size Should be > 0;
 *          char* out                       - output buffer for write decoded data Should be allocated out_size bytes.
 *          const uint32_t out_size         - output buffer size Should be (out_size >= (in_size/3 + bool(in_size % 3)) * 4 
 *          const char* table = table_rfc   - table for decode data
 */
int base64_decode_block(const char* in, const uint32_t in_size, char* out, const uint32_t out_size, const char* table = NULL) {

    register uint32_t in_block = 0;
    register uint32_t out_block = 0;
    register uint32_t out_block1 = 0;
    register uint32_t out_block2 = 0;
    register uint32_t out_block3 = 0;
    register uint32_t out_block4 = 0;
    register uint32_t out_block_check = 0;
    uint32_t in_index = 0;
    uint32_t out_index = 0;
    uint32_t in_block_size = 4;
    uint32_t out_block_size = 3;
    uint32_t in_blocks_count = in_size / in_block_size;
    uint32_t in_blocks_cudr =  in_size % in_block_size;
    bool     flag_null_cudr = ((in_blocks_cudr) && (table['\0'] == 64));

    if ( ((out_size < out_block_size) || (in_size < in_block_size)) && (!flag_null_cudr) ) return 0;
    if ( !table ) table = dtable_rfc;
    if ( flag_null_cudr ) ++in_blocks_count; // inc in_blocks_count because \0 is a terminate string in C. 

    while ( in_blocks_count > 0 ) {
        if ( out_index + out_block_size <= out_size ) {
            if ( in_blocks_count > 1 ) {
                in_block = *((uint32_t*) (in + in_index));
                out_block1 = table[(in_block & 0x000000ff)]; // TODO: optimize
                out_block2 = table[(in_block & 0x0000ff00) >> 8];
                out_block3 = table[(in_block & 0x00ff0000) >> 16];
                out_block4 = table[(in_block & 0xff000000) >> 24];
                out_block_check = ( (out_block1 & 0xc0) >> 6 | (out_block2 & 0xc0) >> 4 | (out_block3 & 0xc0) >> 2 | (out_block4 & 0xc0));
                if ( out_block_check ) return -1; //out_index; // Check for fuck
                out_block  = out_block1  << 18 | out_block2  << 12 | out_block3 << 6  | out_block4; // TODO: optimize
                out_block  = (out_block & 0xff) << 16 | (out_block & 0xff00) | (out_block & 0xff0000) >> 16;
                *(uint32_t*) (out + out_index) = out_block;  // WARN !!! need only 3 byte ! AHTUNG
                out_index += out_block_size;
                in_index += in_block_size;
            }
            else {
                if ( flag_null_cudr ) {
                    if ( 3 == in_blocks_cudr ) {
                        out_block1 = table[*(in + in_index)]; 
                        out_block2 = table[*(in + in_index+1)]; 
                        out_block3 = table[*(in + in_index+2)]; 
                        out_block4 = table[0];
                        in_index += 3;
                        
                    }
                    if ( 2 == in_blocks_cudr ) {
                        out_block1 = table[*(in + in_index)]; 
                        out_block2 = table[*(in + in_index+1)]; 
                        out_block3 = table[0];
                        out_block4 = table[0];
                        in_index += 2;
                    }
                    if ( 1 == in_blocks_cudr ) {
                        out_block1 = table[*(in + in_index)];
                        out_block2 = table[0];
                        out_block3 = table[0];
                        out_block4 = table[0];
                        in_index += 1;
                    }
                }
                else {
                    in_block = *((uint32_t*) (in + in_index));
                    out_block1 = table[(in_block & 0x000000ff)]; // TODO: optimize
                    out_block2 = table[(in_block & 0x0000ff00) >> 8];
                    out_block3 = table[(in_block & 0x00ff0000) >> 16];
                    out_block4 = table[(in_block & 0xff000000) >> 24];
                }

                out_block_check = ( (out_block1 & 0xc0) >> 6 | (out_block2 & 0xc0) >> 4 | (out_block3 & 0xc0) >> 2 | (out_block4 & 0xc0));
                if ( out_block_check ) {
                    if ( out_block_check & 0xAA ) return -1; //out_index; // Check for fuck
                    if ( out_block_check & 0x01 ) return out_index;  // first '='

                    if ( out_block_check == 0x54 ) { // X===
                        // write 1st byte
                        *(out + out_index)      = out_block1 << 2;
                        ++out_index;
                    }

                    if ( out_block_check == 0x50 ) { // XX==
                        *(out + out_index)      = out_block1 << 2 | out_block2 >> 4;
                        ++out_index;
                        //*(out + out_index)      = out_block2 << 4;                     
                    }

                    if ( out_block_check == 0x40 ) { // XXX=
                        *(out + out_index)      = out_block1 << 2 | out_block2 >> 4;
                        *(out + out_index + 1)      = out_block2 << 4 | out_block3 >> 2;
                        out_index += 2;
                        //*(out + out_index)      = out_block3 << 6;                      
                    }
                }
                else {
                    // write all
                    *(out + out_index)          = out_block1 << 2 | out_block2 >> 4;
                    *(out + out_index + 1)        = out_block2 << 4 | out_block3 >> 2;
                    *(out + out_index + 2)        = out_block3 << 6 | out_block4;
                    out_index += out_block_size;
                }
            }
        }
        else {
            return out_index;
        }
        --in_blocks_count;
    }
    return out_index;
}

/*
 * Function base64_encode_block   [block for 4 byte]
 * IO:      const char* in                  - input buffer with src_data for encode
 *          const uint32_t in_size          - input buffer size Should be > 0;
 *          char* out                       - output buffer for write encoded data Should be allocated out_size bytes.
 *          const uint32_t out_size         - output buffer size Should be (out_size >= (in_size/3 + bool(in_size % 3)) * 4 
 *          const char* table = table_rfc   - table for encode data
 */
int base64_encode_block(const char* in, const uint32_t in_size, char* out, const uint32_t out_size, const char* table = NULL) {

    register uint32_t in_block = 0;
    register uint32_t out_block = 0;
    register uint32_t in_index = 0;
    register uint32_t out_index = 0;
    uint32_t in_block_size = 3;
    uint32_t out_block_size = 4;
    uint32_t last_block_size = in_size % in_block_size;
    uint32_t in_blocks_count = in_size / in_block_size;

    if ( out_size < out_block_size || in_size <= 0 ) return 0;
    if ( !table ) table = etable_rfc;

    while ( in_blocks_count-- ) {
        if ( out_index + out_block_size <= out_size ) {
            in_block = *((uint32_t*) (in + in_index));
            out_block = (table[((in_block & 0x00fc) >> 2)]) |  \
                        ((table[((in_block & 0x0003) << 4) | ((in_block & 0x00f000) >> 12)]) << 8) | \
                        ((table[((in_block & 0x0f00) >> 6) | ((in_block & 0xc00000) >> 22)]) << 16) | \
                        ((table[((in_block & 0x3f0000) >> 16)]) << 24);
            *(uint32_t*) (out + out_index) = out_block;
            out_index += out_block_size;
            in_index += in_block_size;
        }
        else {
            return out_index;
        }
    }
    if ( last_block_size && (out_index + out_block_size <= out_size) ) {

        if ( 2 == last_block_size ) {
            in_block = *((uint16_t*) (in + in_index));
            out_block = out_block = (table[((in_block & 0x00fc) >> 2)]) |  \
                    ((table[((in_block & 0x0003) << 4) | ((in_block & 0x00f000) >> 12)]) << 8) | \
                    ((table[((in_block & 0x0f00) >> 6)]) << 16) | \
                    ((table[64]) << 24);
        }
        else { /* char */
            in_block = *(in + in_index);
            out_block = out_block = (table[((in_block & 0x00fc) >> 2)]) |  \
                    ((table[((in_block & 0x0003) << 4)]) << 8) | \
                    ((table[64]) << 16) | \
                    ((table[64]) << 24);
        }

        *(uint32_t*) (out + out_index) = out_block;
        out_index += out_block_size;
    }
    return out_index;
}
