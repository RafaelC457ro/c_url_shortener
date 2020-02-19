#ifndef __S_LIST_H__   
#define __S_LIST_H__

#define S_LIST_INIT_SIZE 1000

typedef struct s_list {
    int len;
    int size;
    char **s;
} StringList;

StringList* s_list_init();

int s_list_append(StringList *s_list, char *s);

int s_list_get(StringList *s_list, int index, char *s);

void s_list_free(StringList *s_list);

#endif