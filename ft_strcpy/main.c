#include <stdio.h>
#include <stdlib.h>

extern size_t ft_strcpy(char *dest, char *str);

int main(int argc, char **argv) {

    if (argc < 1)
        exit(0);

    printf("Resultado antes: %s, %s\n", argv[1], argv[2]);

    // Chama a função ft_strcpy
    ft_strcpy(argv[1], argv[2]);

    printf("Resultado depois: %s, %s\n", argv[1], argv[2]);

    return 0;
}
