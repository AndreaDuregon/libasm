segment .text
		global _ft_list_remove_if
		extern _free

_ft_list_remove_if:
		cmp		rdi, 0					; if list_begin == NULL
		je		return					; return
		cmp		rsi, 0					; if data == NULL
		je		return					; return
		mov		r10, [rdi]				; r10 = begin_list
		jmp		iter					; jump to iter

iter:
		mov		r9, [r10 + 8]			; r9 = list->next
		cmp		r9, 0					; if list->next == NULL
		je		cmp_begin				; jump to comp_begin
		push	rdi						; save list_begin
		push	rsi						; save data
		mov		rdi, [r9]				; rdi = list->next->data
		call	rdx						; cmp(list->next->data, data)
		pop		rsi						; pop data
		pop		rdi						; pop begin_list
		cmp		rax, 0					; if list->next->data == data
		je		free_el					; free element
		jmp		next					; else jump to next

free_el:
		push	rdi						; save begin_list
		push	rsi						; save data
		mov		r9, [r10 + 8]
		mov		rdi, [r9]			; rdi = list->next->data
		call	rcx						; free(list->next->data)
		jmp fake_exit		
		mov		r8, [r9 + 8]			; r8 = list->next->next
		mov		[r10 + 8], r8			; list->next = list->next->next
		mov		rdi, r9					; rdi = list->next
		call	_free					; free(list->next)
		pop		rsi						; pop data
		pop		rdi						; pop begin_list
		jmp		iter					; jump to iter

next:
		mov		r8, [r10 + 8]		; r8 = rdi->next
		cmp		r8, 0				; if rdi->next = NULL
		je		return				; return
		mov		r10, r8				; rdi = rdi->next
		jmp		iter				; jump to iter

cmp_begin:
		jmp		return

fake_exit:
		pop rsi
		pop rdi
		ret

return:
		ret