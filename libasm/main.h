#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

extern ssize_t ft_read(int fd, char *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strcpy(char *dest, char *str);
extern char *ft_strdup(const char *str);
extern size_t ft_strlen(char *);
extern ssize_t ft_write(int fd, char *buf, size_t count);

// functions

void testStrlen();
void testStrcpy();
void testStrcmp();
void testWrite();
void testRead();
void testStrdup();