global _ft_isdigit

section .text
_ft_isdigit:
	cmp rdi, 48
	jl no
	cmp rdi, 57
	jle yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret	
