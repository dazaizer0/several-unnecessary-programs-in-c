#include <stdio.h>
#include <stdlib.h>

bool even(int x)
{
    return x % 2 == 0;
}

int main(void)
{
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int xs_len = sizeof(xs) / sizeof(xs[0]);
    int *xs_pointer = xs;

    bool (*e)(int) = even;

    for (int i = 0; i < xs_len; ++i)
    {
        int *number = (int*)malloc(sizeof(int));
        *number = *(xs_pointer + i);

        if(e(*number))
        {
            printf("even number from list - %d\n", *number);
        }

        free(number);
    }

    return 0;
}
