#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *stack_create(void)
{
    Stack *s = malloc(sizeof(*s));
    s->capacity = 0;
    s->size = 0;

    return s;
}

void stack_destroy(Stack *s)
{
    free(s->data);
    free(s);
}

void stack_push(Stack *s, double value)
{
    s->size += 1;

    if(s->size > s->capacity) {
        s->capacity += 1;
        s->data = realloc(s->data,s->capacity * sizeof(s->data));
    }

    s->data[s->capacity] = value;
}

double stack_pop(Stack *s)
{
    double *value = s->data;

    free(s->data);
    s->size -= 1;
    s->capacity -= 1;

    return *value;
}

bool stack_is_empty(const Stack *s)
{
    return s->capacity == 0;
}   