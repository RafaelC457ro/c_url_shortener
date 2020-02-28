#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_list.h"

HashList *hash_list_init() {
    HashList *h_list = malloc(sizeof(HashList));

    if (h_list == NULL) {
        fprintf(stderr, "Out of memory on create struct\n");
        exit(0);
    }

    h_list->size = HASH_LIST_INIT_SIZE;
    h_list->length = -1;
    h_list->keys = malloc(HASH_LIST_INIT_SIZE * sizeof(char *));
    h_list->data = malloc(HASH_LIST_INIT_SIZE * sizeof(char *));
    return h_list;
}

int hash_list_append(HashList *h_list, char *k, char *v) {
    int i = h_list->length + 1;
    if (i >= h_list->size) {
        h_list->keys =
            realloc(h_list->keys,
                    (h_list->size + HASH_LIST_INIT_SIZE) * sizeof(char *));
        if (h_list->keys == NULL) {
            fprintf(stderr, "Out of memory realocat keys\n");
            exit(0);
        }

        h_list->data =
            realloc(h_list->data,
                    (h_list->size + HASH_LIST_INIT_SIZE) * sizeof(char *));

        if (h_list->data == NULL){
            fprintf(stderr, "Out of memory on realocate data\n");
            exit(0);
        }
    }

    h_list->keys[i] = malloc(strlen(k) * sizeof(char));
    strcpy(h_list->keys[i], k);

    h_list->data[i] = malloc(strlen(v) * sizeof(char));
    strcpy(h_list->data[i], v);

    h_list->length = i;

    return 0;
}

int hash_list_get(HashList *h_list, char *k, char **s) {
    int i = 0;
    while (i < h_list->length) {
        if (strcmp(k, h_list->keys[i]) != 0) {
            i++;
            continue;
        }

        *s = h_list->data[i];
        break;
    }
    return 0;
}

void hash_list_free(HashList *h_list) {
    int i;
    for (i = 0; i < h_list->length; i++) {
        if (h_list->keys[i] != NULL) {
            free(h_list->keys[i]);
            free(h_list->data[i]);
        }
    }
    free(h_list);
}