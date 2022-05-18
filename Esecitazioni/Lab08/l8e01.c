#include <stdio.h>

int main(void) {

    FILE* this_source = fopen("l8e01.c", "r");
    char string[BUFSIZ*10];

        while(fgets(string, BUFSIZ*10, this_source)!=NULL)
        printf("%s", string);

    fclose(this_source);

    return 0;
}
