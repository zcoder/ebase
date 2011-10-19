#include <stdio.h>

extern const char VER_LIB[] = __VER_LIB__;
extern const char BUILD_LIB[] = __BUILD_LIB__;
extern const char VERSION_LIB[] = __VERSION_LIB__;

void version_lib()
{
    fprintf( stderr, "[Version info for libebase v%s.%s]\n", VER_LIB, BUILD_LIB);
    fprintf( stderr, "%s\n", VERSION_LIB );
}

