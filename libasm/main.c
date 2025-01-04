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
    printf("ft_strlen: \n");

    char strLength[] = "Hello, Libasm";
    char strLengthEmpty[] = "";

    printf("True strlen: %ld\n", strlen(strLength));
    printf("False strlen: %ld\n", ft_strlen(strLength));

    printf("True strlen empty: %ld\n", strlen(strLengthEmpty));
    printf("False strlen empty: %ld\n", ft_strlen(strLengthEmpty));

    return ;
}

void testStrcpy()
{
    printf("\nft_strcpy: \n");

    char str2True[28]; 
    char str2False[28];
    
    char str2TrueEmpty[10]; 
    char str2FalseEmpty[10];

    strcpy(str2True, "abcdefghiabcdefghiabcdefghi");
    ft_strcpy(str2False, "abcdefghiabcdefghiabcdefghi");

    strcpy(str2TrueEmpty, "");
    ft_strcpy(str2FalseEmpty, "");

    
    printf("True strcpy: %s\n", str2True);
    printf("False strcpy: %s\n", str2False);

    printf("True strcpy empty: %s\n", str2TrueEmpty);
    printf("False strcpy empty: %s\n", str2FalseEmpty);

    return ;
}


void testStrcmp()
{
    printf("\nft_strcmp: \n");

    const char strCompare1[] = "Hello";
    const char strCompare2[] = "Hello";

    const char strCompare3[] = "My own world is so strange to think and live.";
    const char strCompare4[] = "Food and Juice";

    const char strCompare5[] = "";
    const char strCompare6[] = "";


    printf("True Equal: %d\n", strcmp(strCompare1, strCompare2));
    printf("True Not equal: %d\n", strcmp(strCompare3, strCompare4));
    printf("True Empty: %d\n", strcmp(strCompare5, strCompare6));
    printf("True string and empty: %d\n", strcmp(strCompare4, strCompare6));

    printf("False Equal: %d\n", ft_strcmp(strCompare1, strCompare2));
    printf("False Not equal: %d\n", ft_strcmp(strCompare3, strCompare4));
    printf("False Empty: %d\n", ft_strcmp(strCompare5, strCompare6));
    printf("False string and empty: %d\n", strcmp(strCompare4, strCompare6));

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
    ft_write(215124, "test_wrong_output", 17);
    
    printf("Errno output: %d - %s\n", errno, strerror(errno));


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
    ft_read(6464, storageReadTrue, 9);

    printf("Errno output: %d - %s\n", errno, strerror(errno));

    printf("teste true: %s\n", storageReadTrue);
    printf("teste false: %s\n", storageReadFalse);
    free(storageReadFalse);
    free(storageReadTrue);


}

void testStrdup()
{
    printf("\nft_strdup: \n");

    const char    *text_false;
    const char     text_to_test_false[] = "I'm so tired";
    const char    *text_false_empty;
    const char     text_to_test_false_empty[] = "";

    const char    *text_true;
    const char     text_to_test_true[] = "My goodness!!!!!!!!!!!!";
    const char    *text_true_empty;
    const char     text_to_test_true_empty[] = "";

    

    text_true = strdup(text_to_test_true);
    printf("String true: %s\n", text_true);
    text_true_empty = strdup(text_to_test_true_empty);
    printf("String true empty: %s\n", text_true_empty);

    text_false = ft_strdup(text_to_test_false);
    printf("String false: %s\n", text_false);
    text_false_empty = ft_strdup(text_to_test_false_empty);
    printf("String false empty: %s\n", text_false_empty);


    printf("Errno output: %d - %s\n", errno, strerror(errno));


}
