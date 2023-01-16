#include <stdbool.h>

typedef struct accounts{
  char login[21], password[21];
  long int id;
  int favoritesSize, isAdmin;
}accounts;

accounts createUser(char login[21], char password[21]);
accounts signIn(char login[21], char password[21]);
void pop_film(accounts *user, char *filmName); // перед названием переменной пользователя необходимо написаит <&> --> pop_film(&user, "фильм");
