section .data
	hello db 'Hello, Holberton', 0

section .text
	global main

	extern printf
	section .text

main:
	sub rsp, 8             ; Align the stack

	mov rdi, hello
	call printf

	add rsp, 8             ; Restore the stack

	; Exit the program
	mov eax, 0             ; syscall: exit
	ret
