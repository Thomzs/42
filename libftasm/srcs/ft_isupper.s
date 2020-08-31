global _ft_isupper

section .text
_ft_isupper:
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jle yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
