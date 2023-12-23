#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int foo(int x, int y)
{
    return x * y;
}

int main(void)
{
    int (*f)(int, int) = foo;
    printf("%d\n", f(3,  4));

    return 0;
}
