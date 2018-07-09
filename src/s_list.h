#ifndef __S_LIST_H__   
#define __S_LIST_H__

typedef struct s_list {
    int len;
    int size;
    char **list;
} StringList;

StringList* s_list_init();

int s_list_append(StringList *list, char *s);

int s_list_get(StringList *list, int index);

void s_list_free(StringList *list);

#endif