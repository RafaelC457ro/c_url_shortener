#ifndef __HASH_LIST_H__
#define __HASH_LIST_H__

#define HASH_LIST_INIT_SIZE 1000

typedef struct h_list {
    int length;
    int size;
    void **keys;
    char **data;
} HashList;

HashList *hash_list_init();

int hash_list_append(HashList *h_list, char *k, char *v);

int hash_list_get(HashList *h_list, char *index, char **s);

void hash_list_free(HashList *h_list);

#endif