#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "users.h"

#define T_FILE "components/users/temp.txt"
#define U_FILE "components/users/users.txt"
#define F_FILE "components/users/favorites/favorites_%s.txt"


bool checkLogin(char login[21]){
  bool flag;
  if (strlen(login)==0) flag = false;
  else if ((strlen(login)<3)||(strlen(login)>20)){
    flag = false;
  }
  else{
    flag = true;
    char name[21] = "1";
    FILE *users = fopen("components/users/users.txt", "r");
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

//void replaceUser(accounts *user ,char *component, char* old_Variable, char* new_Variable){
void replaceUser(accounts *user ,char *component, int old_Variable, int new_Variable){
  FILE *fin, *fout;
  fin = fopen(U_FILE, "r");
  fout = fopen(T_FILE, "w");
  char name[21];
  fgets(name,21,fin);
  name[strlen(name)-1] = 0;
  while (strcmp(user->login,name) !=  0){
    fprintf(fout, "%s\n",name);
    fgets(name,21,fin);
    name[strlen(name)-1] = 0;
  }
  if (true){
    fprintf(fout, "%s",name);
    fgets(name,21,fin);
    fprintf(fout, "\n%s",name);
    fgets(name,21,fin);
    fprintf(fout, "%s",name);
    fgets(name,21,fin);
    fprintf(fout,"%d\n", new_Variable);
    //int i_new = atoi (new_Variable);
    user->favoritesSize = new_Variable;
  }
  while (fgets(name, 21, fin) != NULL)
    fprintf(fout, "%s",name);
  fclose(fin);
  fclose(fout);
  remove(U_FILE);
  rename(T_FILE, U_FILE);
}

accounts createUser(char login[21], char password[21]){
  srand(time(NULL));
  long int id = 1000000000000000 + rand()%8999999999999999;
  accounts user = {"","",id,0,0};
  strcpy(user.login, login);
  strcpy(user.password, password);
  accounts voi = {"","",0,0,-1};
  if(!checkLogin(user.login)){
    return voi;
  }
  if(!checkPossword(user.password)){
    return voi;
  }
  if((user.id<999999999999999)||(user.id>9999999999999999)){
    return voi;
  }
  FILE *users = fopen(U_FILE, "a");
  fprintf(users, "%s\n%s\n%ld\n0\n0\n",user.login,user.password,user.id);
  fclose(users);
  char fileName[63];
  sprintf(fileName, F_FILE, user.login);
  FILE *favorites = fopen(fileName, "w");
  fclose(favorites);
  return user;
}

accounts signIn(char login[21], char password[21]){
  accounts user = {"","",0,0,0};
  strcpy(user.login, login);
  strcpy(user.password, password);
  accounts voi = {"","",0,0,-1};
  bool flag = true;
  char name[21];
  while(flag){
    FILE *users = fopen(U_FILE, "r");
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
  FILE *users = fopen(U_FILE, "r");
  while (fgets(name, 21, users) != NULL){
    name[strlen(name)-1] = 0;
    if (strcmp(user.login,name)==0){
      break;
    }
  }
  fgets(name, 21, users);
  name[strlen(name)-1] = 0;
  if (strcmp(user.password,name)!=0){
    return voi;
  }
  fgets(name, 21, users);
  user.id = atol (name);
  fgets(name, 21, users);
  user.favoritesSize = atoi (name);
  fgets(name, 21, users);
  user.isAdmin = atoi (name);
  fclose(users);
  return user;
}

void pop_film(accounts *user, char *filmName){
  char fileName[63];
  sprintf(fileName, F_FILE, user->login);
  FILE *favorites = fopen(fileName, "a+");
  char name[40];
  bool flag = true;
  while (fgets(name,40,favorites) != NULL){
    name[strlen(name)-1] = 0;
    if (strcmp(filmName,name) ==  0){
      flag = false;
      break;
    }
  }
  if (flag) {
    fprintf(favorites, "%s\n",filmName);
    //char f_old[10], f_in[10];
    //sprintf(f_old, "%d", user->favoritesSize);
    //sprintf(f_in, "%d", user->favoritesSize+1);
    //replaceUser(user,"favoritesSize",f_old,f_in);
    replaceUser(user,"favoritesSize",user->favoritesSize,user->favoritesSize+1);
  }
  fclose(favorites);
}