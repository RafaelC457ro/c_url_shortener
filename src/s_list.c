#include "s_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 100; 

StringList* s_list_init() {
    StringList *s_list;
    s_list->size = INIT_SIZE;
    s_list->len = -1;
    s_list->list = malloc(INIT_SIZE * sizeof(char*));
    return s_list;
}

int s_list_append(StringList *s_list, char *s){
    int n_index = s_list->len + 1;
    if(n_index >= s_list->size) {
        s_list = realloc(s_len, (s_list->size + INICIAL_SIZE) * sizeof(char*));
    }
    s_list->list[n_index] =  malloc(strlen(s) * sizeof(char));
    strcpy(s_list->list[n_index], s);
    s_list->len++;
    return 0;
}

int s_list_get(StringList *s_list, int index, char *s) {
    if(index > s_list->len){
        return -1;
    }

    s = s_list->list[index];
    return 0; 
}

void s_list_free(StringList *s_list){
    int i;
    for(i = 0; < s_list->len; i++){
        free(s_list->list[i]);
    }
    free(s_list->list);
}




