#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED


typedef struct state
{
    int value;
} State;

State *state_new();
int state_set(State *, int);
int state_get(State *);
void state_free(State *);

#endif /* STATE_H_INCLUDED */