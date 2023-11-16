section .data
	hello db 'Hello, Holberton', 0

section .text
	global main

	extern printf
	section .text

main:
	mov rdi, hello
	call printf

	; Exit the program
	mov rax, 60         ; syscall: exit
	xor rdi, rdi        ; status: 0
	syscall
