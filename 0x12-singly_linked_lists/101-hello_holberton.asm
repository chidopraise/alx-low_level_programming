section .data
	hello db 'Hello, Holberton', 1

section .text
	global main

	extern printf
	section .text

main:
	mov rdi, hello
	mov rax, 0        ; printf syscall number
	call printf

	; Exit the program
	mov eax, 60       ; syscall: exit
	xor edi, edi      ; status: 0
	syscall
