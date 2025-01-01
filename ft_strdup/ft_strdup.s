extern malloc
extern ft_strlen
extern ft_strcpy

section .data
    erro_msg     db "Error! Check the arguments", 0xA
    new_line     db 0xa

section .bss

section .text
    global ft_strdup

ft_strdup:
    test rdi, rdi
    jz _error_null

    push rbx
    mov rbx, rdi

    call ft_strlen
    mov rsi, rax

    mov rdi, rsi
    add rdi, 1
    call malloc wrt ..plt
    test rax, rax
    jz _error_null

    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy

    pop rbx
    ret

_error_null:
    mov rax, 1
    mov rdi, 1
    mov rsi, erro_msg
    mov rdx, 26
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, new_line
    mov rdx, 1
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
