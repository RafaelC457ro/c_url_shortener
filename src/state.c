#include <stdlib.h>

#include "state.h"

State *state_new()
{
    State *s;

    s = malloc(sizeof *s);
    if (!s)
        return NULL;

    s->value = 0;

    return s;
}

int state_set(State *s, int value)
{
    if (value < 1 || value > 10)
        return -1;

    s->value = value;

    return 0;
}

int state_get(State *s)
{
    return s->value;
}

void state_free(State *s)
{
    free(s);
}