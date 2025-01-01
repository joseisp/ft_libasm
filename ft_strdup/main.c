#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

extern char *ft_strdup(const char *s);
extern ssize_t ft_write(int fd, char *buf, size_t count);
extern size_t ft_strlen(char *);
extern ssize_t ft_read(int fd, char *buf, size_t count);


int main (){    
    char    *text;

    text = ft_strdup("Goodbye, my friend!\n");
    printf("string: %s", text);


    return 0;
}

