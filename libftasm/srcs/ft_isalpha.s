global _ft_isalpha

section .text
_ft_isalpha:
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jle yes
	cmp rdi, 122
	jg no
	cmp rdi, 97
	jge yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
