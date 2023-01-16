#include "pop_film.h"

film* get_films(){
    film* result = malloc(sizeof(film) * 100);
    memset(result, 0, sizeof(film) * 100);

    FILE* file = fopen("components/films/films.txt", "r");

    for (int i = 0; !feof(file); i++) {

        film item;
        char trash;
        fscanf(file, "%[^\n]s", (char*)&item.name);
        fscanf(file, "%c", &trash);
        fscanf(file, "%[^\n]s", (char*)&item.year);
        fscanf(file, "%c", &trash);
        fscanf(file, "%[^\n]s", (char*)&item.country);
        fscanf(file, "%c", &trash);
        fscanf(file, "%[^\n]s", (char*)&item.ganre);
        fscanf(file, "%c", &trash);
        fscanf(file, "%[^\n]s", (char*)&item.range);
        fscanf(file, "%c", &trash);

        result[i] = item;
    }

    return result;
}

int films_count() {
    film* films = get_films();
    int result = 0;
    while (films[result].name[0] != '\0') result++;
    return result;
}