section .text
    global ft_strlen

ft_strlen:
    mov rax, 0

_loop:
    cmp byte[rdi + rax] ,0
    je _return
    inc rax
    jne _loop

_return:
    ret
