#include <stdbool.h>

typedef struct account{
  char login[21], password[21];
  long int id;
  int favoritesSize, isAdmin;
}account;

account createUser(char login[21], char password[21]);
account signIn(char login[21], char password[21]);