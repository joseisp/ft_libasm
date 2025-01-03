#include "main.h"

int main()
{
    testStrlen();
    testStrcpy();
    testStrcmp();
    testWrite();
    testRead();
    testStrdup();

    return 0;
}

void testStrlen()
{
    printf("\nft_strlen: \n");

    char strLength[] = "Hello, Libasm";

    printf("True strlen: %ld\n", strlen(strLength));
    printf("False strlen: %ld\n", ft_strlen(strLength));

    return ;
}

void testStrcpy()
{
    printf("\nft_strcpy: \n");

    char str2True[10]; 
    char str2False[10];

    strcpy(str2True, "abcdefghi");
    ft_strcpy(str2False, "abcdefghi");

    
    printf("True strcpy: %s\n", str2True);
    printf("False strcpy: %s\n", str2False);

    return ;
}


void testStrcmp()
{
    printf("\nft_strcmp: \n");

    const char strCompare1[] = "Hello";
    const char strCompare2[] = "Hello";

    const char strCompare3[] = "My own world is so strange to think and live.";
    const char strCompare4[] = "Food and Juice";

    printf("True Equal: %d\n", strcmp(strCompare1, strCompare2));
    printf("True Not equal: %d\n", strcmp(strCompare3, strCompare4));

    printf("False Equal: %d\n", ft_strcmp(strCompare1, strCompare2));
    printf("False Not equal: %d\n", ft_strcmp(strCompare3, strCompare4));


    return ;

}


void testWrite()
{
    printf("\nft_write: \n");

    char true_test[] = "True: Hello, my friend!\n";
    char false_test[] = "False: Goodbye, my friend!\n";

    int file_descriptor_true = open("exemple_true.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    int file_descriptor_false = open("exemple_false.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    write(file_descriptor_true, "test_true", 9);
    ft_write(file_descriptor_false, "test_false", 10);


    write(1, &true_test, ft_strlen(true_test));
    write(1, &false_test, ft_strlen(false_test));

    return ;
}

void testRead()
{
    printf("\nft_read: \n");

   int fd_true = open("exemple_true.txt", O_RDONLY);
    int fd_false = open("exemple_false.txt", O_RDONLY);
    char *storageReadFalse = malloc(sizeof(char ) * 10);
    char *storageReadTrue = malloc(sizeof(char ) * 10);

    ft_read(fd_false, storageReadFalse, 10);
    read(fd_true, storageReadTrue, 9);

    printf("teste true: %s\n", storageReadTrue);
    printf("teste false: %s\n", storageReadFalse);
    free(storageReadFalse);
    free(storageReadTrue);


}

void testStrdup()
{
    printf("\nft_strdup: \n");

    const char    *text_false;
    const char     text_to_test_false[] = "I'm so tired\n";

    const char    *text_true;
    const char     text_to_test_true[] = "My goodness...\n";

    text_true = strdup(text_to_test_true);
    printf("String true: %s", text_true);

    text_false = ft_strdup(text_to_test_false);
    printf("String false: %s", text_false);

}
