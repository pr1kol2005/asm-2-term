global main
extern printf
extern scanf

section .text

gcd:
  mov ecx, edx

  loop:
  test ecx, ecx
  jz endloop
      
    cdq
    div ecx

    mov eax, ecx
    mov ecx, edx

  jmp loop
  endloop:

  ret

main:
  push A
  push format
  call scanf
  add esp, 8

  push B
  push format
  call scanf
  add esp, 8

  mov eax, [A]
  mov edx, [B]
  call gcd
  
  mov ecx, eax
  mov eax, [A]
  cdq
  div ecx
  mov ecx, [B]
  mul ecx

  push eax
  push format
  call printf
  add esp, 8

  xor eax, eax
  ret

section .data
  format db "%d", 0

section .bss
  A resd 1
  B resd 1
