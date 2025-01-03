section .data
    erro_msg     db "Error! Check the arguments", 0xA
    new_line     db 0xa

section .bss
    errno resq 1

section .text
   global ft_read

ft_read:
    test rsi, rsi
    jz _error_null

    test rdx, rdx
    jz _error_null


ft_read_main:
    mov rax, 0
    syscall
    test rax, rax
    js _error
    ret

_error:
    mov r8, rax
    lea rax, [rel errno]
    mov [rax], r8
    mov rax, -1
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
