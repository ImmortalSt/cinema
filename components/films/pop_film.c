#include "pop_film.h"
#include <string.h>
#include <stdlib.h>


struct film pop_film(int wanted_position,int position_right_now,int number_of_filmes)
{
    char str1[len];
    char str2[len];
    char str3[len];
    char str4[len];
    char str5[len];
    FILE *file;
    file=fopen("films.txt","r");
    for(int i=0;i < ((wanted_position + position_right_now) % number_of_filmes);i++)
    {
        fgets(str1, len, file);
        fgets(str2, len, file);
        fgets(str3, len, file);
        fgets(str4, len, file);
        fgets(str5, len, file);
    }

    struct film res;
    strcpy(res.str1, str1);
    strcpy(res.str2, str2);
    strcpy(res.str3, str3);
    strcpy(res.str4, str4);
    strcpy(res.str5, str5);
    return res;
}
