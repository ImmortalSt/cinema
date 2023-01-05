#include <pop_film.h>
#define len 100
 struct film
         {
     char str1[len];
     char str2[len];
     char str3[len];
     char str4[len];
     char str5[len];
};

struct film pop_film(int wanted_position,int position_right_now,int number_of_filmes)
        {
    char str1[len];
    char str2[len];
    char str3[len];
    char str4[len];
    char str5[len];
    FILE *file;
    file=fopen("films.txt","r");
    for(int i=0;i<((wanted_position + position_right_now) % number_of_filmes);i++)
    {
        fgets(str1, len, file);
        fgets(str2, len, file);
        fgets(str3, len, file);
        fgets(str4, len, file);
        fgets(str5, len, file);
    }
    pop_film.str1=str1;
    pop_film.str2=str2;
    pop_film.str3=str3;
    pop_film.str4=str4;
    pop_film.str5=str5;
    return pop_film;
}
