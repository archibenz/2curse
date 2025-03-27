; unsigned_int.asm
global unsigned_int
extern a_unsigned
extern b_unsigned
extern x_unsigned

section .text

unsigned_int:
    ; Пролог функции
    push rbp
    mov rbp, rsp

    ; Загружаем значения 'a' и 'b' из глобальных переменных
    mov rax, [rel a_unsigned]
    mov rbx, [rel b_unsigned]

    ; Сравниваем 'a' и 'b' (unsigned comparison)
    cmp rax, rbx
    jb less_than    ; a < b
    ja greater_than ; a > b
    ; Если ни одно из вышеуказанных условий не выполнено, то a == b
    jmp equal

less_than:
    ; X = (a + 12) / 5
    add rax, 12
    xor rdx, rdx    ; Обнуляем rdx для unsigned деления
    mov rcx, 5
    div rcx         ; Unsigned division
    mov [rel x_unsigned], rax    ; Сохраняем результат в 'x_unsigned'
    jmp end_function

greater_than:
    ; Проверка на деление на ноль
    cmp rbx, 0
    je division_by_zero
    ; X = a / b - 21
    mov rax, [rel a_unsigned]
    xor rdx, rdx    ; Обнуляем rdx для unsigned деления
    div rbx         ; Unsigned division
    sub rax, 21
    mov [rel x_unsigned], rax    ; Сохраняем результат в 'x_unsigned'
    jmp end_function

equal:
    ; X = 210
    mov rax, 210
    mov [rel x_unsigned], rax    ; Сохраняем результат в 'x_unsigned'
    jmp end_function

division_by_zero:
    ; Установка кода ошибки в 'x_unsigned'
    mov rax, 0xFFFFFFFFFFFFFFFF  ; UINT64_MAX
    mov [rel x_unsigned], rax

end_function:
    ; Эпилог функции
    mov rsp, rbp
    pop rbp
    ret
