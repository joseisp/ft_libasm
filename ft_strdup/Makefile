SRC_C = main.c
SRC_ASM = ft_strlen.s ft_strcpy.s ft_strdup.s ft_write.s
OBJ_C = main.o
OBJ_ASM = $(SRC_ASM:.s=.o)
LIBRARY = ft_strdup.a 
EXEC = programa

CC = gcc
CFLAGS = -Wall -Wextra
AS = nasm
ASFLAGS = -f elf64

all: $(EXEC)

$(EXEC): $(OBJ_C) $(LIBRARY)
	$(CC) -o $@ $^ 

$(OBJ_C): $(SRC_C)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBRARY): $(OBJ_ASM)
	ar rcs $@ $^

$(OBJ_ASM): %.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_C) $(OBJ_ASM)

fclean: clean
	rm -f $(LIBRARY) $(EXEC)

re: fclean all
