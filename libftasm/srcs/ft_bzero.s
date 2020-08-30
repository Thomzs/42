global _ft_bzero

section .text
_ft_bzero:
	cmp rsi, 0
	je end
	mov [rdi], byte 0
	inc rdi
	dec rsi
	jmp _ft_bzero

end:
	ret
