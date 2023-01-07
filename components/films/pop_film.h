#ifndef C3_C_POP_FILM_H
#define C3_C_POP_FILM_H

#include <stdio.h>


#define len 100

struct film
{
     char name[len];
     char year[len];
     char country[len];
     char ganre[len];
     char range[len];
};

struct film pop_film(int wanted_position,int position_right_now,int number_of_filmes);

#endif //C3_C_POP_FILM_H
