#include "scena.h"

#define BACKSPACE_CODE 127

accounts login_scena() {
    enum pictures pic[] = {login_1, login_2, login_3, login_4};

    char login[1000] = {0};
    char password[1000] = {0};
    memset(login, 0, 1000);
    memset(password, 0, 1000);

    int pic_current_state = 0;
    char button[] = "\0\0";
    while (1) {
        print_pictures(pic[pic_current_state], login, password);
        button[0] = _getchar();

        if ((button[0] < 33 || button[0] > 127) && button[0] != '\t' && button[0] != '\r') continue;

        if(button[0] == '\t') {
            pic_current_state = (pic_current_state + 1) % 4;
        
        } else if(pic_current_state == 0) {

            if (button[0] == BACKSPACE_CODE) {
                login[strlen(login) - 1] = 0;
            } else if (strlen(login) <= 55) strcat(login, button);

        } else if(pic_current_state == 1) {

            if (button[0] == BACKSPACE_CODE) {
                password[strlen(password) - 1] = 0;
            } else if (strlen(password) <= 55) strcat(password, button);
        
        } else if (pic_current_state == 2)
        {   
            if(button[0] == '\r')
                return register_scena(login, password);
        } else if (pic_current_state == 3)
        {
            if(button[0] == '\r')
                return signIn(login, password);
        }
    }
}


accounts register_scena() {
    char login[1000];
    char password[1000];
    memset(login, 0, 1000);
    memset(password, 0, 1000);

    enum pictures pic[] = {register_1, register_2, register_3};

    int pic_current_state = 0;
    char button[] = "\0\0";
    while (1) {
        print_pictures(pic[pic_current_state], login, password);
        button[0] = _getchar();

        if ((button[0] < 33 || button[0] > 127) && button[0] != '\t' && button[0] != '\r') continue;


        if(button[0] == '\t') {

            pic_current_state = (pic_current_state + 1) % 3;
        
        } else if(pic_current_state == 0) {

            if (button[0] == BACKSPACE_CODE) {
                login[strlen(login) - 1] = 0;
            } else if (strlen(login) <= 55) strcat(login, button);

        } else if(pic_current_state == 1) {

            if (button[0] == BACKSPACE_CODE) {
                password[strlen(password) - 1] = 0;
            } else if (strlen(password) <= 55) strcat(password, button);

        } else if (pic_current_state == 2 && button[0] == '\r') {
            accounts user = createUser(login, password);
            return user;
        }
    }

}

void menu_scena(accounts user){
    film* films = get_films();
    int current_pos = 500;
    char button[] = "\0\0";
    while (1) {
        int count = films_count();
        film film_1 = films[current_pos % count];

        film film_2 = films[(current_pos - 1) % count];
        film film_3 = films[(current_pos + 1) % count];
        print_pictures(menu, user.login, film_1.name, film_1.year, film_1.country, film_1.ganre, film_1.range, \
                             film_2.name, film_2.year, film_2.country, film_2.ganre, film_2.range, \
                             film_3.name, film_3.year, film_3.country, film_3.ganre, film_3.range\
        );
        button[0] = _getchar();
        if (button[0] == 'a') {
            print_pictures(Left anim);
            usleep(200000);
            print_pictures(menu_anim);
            usleep(200000);
            print_pictures(Right anim);
            usleep(200000);
            
            current_pos--;
        } else if (button[0] == 'd')
        {
            print_pictures(Right anim);
            usleep(200000);
            print_pictures(menu_anim);
            usleep(200000);
            print_pictures(Left anim);
            usleep(200000);

            current_pos++;
        }
        
    }
}
