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
    int     length_msg;

    assert(ft_write(50, msg, len) == -1);
    perror("write");
    char *sub = ft_strdup("a\n");
    printf("STR: %s", sub);

    return 0;
}
