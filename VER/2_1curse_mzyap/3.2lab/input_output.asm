section .bss
    input_a resb 21
    input_b resb 21
    result resd 1
    a resd 1
    b resd 1
    result_str resb 12

section .text
    global _start

_start:
    ; Ввод a
.input_a_loop:
    mov eax, 4
    mov ebx, 1
    mov ecx, input_a_msg
    mov edx, len_input_a_msg
    int 0x80

    mov eax, 3
    mov ebx, 0
    lea ecx, [input_a]
    mov edx, 20
    int 0x80

    mov byte [ecx + eax - 1], 0  ; Устанавливаем нуль-терминатор
    lea esi, [input_a]
    call validate_input
    test eax, eax
    jz .input_a_loop             ; Если ввод некорректный, запросить повторно

    lea ecx, [input_a]
    call str_to_int
    mov [a], eax

    ; Ввод b
.input_b_loop:
    mov eax, 4
    mov ebx, 1
    mov ecx, input_b_msg
    mov edx, len_input_b_msg
    int 0x80

    mov eax, 3
    mov ebx, 0
    lea ecx, [input_b]
    mov edx, 20
    int 0x80

    mov byte [ecx + eax - 1], 0  ; Устанавливаем нуль-терминатор
    lea esi, [input_b]
    call validate_input
    test eax, eax
    jz .input_b_loop             ; Если ввод некорректный, запросить повторно

    lea ecx, [input_b]
    call str_to_int
    mov [b], eax

    ; Вычисления
    mov eax, [a]
    mov ebx, [b]
    cmp eax, ebx
    je .equal
    jb .less       ; Беззнаковое сравнение: если a < b
    ja .greater    ; Беззнаковое сравнение: если a > b

.less:
    ; (a + 12) / 5
    mov eax, [a]
    add eax, 12
    mov edx, 0              ; Обнуляем edx для беззнакового деления
    mov ecx, 5
    div ecx
    mov [result], eax
    jmp .output

.greater:
    ; a / b - 21
    mov eax, [a]
    mov edx, 0              ; Обнуляем edx для беззнакового деления
    mov ecx, [b]
    div ecx
    sub eax, 21
    mov [result], eax
    jmp .output

.equal:
    ; Результат = 210
    mov dword [result], 210
    jmp .output

.output:
    ; Вывод результата в signed формате
    mov eax, [result]
    call int_to_str
    mov eax, 4
    mov ebx, 1
    mov ecx, signed_msg
    mov edx, len_signed_msg
    int 0x80

    mov eax, 4
    mov ebx, 1
    lea ecx, [result_str]
    mov edx, 12
    int 0x80

    ; Печать новой строки
    mov eax, 4
    mov ebx, 1
    mov ecx, newline_msg
    mov edx, len_newline_msg
    int 0x80

    ; Вывод результата в unsigned формате
    mov eax, [result]
    call int_to_str_unsigned
    mov eax, 4
    mov ebx, 1
    mov ecx, unsigned_msg
    mov edx, len_unsigned_msg
    int 0x80

    mov eax, 4
    mov ebx, 1
    lea ecx, [result_str]
    mov edx, 12
    int 0x80

    ; Печать новой строки
    mov eax, 4
    mov ebx, 1
    mov ecx, newline_msg
    mov edx, len_newline_msg
    int 0x80

    jmp _exit

_exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80

validate_input:
    xor eax, eax
    xor edx, edx
    mov edi, esi
.validate_loop:
    lodsb
    cmp al, 0
    je .validate_done
    cmp al, '-'
    je .validate_sign
    cmp al, '0'
    jb .invalidate
    cmp al, '9'
    ja .invalidate
    inc edx
    jmp .validate_loop
.validate_sign:
    cmp edx, 0
    jne .invalidate
    jmp .validate_loop
.invalidate:
    xor eax, eax
    ret
.validate_done:
    test edx, edx
    jz .invalidate
    mov eax, 1
    ret

str_to_int:
    xor eax, eax
    xor ebx, ebx
    mov esi, ecx
    cmp byte [esi], '-'
    jne .read_digits
    inc esi
    mov ecx, 1
.read_digits:
    mov bl, byte [esi]
    cmp bl, 0
    je .end_conversion
    sub bl, '0'
    imul eax, eax, 10
    add eax, ebx
    inc esi
    jmp .read_digits
.end_conversion:
    cmp ecx, 1
    jne .done
    neg eax
.done:
    ret

int_to_str:
    ; Преобразование signed int в строку
    mov ecx, result_str + 11  ; Указываем на конец буфера (+11 для нуль-терминатора)
    mov byte [ecx], 0         ; Нуль-терминатор
    dec ecx                   ; Подготовка к записи цифр
    mov ebx, 10               ; Основание системы счисления
    xor esi, esi              ; Флаг отрицательного числа

    test eax, eax             ; Проверка на отрицательное число
    jge .convert              ; Если число положительное, переходим к конвертации
    neg eax                   ; Делаем число положительным
    mov esi, 1                ; Устанавливаем флаг отрицательного числа

.convert:
    xor edx, edx
    div ebx                   ; Деление eax на 10
    add dl, '0'               ; Конвертация остатка в символ
    mov [ecx], dl             ; Запись символа в буфер
    dec ecx
    cmp eax, 0
    jne .convert              ; Продолжаем, пока eax не станет 0

    cmp esi, 0                ; Проверка флага отрицательного числа
    je .done                  ; Если число положительное, пропускаем
    mov byte [ecx], '-'       ; Добавляем минусовой знак
    dec ecx

.done:
    inc ecx                   ; Корректируем указатель на начало строки
    ret

int_to_str_unsigned:
    ; Преобразование unsigned int в строку
    mov ecx, result_str + 11  ; Указываем на конец буфера
    mov byte [ecx], 0         ; Нуль-терминатор
    dec ecx
    mov ebx, 10               ; Основание системы счисления
.convert_unsigned:
    xor edx, edx              ; Обнуляем старшие 32 бита
    div ebx                   ; Делим eax на 10
    add dl, '0'               ; Преобразуем остаток в символ
    mov [ecx], dl             ; Записываем символ
    dec ecx
    cmp eax, 0
    jne .convert_unsigned      ; Повторяем, пока число не станет 0
    inc ecx                   ; Корректируем указатель
    ret

section .data
    input_a_msg db "Введите значение a: ", 0
    len_input_a_msg equ $ - input_a_msg
    input_b_msg db "Введите значение b: ", 0
    len_input_b_msg equ $ - input_b_msg
    signed_msg db "Результат (signed int): ", 0
    len_signed_msg equ $ - signed_msg
    unsigned_msg db "Результат (unsigned int): ", 0
    len_unsigned_msg equ $ - unsigned_msg
    newline_msg db 10, 0
    len_newline_msg equ $ - newline_msg

