#pragma once
#ifndef WW_TYPE__H
#define WW_TYPE__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;

#define ww_debug(...) printf("%s:%d:",__FUNCTION__,__LINE__);printf(__VA_ARGS__);fflush(stdout);//win32

#endif // !WW_TYPE__H

