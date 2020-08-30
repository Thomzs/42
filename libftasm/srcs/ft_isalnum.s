global _ft_isalnum
extern _ft_isdigit
extern _ft_isalpha

section .text
_ft_isalnum:
	call _ft_isdigit
	cmp eax, 1
	je yes
	call _ft_isalpha
	cmp eax, 1
	je yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
