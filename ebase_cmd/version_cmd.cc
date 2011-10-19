#include <stdio.h>

extern const char VER_CMD[] = __VER_CMD__;
extern const char BUILD_CMD[] = __BUILD_CMD__;
extern const char VERSION_CMD[] = __VERSION_CMD__;

void version_cmd()
{
fprintf( stderr, "[Version info for ebase v%s.%s]\n", VER_CMD, BUILD_CMD );
fprintf( stderr, "%s\n", VERSION_CMD );
}

