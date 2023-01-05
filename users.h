#include <stdbool.h>

typedef struct accounts{
  char login[21], password[21];
  long int cardNamber;
  int favoritesSize, isAdmin;
}accounts;

accounts createUser(char login[21], char password[21], long int cardNamber);
accounts signIn(char login[21], char password[21]);