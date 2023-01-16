#include "getchar.h"

#if defined(_WIN32) || defined(__CYGWIN__)
    #include <conio.h>
#elif defined(__linux__)
    #include <stdio.h>
    #include <stdlib.h>
#else
    #error Unknown environment!
#endif



char _getchar() {
    char result = 0;
    #if defined(_WIN64) || defined(__CYGWIN__) || defined(_WIN32)
        result = _getch();
    #elif defined(__linux__)
        system("/bin/stty raw");
        result = getchar();
        system("/bin/stty cooked");
    #endif
    return result;
}