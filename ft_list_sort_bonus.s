segment .text
		global _ft_list_sort

_ft_list_sort:
		cmp		rdi, 0				; if list_begin == NULL
		je		return				; return
		mov     r9, [rdi]			; r9 = *list_begin
		mov     r10, rsi			; r10 = cmp
		jmp     iter				; jmp to iter

iter:
		mov		rbx, [r9 + 8]		; rbx = rdi->next
		cmp		rbx, 0				; if list->next = NULL
		je		return				; return
		push	rdi					; save list_begin
		push	rsi					; save camp
		mov		rdi, [r9]			; rdi = rdi.data
		mov		rsi, [rbx]			; rsx = rbx.data
		call	r10					; call compare
		pop		rsi					; pop rsi
		pop		rdi					; pop rdi
		cmp		rax, 0				; if cmp > 0
		jg		to_sort				; need to sort
		jmp		is_sort				; else is sort

to_sort:
		mov		r11, [r9]			; r11 = rdi->data
		mov		r12, [rbx]			; r12 = rdi->next->data
		mov		[r9], r12			; r9 = r11
		mov		[rbx], r11			; rbx = rdi->next->data
		mov		r9, [rdi]			; r9 = *begin_lst
		jmp		iter				; jump to iter

is_sort:
		mov		r8, [r9 + 8]		; r8 = rdi->next
		cmp		r8, 0				; if rdi->next = NULL
		je		return				; return
		mov		r9, r8				; rdi = rdi->next
		jmp		iter				; jump to iter

return:
		ret							; return
