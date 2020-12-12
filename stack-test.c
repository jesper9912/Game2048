#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

int main(void)
{
    Stack *s = stack_create();
    bool test = true;

    for (int n = 1; n <= 10; n++) {
        stack_push(s, pow(0.5, (double) n));

    }

    int n = 10;

    while (!stack_is_empty(s)) {

        if ((stack_pop(s) != pow(0.5, (double) n)) && n > 0) {
            test = false;

        }
        n--;
    }

    printf("Test the functioning of the stack ... %s\n", test ? "PASS" : "FAIL");

    stack_destroy(s);

    return 0;
}