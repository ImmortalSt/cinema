#ifndef C3_C_POP_FILM_H
#define C3_C_POP_FILM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 100

typedef struct film
{
     char name[len];
     char year[len];
     char country[len];
     char ganre[len];
     char range[len];
} film ;

film* get_films();
int films_count();

#endif //C3_C_POP_FILM_H
