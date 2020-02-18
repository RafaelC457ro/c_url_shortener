#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 1000;

typedef struct StringList
{
    int size;
    int len;
    char *list;
} StringList;

StringList *s_list_init()
{
    StringList *s_list;
    s_list->size = INIT_SIZE;
    s_list->len = -1;
    s_list->list = malloc(INIT_SIZE * sizeof(char *));
    return s_list;
}

int s_list_append(StringList *s_list, char *s)
{
    int n_index = s_list->len + 1;
    if (n_index >= s_list->size)
    {
        realloc(s_list->list, (s_list->size + INIT_SIZE) * sizeof(char *));
    }
    s_list->list[n_index] = malloc(strlen(s) * sizeof(char));
    strcpy(s_list->list[n_index], s);
    s_list->len++;
    return 0;
}

int s_list_get(StringList *s_list, int index, char *s)
{
    if (index > s_list->len)
    {
        return -1;
    }

    s = s_list->list[index];
    return 0;
}

void s_list_free(StringList *s_list)
{
    int i;
    for (i = 0; i < s_list->len; i++)
    {
        free(s_list->list[i]);
    }
    free(s_list->list);
}
