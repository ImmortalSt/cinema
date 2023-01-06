#include "display.h"

const int WIDTH = 128;
const int HEIGHT = 30;

const char* PicturesToFile[] = {"Test.txt"};

void print_file(const char* file_name) {
    char path[100] = "components/display/pictures/";
    strcat(path, file_name);
    FILE* file = fopen(path, "r");

    system("clear");

    while (!feof(file)) {
        char* buffer = malloc(WIDTH);
        fgets(buffer, WIDTH, file);
        

        printf("%s", buffer);
    }
}

void print_pictures(enum pictures pic){

    print_file(PicturesToFile[pic]);
}
