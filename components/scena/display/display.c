#include "display.h"

const int WIDTH = 128;
const int HEIGHT = 30;

typedef struct field
{
    int heigh;
    int width;
    int size;
} field;

typedef struct screen {
    field* fields;
    int fields_count;
    char* path;
} screen;


field fields_login[] = {{15, 28, 56}, {20, 28, 56}};
field fields_register[] = {{15, 28, 56}, {20, 28, 56}};
field fields_menu[] = {{2, 13, 49},                                     \
    {6, 51, 30}, {9, 29, 30}, {12, 51, 30}, {15, 29, 30}, {18, 51, 30},    \
    {9, 17, 22}, {11, 17, 22}, {13, 17, 22}, {15, 17, 22}, {17, 17, 22},   \
    {9, 89, 22}, {11, 89, 22}, {13, 89, 22}, {15, 89, 22}, {17, 89, 22}
    };
screen screens[] = {   
    {0, 0, "Test.txt"},
    {fields_login, 2, "login/Login_Board.txt"}, 
    {fields_login, 2, "login/Login_Board_1.txt"},
    {fields_login, 2, "login/Login_Board_2.txt"},
    {fields_login, 2, "login/Login_Board_3.txt"},
    {fields_login, 2, "login/Login_Board_4.txt"},
    {fields_register, 2, "register/Register_Board_1.txt"},
    {fields_register, 2, "register/Register_Board_2.txt"},
    {fields_register, 2, "register/Register_Board_3.txt"},
    {0, 0, "error.txt"},
    {fields_menu, 16, "menu/menu.txt"},
    {0, 0, "menu/menu_anim.txt"}

};                      


wchar_t** get_file(const char* file_name) {
    char path[100] = "components/scena/display/pictures/";
    strcat(path, file_name);
    FILE* file = fopen(path, "r");
    
    system("clear");

    wchar_t** strings = malloc(sizeof(wchar_t*) * HEIGHT);
    for (int i = 0; feof(file) == 0; i++) {
        wchar_t* buffer = malloc(sizeof(wchar_t) * WIDTH);
        memset(buffer, 0, sizeof(wchar_t) * WIDTH);
        fgetws(buffer, WIDTH, file);
        strings[i] = buffer;
    }
    return strings;
}

void print_pictures(enum pictures pic, ...){
    va_list va_args;
    va_start(va_args, pic);
 
    char** args_function = (char**)malloc(sizeof(char*) * 20);
    for (int i = 0; i < 20; i++) {
        args_function[i] = va_arg(va_args, char*);
    }

    va_end(va_args);

    screen _screen = screens[pic];

    wchar_t** strings = get_file(_screen.path);

    for (int i = 0; i < _screen.fields_count; i++) {
        wchar_t* field_text = malloc((strlen(args_function[i]) + 2 ) * sizeof(wchar_t));
        field _field = _screen.fields[i];
        wchar_t* string = strings[_field.heigh];
        wchar_t* buffer = malloc(sizeof(wchar_t) * WIDTH);
        memset(buffer, 0, sizeof(wchar_t) * WIDTH);

        memmove(buffer, string, sizeof(wchar_t) * (_field.width - 2));
        

        memset(field_text, 0, (strlen(args_function[i]) + 2 ) * sizeof(wchar_t));
        mbstowcs (field_text, args_function[i], strlen(args_function[i]) >= _field.size ? _field.size : strlen(args_function[i]));

        wcscat(buffer, field_text);   
        
        wchar_t* space = L" ";
        for (int j = 0; j < _field.size - wcslen(field_text); j++) {
            wcscat(buffer, space);
        }
        
        wcscat(buffer, string + _field.width - 2);

        strings[_field.heigh] = buffer;
    }


    #if defined(__linux__)
        system("/bin/stty cooked");
    #endif

    for (int i = 0; i < HEIGHT; i++){
        wchar_t* a = strings[i];
        wprintf(L"%ls", a);
    }
    wprintf(L"\n");
}