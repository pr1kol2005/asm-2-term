extern printf
extern scanf
global main

section .text
main:
  push A
  push format
  call scanf
  
  movsd xmm0, [A]

  movsd xmm1, [zero]
  cmpnlesd xmm1, [A]
  movd eax, xmm1
  
  test eax, eax
  jz pos
  mulsd xmm0, [negative]
  pos:
  
  movsd [esp], xmm0
  push format
  call printf
  add esp, 12
  
  xor eax, eax
  ret

section .data:
  format db "%lf", 0
  zero dq +0.0
  negative dq -1.0

section .bss
  A resq 1
