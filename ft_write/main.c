#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern ssize_t ft_write(int fd, char *buf, size_t count);

int main (int argc, char **argv){


    if (argc < 2)
        exit(0);

    int i = ft_write(1, argv[1], strlen(argv[1]));

    printf("The result is: %d\n", i);

}