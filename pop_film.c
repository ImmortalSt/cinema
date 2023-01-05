#include <pop_film.h>
#define len 15
 struct film
         {
     char str1[len];
     char str2[len];
     char str3[len];
     char str4[len];
     char str5[len];
};

struct film pop_film(int now,int last)
        {
    char str1[len];
    char str2[len];
    char str3[len];
    char str4[len];
    char str5[len];
    FILE *fg;
    fg=fopen("films.txt","r");
    for(int i=0;i<(last+now)%30;i++)
    {
        fgets(str1, len, fg);
        fgets(str2, len, fg);
        fgets(str3, len, fg);
        fgets(str4, len, fg);
        fgets(str5, len, fg);
    }
    pop_film.str1=str1;
    pop_film.str2=str2;
    pop_film.str3=str3;
    pop_film.str4=str4;
    pop_film.str5=str5;
    return pop_film;
}
