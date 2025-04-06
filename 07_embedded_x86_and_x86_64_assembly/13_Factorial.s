cmp al, 0
jbe zero

movzx edx, al
mov ecx, edx

cmp ecx, 0
jbe done

mov eax, 1

loop:
    cmp ecx, 1
    jbe done
    imul eax, ecx
    dec ecx
    jmp loop

zero:
    mov eax, 1

done:
    mov edx, eax