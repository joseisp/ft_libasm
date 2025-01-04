extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
    global ft_strdup

ft_strdup:
    call __errno_location wrt ..plt
    mov r12, rax
    mov dword [r12], 0 

    test rdi, rdi
    jz set_errno_null

    push rbx
    mov rbx, rdi

    call ft_strlen
    mov rsi, rax

    mov rdi, rsi
    add rdi, 1          
    call malloc wrt ..plt
    test rax, rax
    jz set_errno_mem

    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy

    pop rbx
    ret

set_errno_mem:
    mov dword [r12], -12 
    mov rax, -1
    pop rbx
    ret

set_errno_null:
    mov dword [r12], -22
    mov rax, -1
    ret
