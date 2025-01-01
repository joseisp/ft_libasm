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
    ; Verifica se rdi é nulo
    test rdi, rdi
    jz _error_null

    ; Salva o endereço da string original
    mov rbx, rdi

    ; Calcula o comprimento da string
    call ft_strlen
    mov rsi, rax

    ; Aloca memória suficiente para a cópia da string
    mov rdi, rsi
    add rdi, 1
    call malloc wrt ..plt
    test rax, rax
    jz _error_null

    ; Copia a string para o novo espaço alocado
    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy

    ; Retorna o endereço da nova string
    ret

_error_null:
    ; Exibe a mensagem de erro
    mov rax, 1
    mov rdi, 1
    mov rsi, erro_msg
    mov rdx, 26
    syscall

    ; Exibe uma nova linha
    mov rax, 1
    mov rdi, 1
    mov rsi, new_line
    mov rdx, 1
    syscall

    ; Termina o programa com código de saída 0
    mov rax, 60
    xor rdi, rdi
    syscall
