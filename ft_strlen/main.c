#include <stdio.h>
#include <stdlib.h>

extern size_t ft_strlen(char *);


int main(int argc, char** argv){
    if (argc <= 0)
        exit(0);
    size_t resultado = ft_strlen(argv[1]);
    printf("Resultado: %ld\n", resultado);
    return 0;
}   