/* 
 * File:   ebase_cmd.cpp
 * Author: zhenka
 *
 * Created on July 4, 2011, 3:48 PM
 * Refactoring on October 18, 2011, 17:48 MSK
 */

#include "../ebase_lib/ebase_lib.h"
#include "../ebase_lib/ebase_tables.h"
#include "../ebase_lib/version_lib.h"
#include "version_cmd.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <getopt.h>

using namespace std;

/**
 * base64 called from base64_main with files for read;
 * @param decode = if true then decode, else encode
 * @param in_filename 
 * @param out_filename
 * @param table  etable_* or dtable_*
 * @return  count of write bytes
 */
int base64(bool decode = false, const char *in_filename = NULL, const char* out_filename = NULL, const char* table = NULL ) {

    const int max_buf_size = 5460;
    int in_buf_size; // = 4095;
    int out_buf_size; // = 5460;
    int (*enc_dec_func)(const char*, const uint32_t, char*, const uint32_t, const char*) ; // = ;

    if ( !decode ) {
        in_buf_size = 4095;
        out_buf_size = 5460;
        enc_dec_func = base64_encode_block;
        if ( !table ) table = etable_rfc;
    }
    else {
        in_buf_size = 4096;
        out_buf_size = 3072;
        enc_dec_func = base64_decode_block;
        if ( !table ) table = dtable_rfc;
    }

    static char in_buf[max_buf_size], out_buf[max_buf_size];

    int _fd_in = 0;
    int _fd_out = 0;

    ssize_t size_in = 0;
    ssize_t size_in_read = 0;
    ssize_t size_read_total = 0;
    ssize_t size_enc_dec_block = 0;
    ssize_t size_out_write = 0;
    ssize_t size_out_write_total = 0;
    ssize_t size_in_block = 0;

    if ( !in_filename ) {
        in_filename = "/dev/stdin";
    }
    _fd_in = open( in_filename , O_RDONLY );
    if ( _fd_in < 0 ) {
        perror( in_filename );
        return 0;
    }

    if ( !out_filename ) {
        out_filename = "/dev/stdout";
    }
    _fd_out = open( out_filename , O_WRONLY | O_TRUNC | O_CREAT, 0664	);
    if ( _fd_out < 0 ) {
        perror( out_filename );
        return 0;
    }

    do {
        size_read_total = 0;
        while ( size_read_total < in_buf_size ) {
            size_in_read = read( _fd_in, in_buf + size_read_total, in_buf_size - size_read_total );
            if ( 0 > size_in_read ) {
                perror( in_filename );
                return -1;
            }
            if ( 0 == size_in_read ) {
                break;
            }
            size_read_total += size_in_read;
        }
        if ( size_read_total ) {
            size_enc_dec_block = enc_dec_func( in_buf, size_read_total, out_buf, out_buf_size, table );
            if ( -1 == size_enc_dec_block || 0 == size_enc_dec_block ) break;

            size_out_write = write( _fd_out, out_buf, size_enc_dec_block );
            size_out_write_total += size_out_write;
            if ( size_out_write != size_enc_dec_block ) {
                perror( out_filename );
                break;
            }
        }
    }
    while ( size_in_read );

    close( _fd_in );
    close( _fd_out );
    if  ( -1 == size_enc_dec_block ) return -1;
    return size_out_write_total;
}

int help( int argc, char** argv ) 
{
        fprintf( stderr, "eBase (enhanced Base tool) v%s.%s \n\n", VER_CMD, BUILD_CMD);
        fprintf( stderr, " Usage: %s \n", argv[0] );
        fprintf( stderr, "        %s [-e|-d] -i[INPUT_FILE] -o[OUTPUT_FILE] -t[TABLE_NAME]\n", argv[0] );
        fprintf( stderr, "        %s [--encode|--decode] --input=[INPUT_FILE] --output=[OUTPUT_FILE] --table=[TABLE_NAME]\n", argv[0] );
        fprintf( stderr, "        %s [-e|-d] [INPUT_FILE] [OUTPUT_FILE] [TABLE_NAME]\n", argv[0] );
        fprintf( stderr, " Base64 encode or decode INPUT_FILE, or standart input, to OUTPUT_FILE or standart output with TABLE_NAME or rfc base64 table\n\n" );
        fprintf( stderr, " \t-e|--encode           encode data (-e is *default)\n" );
        fprintf( stderr, " \t-d|--decode           decode data\n" );
        fprintf( stderr, " \t-i|--input=           input file (stdin is *default)\n" );
        fprintf( stderr, " \t-o|--output=          output file (stdout is *default)\n" );
        fprintf( stderr, " \t-t|--table=           ebase64 table may be [rfc|url|xmlt|xmli]  (rfc is *default)\n\n" );
        fprintf( stderr, " \t-h|--help             display this help and exit\n" );
        fprintf( stderr, " \n" );
        fprintf( stderr, " You may combine any rational parameter for usage, but count of params without opts [-i|-o|-t] may be less 4.\n"\
                         " The data are encoded as described for the base64 alphabet in RFC 3548 or other [TABLE_NAME].\n"\
                         " When decoding, the input may contain newlines in addition to the bytes of the formal base64 alphabet.\n" );
        fprintf( stderr, "\n" );
        for (int i=0; NULL != b64_tables[i].table_name; i++) {
            fprintf( stderr, " table [%s] is [%s]\n", b64_tables[i].table_name, b64_tables[i].etable_ptr );
        }
        fprintf( stderr, "\n" );
}


//#define DEBUG
/*
 * base64_main(int argc, char** argv) called from term
 */
int main_cmd(int argc, char** argv) {

    int do_decode   = 0;
    int do_encode   = 0;
    int do_help     = 0;
    int do_version_cmd = 0;
    int do_version_lib = 0;
    int do_if_name  = 0;
    int do_of_name  = 0;
    int do_tab_name = 0;
    int getop       = 0;
    char *if_name   = NULL;
    char *of_name   = NULL;
    char *table_name = NULL;
    const char *table = NULL;
    struct option longopts[] = {
        { "encode", no_argument,        &do_encode, 'e' },
        { "decode", no_argument,        &do_decode, 'd'},
        { "input",  required_argument,  NULL, 'i'},
        { "output", required_argument,  NULL, 'o'},
        { "table",  required_argument,  NULL, 't'},
        { "help",   no_argument,        &do_help,   'h' },
        { "version",no_argument,        &do_version_cmd,   'v' },
        { "libversion",no_argument,     &do_version_lib,   'l' },
        { 0,        0,                  0,          0}
    };

    while ( (getop = getopt_long( argc, argv, "-:edhvli:o:t:W;", longopts, NULL )) != -1 ) {

        switch ( getop ) {
            case 'e':
                do_encode = 1;
#ifdef DEBUG_OPT
                fprintf( stderr, "e_%c\n", getop);
#endif
                break;
            case 'd':
                do_decode = 1;
#ifdef DEBUG_OPT
                fprintf( stderr, "d_%c\n", getop);
#endif
                break;
            case 'h':
                do_help = 1;
#ifdef DEBUG_OPT
                fprintf( stderr, "h_%c\n", getop);
#endif
                break;
            case 'v':
                do_version_cmd = 1;
#ifdef DEBUG_OPT
                fprintf( stderr, "v_%c\n", getop);
#endif
                break;
            case 'l':
                do_version_lib = 1;
#ifdef DEBUG_OPT
                fprintf( stderr, "l_%c\n", getop);
#endif
                break;
            case 'i':
                ++do_if_name;
                if_name = optarg;
#ifdef DEBUG_OPT
                fprintf( stderr, "i_%c___%s\n", getop, if_name);
#endif
                break;
            case 'o':
                ++do_of_name;
                of_name = optarg;
#ifdef DEBUG_OPT
                fprintf( stderr, "o_%c___%s\n", getop, of_name);
#endif
                break;
            case 't':
                ++do_tab_name;
                table_name = optarg;
#ifdef DEBUG_OPT
                fprintf( stderr, "t_%c___%s\n", getop, table_name);
#endif
                break;
            case 0: // getopt_long set var
#ifdef DEBUG_OPT
                fprintf( stderr,"%s_%s_%s\n", ((do_encode) ? "[do_encode]" : "!do_encode"), ((do_decode) ? "[do_decode]" : "!do_decode"), ((do_help) ? "[do_help]" : "!do_help"));
#endif
                break;
            case 1:
#ifdef DEBUG_OPT
                fprintf( stderr, "case 1:__%d___%s\n", optopt, optarg);
#endif
                if ( !do_if_name && NULL != optarg ) {
                    ++do_if_name;
                    if_name = optarg;
                    break;
                }
                if ( !do_of_name && NULL != optarg ) {
                    ++do_of_name;
                    of_name = optarg;
                    break;
                }
                if ( !do_tab_name && NULL != optarg ) {
                    ++do_tab_name;
                    table_name = optarg;
                    break;
                }
                fprintf( stderr, "%s: option `-%c`:\"%s\" is invalid: ignored\n", argv[0], optopt, optarg );

                break;
            case ':': // no requred arg for opt
                fprintf( stderr, "%s: option `-%c` requires an argument\n", argv[0], optopt );
                break;
            case '?':
            default: // inalid option
                fprintf( stderr, "%s: option `-%c` is invalid: ignored\n", argv[0], optopt );
                break;
        }
    }

    if ( !do_decode && !do_encode ) do_encode = 1;
#ifdef DEBUG_OPT
    fprintf( stderr,"%s_%s_%s\n", ((do_encode) ? "[do_encode]" : "!do_encode"), ((do_decode) ? "[do_decode]" : "!do_decode"), ((do_help) ? "[do_help]" : "!do_help"));
    fprintf( stderr,"input=%s\toutput=%s\ttable=%s\n", if_name, of_name, table_name );
#endif

    if ( do_help ) {
        help(argc,argv);
    }
    
    if ( do_version_cmd ) 
    {
        version_cmd();
    }

    if ( do_version_lib )
    {
        version_lib();
    }
    
    if (do_help || do_version_cmd || do_version_lib) 
    {
        return 0;
    }
    
    if ( do_tab_name && NULL != table_name ) {
        for (int i=0; NULL != b64_tables[i].table_name; i++){
            if (!strncasecmp( table_name ,b64_tables[i].table_name, 4)) {
                if (do_decode) table = b64_tables[i].dtable_ptr;
                if (do_encode) table = b64_tables[i].etable_ptr;
                break;
            }
        }
    }

#ifdef DEBUG_OPT
    fprintf( stderr, "selected table %s\n", table);
#endif

    if ( do_encode || do_decode ) {
#ifdef DEBUG_OPT
        fprintf( stderr,"do: %s %s %s %s\n", ((!do_encode || do_decode) ? "decode " : "encode "), ((do_if_name) ? if_name : "/dev/stdin"), ((do_of_name) ? of_name : "/dev/stdout"), ((do_tab_name) ? table_name : "rfc"));
#endif
        //return 0;
        return base64( !do_encode && do_decode, if_name, of_name, table ); // b64
    }

    fprintf( stderr, "%s: invalid input\n", argv[0] );
    return -1;
}
