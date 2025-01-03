section .data
    erro_msg       db "Error! Check the arguments", 0xA
    new_line     db 0xa

section .text
    global ft_strcpy

ft_strcpy:
    mov rax, 0
    mov rcx, 0

    test rsi, rsi
    jz _error_null

    test rdi, rdi
    jz _error_null

_loop:
    mov     al, byte[rsi + rcx]
    mov     [rdi + rcx], al
    inc     rcx
    cmp     al, 0
    jne     _loop

return: 
    mov     rax, rdi
    ret

_error_null:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel erro_msg]
    mov rdx, 26
    syscall

    mov rax, 1
    mov rdi, 1
    lea rsi, [rel new_line]
    mov rdx, 1
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall