section .data
	message db 'Hello, Holberton', 0Ah, 0

section .text
	global main

	extern printf

main:
	push message
	mov	rdi, message
	mov	rax, 0
	call printf
	add	rsp, 8

	xor	eax, eax
	ret

