#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 


int main() {
    char original[] = "maça amassada";
    char *duplicate = strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);

        // Lembre-se de liberar a memória alocada para a duplicata
        free(duplicate);
    } else {
        printf("Falha ao duplicar a string.\n");
    }

    return 0;
}







// int main(int argc, char **argv){

//     int result = strcmp(argv[1], argv[2]);

//     printf("S1: %s, S2: %s\n", argv[1], argv[2]);
//     printf("Resultado: %d\n", result);

//     return 0;
// }

// void test_strcmp(const char *str1, const char *str2) {
//     int result = strcmp(str1, str2);

//     printf("Comparando \"%s\" com \"%s\": ", str1, str2);

//     if (result < 0) {
//         printf("A primeira string é menor.\n");
//     } else if (result == 0) {
//         printf("As strings são iguais.\n");
//     } else {
//         printf("A primeira string é maior.\n");
//     }
// }

// int main() {
//     const char *string1 = "abc";
//     const char *string2 = "abc";
//     const char *string3 = "abcd";
//     const char *string4 = "ab";
//     const char *string5 = "xyz";
//     const char *string6 = "abd";
    
//     test_strcmp(string1, string2); // Strings iguais
//     test_strcmp(string1, string3); // Primeira string menor
//     test_strcmp(string3, string1); // Primeira string maior
//     test_strcmp(string1, string4); // Primeira string maior
//     test_strcmp(string4, string1); // Primeira string menor
//     test_strcmp(string1, string5); // Primeira string menor
//     test_strcmp(string5, string1); // Primeira string maior
//     test_strcmp(string6, string1);

//     test_strcmp("a", "sss");

//     return 0;
// }
