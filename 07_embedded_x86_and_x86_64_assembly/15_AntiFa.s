mov ebx, 1
mov ecx, 1
mov edx, eax

antifa:
    cmp edx, ebx
    je done

    inc ecx
    imul ebx, ecx
    jmp antifa

done:
    mov eax, ecx
    mov ebx, eax
