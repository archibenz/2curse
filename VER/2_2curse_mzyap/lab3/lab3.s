    .global _start
_start: 
ldr r0,=0xff200020
movw r1,0x5874
movt r1,0x5c54
str r1,[r0],#16
mov r1,#0x7c
str r1,[r0]
st: b st
.end
