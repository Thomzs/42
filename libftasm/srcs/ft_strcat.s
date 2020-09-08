global _ft_strcat

section .text
_ft_strcat:
	push rdi
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end

go_end:
	cmp [rdi], byte 0
	je fill
	inc rdi
	jmp go_end

fill:
	mov rdx, [rsi]
	mov [rdi], rdx 
	inc rsi
	inc rdi
	cmp [rsi], byte 0
	je end
	jmp fill

end:
	pop rax
	ret
