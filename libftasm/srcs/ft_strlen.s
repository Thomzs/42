global _ft_strlen

section .text
_ft_strlen:
	mov al, 0
	cmp rdi, 0
	je end
	sub rcx, rcx
	not rcx
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx

end:
	ret	
