section .data
  msg db "Liberté, égalité, fraternité!", 0xA

section .text
  global main

main:
  mov rax, 1
  mov rdi, 1
  mov rsi, msg
  mov rdx, 34
  syscall

  mov rax, 60
  xor rdi, rdi
  syscall
