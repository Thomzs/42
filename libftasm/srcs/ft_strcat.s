global _ft_strcat

section .text
_ft_strcat:
	push rdi
	cmp rsi, 0
	je end

go_end:
	cmp [rdi], byte 0
	je fill
	inc rdi
	jmp go_end

fill:
	cmp [rsi], byte 0
	je end
	mov rdx, [rsi]
	mov [rdi], rdx 
	inc rsi
	inc rdi
	jmp fill

end:
	pop rax
	ret
