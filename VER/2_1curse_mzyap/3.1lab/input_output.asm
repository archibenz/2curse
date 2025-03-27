section .bss
    global a_char
    global b_char
    global c_char
    global numerator_char
    global denominator_char
    global result_char

    global a_uint
    global b_uint
    global c_uint
    global numerator_uint
    global denominator_uint
    global result_uint

    input_a resb 20
    input_b resb 20
    input_c resb 20
    result_str resb 12

    a_char resb 1
    b_char resb 1
    c_char resb 1
    numerator_char resd 1
    denominator_char resd 1
    result_char resd 1        ; Изменено на resd 1 для хранения 32-битного результата

    a_uint resd 1             ; Оставляем как resd для 32-битных значений
    b_uint resd 1
    c_uint resd 1
    numerator_uint resd 1
    denominator_uint resd 1
    result_uint resd 1

section .data
    input_a_msg db "Введите значение a: ", 0
    len_input_a_msg equ $ - input_a_msg
    input_b_msg db "Введите значение b: ", 0
    len_input_b_msg equ $ - input_b_msg
    input_c_msg db "Введите значение c: ", 0
    len_input_c_msg equ $ - input_c_msg
    error_invalid_input db "Ошибка: введите корректное число!", 10, 0
    len_error_invalid_input equ $ - error_invalid_input
    result_signed_msg db "Результат (signed): ", 0
    len_result_signed_msg equ $ - result_signed_msg
    result_unsigned_msg db "Результат (unsigned): ", 0
    len_result_unsigned_msg equ $ - result_unsigned_msg
    newline db 10

section .text
    global _start
    extern compute_signed_char
    extern compute_unsigned_int

_start:
    ; Ввод a
    mov eax, 4
    mov ebx, 1
    mov ecx, input_a_msg
    mov edx, len_input_a_msg
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, input_a
    mov edx, 20
    int 0x80
    mov byte [input_a + eax - 1], 0

    push ecx
    call str_to_int
    add esp, 4
    cmp ebx, 0
    jne invalid_input

    ; Сохраняем для signed
    cmp eax, -128
    jl invalid_input
    cmp eax, 127
    jg invalid_input
    mov [a_char], al

    ; Сохраняем для unsigned
    cmp eax, 0
    jl invalid_input
    mov [a_uint], eax

    ; Ввод b
    mov eax, 4
    mov ebx, 1
    mov ecx, input_b_msg
    mov edx, len_input_b_msg
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, input_b
    mov edx, 20
    int 0x80
    mov byte [input_b + eax - 1], 0

    push ecx
    call str_to_int
    add esp, 4
    cmp ebx, 0
    jne invalid_input

    ; Сохраняем для signed
    cmp eax, -128
    jl invalid_input
    cmp eax, 127
    jg invalid_input
    mov [b_char], al

    ; Сохраняем для unsigned
    cmp eax, 0
    jl invalid_input
    mov [b_uint], eax

    ; Ввод c
    mov eax, 4
    mov ebx, 1
    mov ecx, input_c_msg
    mov edx, len_input_c_msg
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, input_c
    mov edx, 20
    int 0x80
    mov byte [input_c + eax - 1], 0

    push ecx
    call str_to_int
    add esp, 4
    cmp ebx, 0
    jne invalid_input

    ; Сохраняем для signed
    cmp eax, -128
    jl invalid_input
    cmp eax, 127
    jg invalid_input
    mov [c_char], al

    ; Сохраняем для unsigned
    cmp eax, 0
    jl invalid_input
    mov [c_uint], eax

    ; Вычисление signed
    call compute_signed_char
    mov eax, [result_char]       ; Читаем полный 32-битный результат
    call int_to_str
    mov eax, 4
    mov ebx, 1
    mov ecx, result_signed_msg
    mov edx, len_result_signed_msg
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, esi
    mov edx, edi
    int 0x80

    ; Перенос строки
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    ; Вычисление unsigned
    call compute_unsigned_int
    mov eax, [result_uint]
    call int_to_str_unsigned
    mov eax, 4
    mov ebx, 1
    mov ecx, result_unsigned_msg
    mov edx, len_result_unsigned_msg
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, esi
    mov edx, edi
    int 0x80

    ; Перенос строки
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    jmp exit

invalid_input:
    mov eax, 4
    mov ebx, 1
    mov ecx, error_invalid_input
    mov edx, len_error_invalid_input
    int 0x80

exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80

; Функция str_to_int: преобразует строку в число
; Возвращает число в eax, ebx = 0 если успех; ebx = 1 если ошибка
str_to_int:
    push ebp
    mov ebp, esp

    mov esi, [ebp + 8]  ; esi = указатель на строку
    xor eax, eax
    xor ebx, ebx
    mov edi, 0          ; Флаг знака, 0 = положительное, 1 = отрицательное

    ; Пропуск пробелов
.skip_whitespace:
    mov al, byte [esi]
    cmp al, ' '
    je .inc_esi
    cmp al, 9
    je .inc_esi
    jmp .check_sign

.inc_esi:
    inc esi
    jmp .skip_whitespace

.check_sign:
    mov al, byte [esi]
    cmp al, '-'
    jne .read_digits
    mov edi, 1          ; Отрицательное число
    inc esi
    jmp .read_digits

.read_digits:
    mov al, byte [esi]
    cmp al, 0
    je .end_conversion
    cmp al, '0'
    jb .error
    cmp al, '9'
    ja .error
    sub al, '0'         ; Преобразование символа в цифру
    movzx edx, al       ; edx = цифра
    imul eax, eax, 10
    add eax, edx
    inc esi
    jmp .read_digits

.error:
    mov ebx, 1          ; Установить флаг ошибки
    jmp .done

.end_conversion:
    cmp edi, 1
    jne .done
    neg eax

.done:
    pop ebp
    ret

; Функция int_to_str: преобразует число в строку (знаковое)
; Результат в esi, длина в edi
int_to_str:
    push ebp
    mov ebp, esp

    mov esi, result_str + 11
    mov byte [esi], 0   ; Нуль-терминатор
    mov edi, 0          ; Счётчик длины
    dec esi             ; Уменьшаем esi для записи символов

    mov ecx, eax        ; Число для преобразования
    mov bl, 0           ; Флаг отрицательного числа

    cmp ecx, 0
    jge .convert_digits
    neg ecx
    mov bl, 1           ; Число отрицательное

.convert_digits:
    ; Цикл преобразования числа в строку
.convert_loop:
    mov eax, ecx
    xor edx, edx
    mov ebx, 10
    div ebx             ; eax = eax / 10, edx = остаток
    add dl, '0'         ; Преобразуем цифру в символ
    mov [esi], dl
    dec esi
    inc edi
    mov ecx, eax
    cmp eax, 0
    jne .convert_loop

    cmp bl, 1
    jne .done
    mov byte [esi], '-'
    dec esi
    inc edi

.done:
    inc esi             ; Увеличиваем esi до начала строки
    pop ebp
    ret

; Функция int_to_str_unsigned: преобразует число в строку (беззнаковое)
; Результат в esi, длина в edi
int_to_str_unsigned:
    push ebp
    mov ebp, esp

    mov esi, result_str + 11
    mov byte [esi], 0   ; Нуль-терминатор
    mov edi, 0          ; Счётчик длины
    dec esi             ; Уменьшаем esi для записи символов

    mov ecx, eax        ; Число для преобразования

.convert_loop_unsigned:
    mov eax, ecx
    xor edx, edx
    mov ebx, 10
    div ebx             ; eax = eax / 10, edx = остаток
    add dl, '0'         ; Преобразуем цифру в символ
    mov [esi], dl
    dec esi
    inc edi
    mov ecx, eax
    cmp eax, 0
    jne .convert_loop_unsigned

    inc esi             ; Увеличиваем esi до начала строки
    pop ebp
    ret

