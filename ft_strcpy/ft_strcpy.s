section .data
    hello       db "Error! Check the arguments", 0xA
    newLine     db 0xa

section .text
    global ft_strcpy

ft_strcpy:
    mov rax, 0
    mov rcx, 0

    test rsi, rsi
    jz errorNull

    test rdi, rdi
    jz errorNull

_loop:
    mov     al, byte[rsi + rcx]
    mov     [rdi + rcx], al
    inc     rcx
    cmp     al, 0
    jne     _loop

return: 
    mov     rax, rdi
    ret

errorNull:
    mov rax, 1
    mov rdi, 1
    mov rsi, hello
    mov rdx, 26
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newLine
    mov rdx, 1
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall