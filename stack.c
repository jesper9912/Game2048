#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *stack_create(void)
{
    Stack *s = malloc(sizeof(*s));

    s->capacity = 1;
    s->size = 0;
    s->data = calloc(s->capacity, sizeof(*s->data));

    return s;
}

void stack_destroy(Stack *s)
{   
    free(s->data);
    free(s);
}

void stack_push(Stack *s, double value)
{
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * sizeof(*s->data));

    }
    
    s->data[s->size] = value;
    s->size += 1;

}

double stack_pop(Stack *s)
{
    double value = s->data[s->size - 1];

    s->size -= 1;

    return value;
}

bool stack_is_empty(const Stack *s)
{
    return s->size <= 0;
}   