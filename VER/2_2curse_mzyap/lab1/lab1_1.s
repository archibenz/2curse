.text
.global _start
_start:
    LDR R0, =0xFF200040
    LDR R1, =ARR
    MOV R2, #3

LOOP:
    LDR R3, [R0]
    STR R3, [R1], #4
    SUBS R2, #1
    BNE LOOP
AB:
    B AB

ARR: .word 0, 0, 0
.end