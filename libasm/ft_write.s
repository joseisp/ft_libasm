extern __errno_location

section .data
    erro_msg     db "Error! Check the arguments", 0xA
    new_line     db 0xa

section .text
    global ft_write

ft_write:
    test rsi, rsi
    jz set_errno_null

    test rdx, rdx
    jz set_errno_null

ft_write_main:
    call __errno_location wrt ..plt ; reset error_location
    mov r12, rax
    mov dword [r12], 0

    mov rax, 1
    syscall
    test rax, rax
    js set_errno_syscall
    ret

set_errno_syscall:
    mov dword [r12], eax
    neg dword [r12]
    mov rax, -1
    ret

set_errno_null:
    call __errno_location wrt ..plt
    mov r12, rax
    mov dword [r12], -22 
    mov rax, -1         
    ret
