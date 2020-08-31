global _ft_strlen

section .text
_ft_strlen:
	mov rax, 0
	cmp rdi, 0
	je end

beg:
	cmp [rdi], byte 0
	je end
	inc rax
	inc rdi
	jmp beg

end:
	ret	
