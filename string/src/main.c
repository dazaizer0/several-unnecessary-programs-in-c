#include <stdio.h>
#include <stdlib.h>
#include "lib/string.h"

int main() {
    struct string str;

    printf("scan string: ");
    scans(&str);

    printf("\nscans result: ");
    prints(&str);

    sets(&str, "Hello World!!!");
    printf("\nsets result: ");
    prints(&str);

    free(str.value);

    return 0;
}
