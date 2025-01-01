#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern ssize_t ft_read(int fd, char *buf, size_t count);

int main (){

    char *file = "text.txt";
    char *storageRead = malloc(sizeof(char) * 50);
    int fd = open(file, O_RDONLY);

    int i = ft_read(fd, storageRead, 40);

    printf("The result is: %d\n", i);

}