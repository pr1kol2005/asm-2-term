extern printf
extern scanf
global main

section .text
main:
  push A
  push format
  call scanf
  add esp, 8

  push B
  push format
  call scanf
  add esp, 8

  movsd xmm0, [A]
  divsd xmm0, [B]
  movsd [A],  xmm0

  sub esp, 8
  movsd [esp], xmm0
  push format
  call printf
  add esp, 12

  xor eax, eax
  ret

section .data:
format db "%lf", 0

section .bss
A resq 1
B resq 1
