#include <stdio.h>
#include <stdlib.h>

extern size_t ft_strcmp(char *dest, char *str);

int main (int argc, char **argv){

    if (argc < 1)
        exit(0);

    int i = ft_strcmp(argv[1], argv[2]);

    printf("The result is: %d\n", i);

}