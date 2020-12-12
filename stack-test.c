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
        stack_push(s, pow(0.5, n));

        if (stack_pop(s) != pow(0.5, (double) n)) {
            test = false;

        }
    }

    printf("Test the functioning of the stack ... %s", test ? "PASS" : "FAIL");

    return 0;
}