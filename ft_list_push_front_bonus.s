segment .text
        global _ft_list_push_front
        extern _malloc

_ft_list_push_front:
		
        push    rdi             ; save head_list
        push    rsi             ; save data
        jmp     insert          ; jump to insert

insert:
        mov     rdi, 16         ; insert in rdi 16 (sizeof(t_list))
		push	rbx
        call    _malloc         ; malloc
		pop		rbx
        pop     rsi             ; pop rsi
        pop     rdi             ; pop rdi
        cmp     rax, 0          ; if malloc fail
        je      return          ; return
        jmp     swap            ; jump to swap

swap:
        mov     [rax], rsi      ; move data in rax
        mov     r9, [rdi]		; move rdi in r9
        mov     [rax + 8], r9	; move rdi address in rax->next
        mov     [rdi], rax		; move rax in rdi
		jmp		return			; jump to return

return:
        ret						; return