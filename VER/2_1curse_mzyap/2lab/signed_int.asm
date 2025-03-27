; signed_int.asm
global signed_int
extern a_signed
extern b_signed
extern x_signed

section .text

signed_int:
    ; Пролог функции
    push rbp
    mov rbp, rsp

    ; Загружаем значения 'a' и 'b' из глобальных переменных
    mov rax, [rel a_signed]
    mov rbx, [rel b_signed]

    ; Сравниваем 'a' и 'b' (signed comparison)
    cmp rax, rbx
    jl less_than    ; a < b
    jg greater_than ; a > b
    ; Если ни одно из вышеуказанных условий не выполнено, то a == b
    jmp equal

less_than:
    ; X = (a + 12) / 5
    add rax, 12
    cqo             ; Расширение знака для деления (64-битный эквивалент cdq)
    mov rcx, 5
    idiv rcx        ; Signed division
    mov [rel x_signed], rax    ; Сохраняем результат в 'x_signed'
    jmp end_function

greater_than:
    ; Проверка на деление на ноль
    cmp rbx, 0
    je division_by_zero
    ; X = a / b - 21
    mov rax, [rel a_signed]
    cqo             ; Расширение знака для деления
    idiv rbx        ; Signed division
    sub rax, 21
    mov [rel x_signed], rax    ; Сохраняем результат в 'x_signed'
    jmp end_function

equal:
    ; X = 210
    mov rax, 210
    mov [rel x_signed], rax    ; Сохраняем результат в 'x_signed'
    jmp end_function

division_by_zero:
    ; Установка кода ошибки в 'x_signed'
    mov rax, 0x7FFFFFFFFFFFFFFF  ; INT64_MAX
    mov [rel x_signed], rax

end_function:
    ; Эпилог функции
    mov rsp, rbp
    pop rbp
    ret
