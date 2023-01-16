#include <stdio.h>
#include <locale.h>
#include "components/scena/scena.h"

int main() {
    setlocale(LC_ALL, "");
    


    account user;
    while(1) {
        user = login_scena();
        if (user.isAdmin == -1) {
            print_pictures(error);
            sleep(1);
        } else {
            break;
        }
    }

    menu_scena(user);


}
