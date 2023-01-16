#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>
#include <string.h>
#include <wchar.h>
#include <errno.h>

enum pictures { test, login_empty,                    \
    login_1, login_2, login_3, login_4,               \
    register_1, register_2, register_3,               \
    error, menu, menu_anim                            \
    };  

void print_pictures(enum pictures pic, ...);