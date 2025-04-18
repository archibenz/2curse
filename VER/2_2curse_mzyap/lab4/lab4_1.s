.text
.global _start

_start:         ldr r0, =0xff200000

met1:           ldr r1, [r0, #0x50]
                tst r1, #1
                bne progA
                tst r1, #2
                bne progDATA

                movw r2, #0x4949
                str r2, [r0, #0x20]
dl:             ldr r3, =0xa0000000
dl1:            subs r3, r3, #1
                bne dl
                b met1

progA:          mov r7, #0
                str r7, [r0, #0x20]
                ldr r1, CNT
m1:             movw r5, 0x7700
                mov r3, #2

MET:            str r5, [r0, #48]
                lsr r5, r5, #8
                ldr r2, DEL
LOOP:           subs r2, r2, #1
                bne LOOP
                subs r3, r3, #1
                bne MET

                str r7, [r0, #48]
                mov r5, #0
                movt r5, 0x7700
                mov r3, #4

MET1:           str r5, [r0, #32]
                lsr r5, r5, #8
                ldr r2, DEL
LOOP1:          subs r2, r2, #1
                bne LOOP1
                subs r3, r3, #1
                bne MET1

                str r7, [r0, #32]
                adds r1, r1, #1
                bne m1
                b met1

progDATA:       mov r8, #5
CYCLE:          ldr r6, =ARR_A
                ldr r7, =ARR_B
                mov r2, #16

MET4:           ldr r4, [r6], #4
                ldr r5, [r7], #4
                str r5, [r0, #32]
                ldr r3, DEL
LOOP3:          subs r3, r3, #1
                bne LOOP3
                str r4, [r0, #32]
                subs r2, r2, #1
                bne MET4
                subs r8, r8, #1
                bne CYCLE

                b met1

CNT:        .word 0xff200020
DEL:        .word 0x200000

ARR_A:      .word 0x0b56, 0x0b66, 0x0b66, 0x85608, 0x85608, 0x3f58603f, 0x66683f4f, 0x83f4f48f
ARR_B:      .word 0x3f4f085b, 0x3f5b3f, 0x3f5b3f5b, 0x3f58603f, 0x3f58603f, 0x3f58603f, 0x3f58603f, 0x3f58603f

.end