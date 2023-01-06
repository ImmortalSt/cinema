#include "list.h"

void push_back(list* lst, void* element){
    struct unit* temp = malloc(sizeof(struct unit));
    temp->item = element;
    if (lst->firstelement == NULL) {
        lst->firstelement = temp;
        lst->lastelement = temp;
    } else {
        temp->previos = lst->lastelement;
        lst->lastelement->next = temp;
        lst->lastelement = temp;
    }
    lst->size++;
}

void* pop_back(list* lst){
    struct unit* res;
    
    void* result = 0;
    if (lst->size > 1) {
        result = lst->lastelement->item;
        res = lst->lastelement;
        lst->lastelement = lst->lastelement->previos;
        lst->lastelement->next = NULL;
    } else if (lst->size == 1){
        res = lst->firstelement;
        result = lst->firstelement->item;
        lst->firstelement = NULL;
    }
    lst->size--;
    free(res);
    return result;
}

void do_func_on_elements(list* lst, void (*func)(void* element)) {
    struct unit* currentelement = lst->firstelement;
    do {
        func(currentelement->item);
        currentelement = currentelement->next;
    } while (currentelement);
}

void remove_at(list* lst, int index){
    if (index < 0 || index > lst->size - 1) return;


    struct unit* result;
    if (index == 0) {
        result = lst->firstelement;
        lst->firstelement = lst->firstelement->next;
        lst->firstelement->previos = NULL;
    } else if (index == lst->size - 1) {
        result = lst->lastelement;
        lst->lastelement->previos->next = NULL;
        lst->lastelement = lst->lastelement->previos;
    } else {
        struct unit* target = lst->firstelement;
        for (int i = 1; i < index + 1; i++) target = target->next;
        target->previos->next = target->next;
        target->next->previos = target->previos;
        result = target;
    }

    lst->size--;
    free(result);
}

void add_at(list* lst, int index, void* el) {
    if (index < 0 || index > lst->size) return;

    struct unit* element = malloc(sizeof(struct unit));
    element->item = el;

    if (index == 0) {
        element->next = lst->firstelement;
        lst->firstelement->previos = element;
        lst->firstelement = element;
    } else if (index == lst->size){
        element->previos = lst->lastelement;
        lst->lastelement->next = element;
        lst->lastelement = element;
    } else {
        struct unit* target = lst->firstelement;
        for (int i = 1; i < index; i++) target = target->next;

        element->next = target->next;
        target->next->previos = element;
        target->next = element;
        element->previos = target;
    }
    lst->size++;
}

void* get_at(list* lst, int index){
    if (index == 0) {
        return lst->firstelement->item;
    } else {
        struct unit* result = lst->firstelement;
        for (int i = 1; i <= index; i++) result = result->next;
        return result->item;
    }
}