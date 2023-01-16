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

account login_scena();

account register_scena();

void menu_scena(account user);