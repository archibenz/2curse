.text
.global _start
_start:
    LDR R0, =ARR_A
    LDR R1, =ARR_B
    LDR R2, N
    MOV R3, #0
LOOP:
    LDR R4, [R0], #4
    LDR R5, [R1], #4
    MLA R3, R4, R5, R3
    SUBS R2, R2, #1
    BGT LOOP
    STR R3, RESULT
STOP:
    B STOP

N:      .word 4
ARR_A:  .word 5, -3, -6, 9
ARR_B:  .word 2, 14, -3, 2
RESULT: .space 4
.end