;   rdi : register for first argument
;   rax : register for return value
;   mov : move value (2nd argument) in register (1st argument)
;   jmp : jump to label
;   cmp : difference between 1st argument and 2nd argument
;   je  : jump if the last command return 0 (equal)
;   inc : increment argument
;   ret : return rax

segment .text
        global  _ft_strlen              ; function name

_ft_strlen:
        mov     rax, 0                  ; set 0 to rax
        jmp     count                   ; jmp to count;

count:
        cmp     BYTE [rdi + rax], 0     ; compare number of byte of rdi and rax
        je      return                  ; if compare = 0 (equal) jump to return
        inc     rax                     ; increment rax (rax++)
        jmp     count                   ; restart count

return:
        ret                             ; return value in rax