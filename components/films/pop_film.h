#ifndef C3_C_POP_FILM_H
#define C3_C_POP_FILM_H

#include <stdio.h>


#define len 100

struct film
{
     char str1[len];
     char str2[len];
     char str3[len];
     char str4[len];
     char str5[len];
};

struct film pop_film(int wanted_position,int position_right_now,int number_of_filmes);

#endif //C3_C_POP_FILM_H
