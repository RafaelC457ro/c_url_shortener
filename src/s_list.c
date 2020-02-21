#include "s_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StringList *s_list_init() {
    StringList *s_list = malloc(sizeof(StringList));
    // TODO: Check is not null
    s_list->size = S_LIST_INIT_SIZE;
    s_list->len = -1;
    s_list->s = malloc(S_LIST_INIT_SIZE * sizeof(char *));
    // TODO: Check is not null
    return s_list;
}

int s_list_append(StringList *s_list, char *s) {
    int n_index = s_list->len + 1;
    if (n_index >= s_list->size) {
        s_list->s = realloc(s_list->s,
                            (s_list->size + S_LIST_INIT_SIZE) * sizeof(char *));
        // TODO: Check is not null
    }
    s_list->s[n_index] = malloc(strlen(s) * sizeof(char));
    strcpy(s_list->s[n_index], s);
    s_list->len++;
    return n_index;
}

int s_list_get(StringList *s_list, int index, char **s) {
    if (index > s_list->len) {
        return -1;
    }
    // TODO: check if not null, there no way to change the index for now
    *s = s_list->s[index];
    return 0;
}

void s_list_free(StringList *s_list) {
    int i;
    for (i = 0; i < s_list->len; i++) {
        if (s_list->s[i] != NULL) {
            free(s_list->s[i]);
        }
    }
    free(s_list);
}
