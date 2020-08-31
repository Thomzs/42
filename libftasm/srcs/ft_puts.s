%define MATCH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

global _ft_puts
extern _ft_strlen

section .data
newline:
	.string db 10
	.len equ $ - newline.string

section .text
_ft_puts:
	cmp rdi, 0
	je no
	push rdi
	call _ft_strlen
	pop rsi
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MATCH_SYSCALL(WRITE)
	syscall
	cmp eax, -1
	je no

yes:
	lea rsi, [rel newline.string]
	mov rdx, newline.len
	mov rax, MATCH_SYSCALL(WRITE)
	syscall
	mov rax, 1
	ret

no:
	mov rax, -1
	ret
