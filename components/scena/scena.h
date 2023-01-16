#include "../users/users.h"
#include "display/display.h"
#include "../../libs/getchar/getchar.h"
#include "../films/pop_film.h"
#include <stdlib.h>
#include <stdio.h>


#if defined(__linux)
    #include <unistd.h>
#else
    #include <windows.h>
#endif

accounts login_scena();

accounts register_scena();

void menu_scena(accounts user);