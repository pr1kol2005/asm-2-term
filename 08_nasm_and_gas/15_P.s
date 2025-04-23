extern printf
extern scanf
global main

section .text

rec:
  sub esp, 8
  movsd [esp], xmm1

  sub esp, 8
  movsd [esp], xmm2
  movsd xmm2, [zero]

  function_loop:
    movq xmm1, xmm0

    cmplesd xmm1, [one]
    movd eax, xmm1
    test eax, eax
    jnz return

    addsd xmm2, xmm0
    subsd xmm2, [one]

    sub esp, 8
    movsd [esp], xmm0
    divsd xmm0, [three]
    call rec
    addsd xmm2, xmm0
    movsd xmm0, [esp]
    add esp, 8
    divsd xmm0, [two]
  jmp function_loop

  return:
    movq xmm0, xmm2

    movsd xmm2, [esp]
    add esp, 8

    movsd xmm1, [esp]
    add esp, 8
  ret


main:
  push x
  push format
  call scanf
  add esp, 8

  movsd xmm0, [x]
  call rec

  sub esp, 8
  movsd [esp], xmm0
  push format
  call printf
  add esp, 12

  xor eax, eax
  ret

section data
  format db  "%lf", 0
  zero dq 0.0
  one dq 1.0
  two dq 2.0
  three dq 3.0

section .bss
  x   resq 1
