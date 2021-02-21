;   movzx   : move the content of a register in a greater register
;   sub     : subtraction between two argument, save in the 1st argument

segment .text
        global  _ft_strcmp

_ft_strcmp:
        mov     rcx, 0                  ;   set rcx to 0
        jmp     compare                 ;   jump to compare

compare:
        mov     al, BYTE [rdi + rcx]    ;   move in al the content of rdi
        mov     bl, BYTE [rsi + rcx]    ;   move in bl the content of rsi
        cmp     al, bl                  ;   if al = bl
        je      equal                   ;   jump to equal
        jmp     return                  ;   jump to return

equal:
        cmp     al, 0;                  ;   if al == 0
        je      return                  ;   return
        cmp     bl, 0;                  ;   if bl == 0
        je      return                  ;   return
        inc     rcx                     ;   rcx++
        jmp     compare                 ;   jump to compare

return:
        movzx   rax, al                 ;   move in rax the content of al
        movzx   rbx, bl                 ;   move in rax the content of bl
        sub     rax, rbx                ;   rax - rbx
        ret                             ;   return rax
