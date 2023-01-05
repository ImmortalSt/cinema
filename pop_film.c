#include <pop_film.h>
#define len 15

int pop_film(int l)
{
    char str1[len];
    char str2[len];
    char str3[len];
    char str4[len];
    char str5[len];
    FILE *fg;
    fg=fopen("films.txt","r");
    for(int i=1;i<=l;i++)
    {
        fgets(str1, len, fg);
        fgets(str2, len, fg);
        fgets(str3, len, fg);
        fgets(str4, len, fg);
        fgets(str5, len, fg);
    }
    fprintf(stdout,"%s",str1);
    fprintf(stdout,"%s",str2);
    fprintf(stdout,"%s",str3);
    fprintf(stdout,"%s",str4);
    fprintf(stdout,"%s",str5);
    return 0;
}