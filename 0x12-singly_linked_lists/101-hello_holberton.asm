section .data
	hello db 'Hello, Holberton', 0

section .text
	global main

	extern printf
	section .text

main:
	mov rdi, hello
	mov rax, 1
	call printf

	; Exit the program
	mov eax, 60         ; syscall: exit
	xor edi, edi        ; status: 0
	syscall
