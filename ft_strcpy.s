;   rsi : 2nd argument
;   cl  : 8bit of ECX register

segment .text
        global _ft_strcpy

_ft_strcpy:
        mov     rax, 0                  ; set rax to 0
        jmp     copy                    ; jump to copy

copy:
        mov     cl, BYTE[rsi + rax]     ; move in cl the content of rsi
        mov     BYTE[rdi + rax], cl     ; move in rdi the content of cl
        cmp     BYTE[rsi + rax], 0      ; compare rsi + rax with 0
        je      return                  ; if cmp = 0 (equal) jump to return
        inc     rax                     ; increment rax
        jmp     copy                    ; re-jump to copy

return:
        mov     rax, rdi                ; move in rax the content of rdi
        ret                             ; return rax