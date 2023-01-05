#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct accounts{
  char login[21], password[21];
  long int cardNamber;
  int favoritesSize, isAdmin;
}accounts;

bool checkLogin(char login[21]){
  bool flag;
  if (strlen(login)==0) flag = false;
  else if ((strlen(login)<3)||(strlen(login)>20)){
    flag = false;
  }
  else{
    flag = true;
    char name[20] = "1";
    FILE *users = fopen("users.txt", "r");
    while (fgets(name,21,users) != NULL){
      name[strlen(name)-1] = 0;
      if (strcmp(login,name) ==  0){
        flag = false;
        break;
      }
    }
    fclose(users);
  }
  return flag;
}

bool checkPossword(char password[21]){
  bool flag;
  if (strlen(password)==0) flag = false;
  else if ((strlen(password)<3)||(strlen(password)>20)){
    flag = false;
  }
  else{
    // Не ебу, как это оптимизировать, поэтому ловите милион else if
    if (strchr(password, '0')!=NULL) flag = true;
    else if (strchr(password, '1')!=NULL) flag = true;
    else if (strchr(password, '2')!=NULL) flag = true;
    else if (strchr(password, '3')!=NULL) flag = true;
    else if (strchr(password, '4')!=NULL) flag = true;
    else if (strchr(password, '5')!=NULL) flag = true;
    else if (strchr(password, '6')!=NULL) flag = true;
    else if (strchr(password, '7')!=NULL) flag = true;
    else if (strchr(password, '8')!=NULL) flag = true;
    else if (strchr(password, '9')!=NULL) flag = true;
    if (flag){
      if (strchr(password, 'q')!=NULL) flag = true;
      else if (strchr(password, 'w')!=NULL) flag = true;
      else if (strchr(password, 'e')!=NULL) flag = true;
      else if (strchr(password, 'r')!=NULL) flag = true;
      else if (strchr(password, 't')!=NULL) flag = true;
      else if (strchr(password, 'y')!=NULL) flag = true;
      else if (strchr(password, 'u')!=NULL) flag = true;
      else if (strchr(password, 'i')!=NULL) flag = true;
      else if (strchr(password, 'o')!=NULL) flag = true;
      else if (strchr(password, 'p')!=NULL) flag = true;
      else if (strchr(password, 'a')!=NULL) flag = true;
      else if (strchr(password, 's')!=NULL) flag = true;
      else if (strchr(password, 'd')!=NULL) flag = true;
      else if (strchr(password, 'f')!=NULL) flag = true;
      else if (strchr(password, 'g')!=NULL) flag = true;
      else if (strchr(password, 'h')!=NULL) flag = true;
      else if (strchr(password, 'j')!=NULL) flag = true;
      else if (strchr(password, 'k')!=NULL) flag = true;
      else if (strchr(password, 'l')!=NULL) flag = true;
      else if (strchr(password, 'z')!=NULL) flag = true;
      else if (strchr(password, 'x')!=NULL) flag = true;
      else if (strchr(password, 'c')!=NULL) flag = true;
      else if (strchr(password, 'v')!=NULL) flag = true;
      else if (strchr(password, 'b')!=NULL) flag = true;
      else if (strchr(password, 'n')!=NULL) flag = true;
      else if (strchr(password, 'm')!=NULL) flag = true;
      else{

        flag = false;
      }
    }
    if (flag){
      if (strchr(password, 'Q')!=NULL) flag = true;
      else if (strchr(password, 'W')!=NULL) flag = true;
      else if (strchr(password, 'E')!=NULL) flag = true;
      else if (strchr(password, 'R')!=NULL) flag = true;
      else if (strchr(password, 'T')!=NULL) flag = true;
      else if (strchr(password, 'Y')!=NULL) flag = true;
      else if (strchr(password, 'U')!=NULL) flag = true;
      else if (strchr(password, 'I')!=NULL) flag = true;
      else if (strchr(password, 'O')!=NULL) flag = true;
      else if (strchr(password, 'P')!=NULL) flag = true;
      else if (strchr(password, 'A')!=NULL) flag = true;
      else if (strchr(password, 'S')!=NULL) flag = true;
      else if (strchr(password, 'D')!=NULL) flag = true;
      else if (strchr(password, 'F')!=NULL) flag = true;
      else if (strchr(password, 'G')!=NULL) flag = true;
      else if (strchr(password, 'H')!=NULL) flag = true;
      else if (strchr(password, 'J')!=NULL) flag = true;
      else if (strchr(password, 'K')!=NULL) flag = true;
      else if (strchr(password, 'L')!=NULL) flag = true;
      else if (strchr(password, 'Z')!=NULL) flag = true;
      else if (strchr(password, 'X')!=NULL) flag = true;
      else if (strchr(password, 'C')!=NULL) flag = true;
      else if (strchr(password, 'V')!=NULL) flag = true;
      else if (strchr(password, 'B')!=NULL) flag = true;
      else if (strchr(password, 'N')!=NULL) flag = true;
      else if (strchr(password, 'M')!=NULL) flag = true;
      else{
        flag = false;
      }
    }
  }
  return flag;
}

accounts createUser(char login[21], char password[21], long int cardNamber){
  accounts user = {"","",cardNamber,0,0};
  strcpy(user.login, login);
  strcpy(user.password, password);
  printf("%s %s 2\n1\n",login ,user.login);
  accounts voi = {"","",0,0,0};
  if(!checkLogin(user.login)){
      printf("111");

    return voi;
  }
  if(!checkPossword(user.password)){
      printf("222");

    return voi;
  }
  if((user.cardNamber<999999999999999)||(user.cardNamber>9999999999999999)){
      printf("333");

    return voi;
  }
  FILE *users = fopen("users.txt", "a");
  fprintf(users, "%s\n%s\n%ld\n0\n0\n",user.login,user.password,user.cardNamber);
  fclose(users);
  char fileName[44];
  sprintf(fileName, "favorites/favorites_%s.txt", user.login);
  FILE *favorites = fopen(fileName, "w");
  fclose(favorites);
  return user;
}

accounts signIn(char login[21], char password[21]){
  accounts user = {*login,*password,0,0,0};
  accounts voi = {"","",0,0,0};
  bool flag = true;
  char name[21];
  while(flag){
    FILE *users = fopen("users.txt", "r");
    while (fgets(name, 21, users) != NULL){
      name[strlen(name)-1] = 0;
      if (strcmp(user.login,name)==0){
        flag = false;
        break;
      }
    }
    if (flag){
      fclose(users);
      return voi;
    }
  }
  // Не ебу как это починить, поэтому ловите ещё один перебор файла
  FILE *users = fopen("users.txt", "r");
  while (fgets(name, 21, users) != NULL){
    name[strlen(name)-1] = 0;
    if (strcmp(user.login,name)==0){
      break;
    }
  }
  fgets(name, 21, users);
  name[strlen(name)-1] = 0;
  if (strcmp(user.password,name)!=0)
    return voi;
  fgets(name, 21, users);
  user.cardNamber = atol (name);
  fgets(name, 21, users);
  user.favoritesSize = atoi (name);
  fgets(name, 21, users);
  user.isAdmin = atoi (name);
  fclose(users);
  free(name);
  printf("111");
  return user;
}