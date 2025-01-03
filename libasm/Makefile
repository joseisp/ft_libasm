SRC_C = main.c
SRC_ASM = ft_strlen.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s ft_strcmp.s
OBJ_C = main.o
OBJ_ASM = $(SRC_ASM:.s=.o)
LIBRARY = libasm.a 
EXEC = libasmExec

CC = gcc
CFLAGS = -static -Wall -Wextra -Werror
AS = nasm
ASFLAGS = -f elf64
EXEMPLETXT = exemple_false.txt exemple_true.txt


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
	rm -f $(LIBRARY) $(EXEC) $(EXEMPLETXT)

re: fclean all
