#pragma once

#if defined(LINUX) || defined(UNIX) || defined(_UNIX) || defined(__MINGW32__) || defined(__CYGWIN__)
#define __UNIX_LIKE
#endif

#if defined(WIN32) || defined(_WIN32) || defined(WINDOWS) || defined(WIN64) || defined(_WIN64)
#define __WINDOWS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#ifdef __WINDOWS
#include <windows.h>
#define symbol "\\"
#endif

#ifdef __UNIX_LIKE
#include <sys/stat.h>
#include <unistd.h>
#define symbol "/"
#endif

#include "StringUtil.h"

int getFileList(const char * path, pStringArr pathList);

int findSubStr(pStringArr pathList, pStringArr findList, const char * subStr);