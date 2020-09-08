%define MATCH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4
%define READ				3
%define STDOUT				1

global _ft_cat

section .data
buffer:
	.mem times 1000 db 0
	.size equ $ - buffer.mem

section .text
_ft_cat:
	push rdi
	lea rsi, [rel buffer.mem]
	mov rdx, buffer.size
	mov rax, MATCH_SYSCALL(READ)
	syscall
	cmp rax, 0
	jle end
	mov rdx, rax
	mov rdi, STDOUT
	mov rax, MATCH_SYSCALL(WRITE)
	syscall
	cmp rax, 0
	jle end
	pop rdi
	jmp _ft_cat

end:
	leave
	ret
