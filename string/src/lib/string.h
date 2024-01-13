#include <stdio.h>
#include <stdlib.h>

#ifndef ADVC_STRING_H
#define ADVC_STRING_H

struct string {
    char *value;
};

void sets(struct string *str, const char c[]) {
    free(str->value);
    int c_length = 0;

    while (c[c_length] != '\0') {
        c_length++;
    }

    str->value = (char *)malloc((c_length + 1) * sizeof(char));

    int i;
    for (i = 0; i < c_length; i++) {
        str->value[i] = c[i];
    }

    str->value[c_length] = '\0';
}

void scans(struct string *str) {
    free(str->value);
    str->value = (char *)malloc(1 * sizeof(char));

    if (str->value == NULL) {
        fprintf(stderr, "memory alocation error.\n");
        exit(EXIT_FAILURE);
    }

    int c;
    int length = 0;

    while ((c = getchar()) != '\n') {
        str->value[length] = (char)c;

        str->value = (char *)realloc(str->value, (length + 2) * sizeof(char));

        if (str->value == NULL) {
            fprintf(stderr, "memory alocation error.\n");
            exit(EXIT_FAILURE);
        }

        length++;
    }

    str->value[length] = '\0';
}

void prints(struct string *str) {
    printf("%s", str->value);
}

#endif
