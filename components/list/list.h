#include <stdio.h>
#include <stdlib.h>

struct unit
{
    void* item;
    struct unit* next;
    struct unit* previos;
};

typedef struct list
{       
    struct unit* firstelement;
    struct unit* lastelement;
    int size;

} list;

void push_back(list* lst, void* element);
void* pop_back(list* lst);
void do_func_on_elements(list* lst, void (*func)(void* element));
void remove_at(list* lst, int index);
void add_at(list* lst, int index, void* element);
void* get_at(list* lst, int index);