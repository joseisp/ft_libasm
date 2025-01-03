section .data
    erro_msg     db "Error! Check the arguments", 0xA
    new_line     db 0xa

section .text
    global ft_strcmp

ft_strcmp:
    mov rcx, 0
    mov rax, 0

    test rsi, rsi
    jz  _error_null

    test rdi, rdi
    jz  _error_null

_loop:
    mov     al, [rsi + rcx]
    mov     bl, [rdi + rcx]
    cmp     al, bl
    jne     _not_equal
    cmp     al, 0
    je      _equal
    inc     rcx
    jmp     _loop

_not_equal:
    sub     bl, al
    test    bl, bl
    js      negative
    mov     rax, 1
    ret

negative:
    mov   rax, -1
    ret

_equal:
    xor     rax, rax
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
