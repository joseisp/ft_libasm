SRC_C = main.c
SRC_ASM = ft_write.s
OBJ_C = main.o
OBJ_ASM = ft_write.o
LIBRARY = ft_write.a
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

$(OBJ_ASM): $(SRC_ASM)
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_C) $(OBJ_ASM)

fclean: clean
	rm -f $(LIBRARY) $(EXEC)

re: fclean all
