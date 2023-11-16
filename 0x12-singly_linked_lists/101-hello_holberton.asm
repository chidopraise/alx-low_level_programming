section .data
	hello db 'Hello, Holberton', 0

section .text
	global _start

_start:
	; write the string to stdout
	mov eax, 4            ; syscall: write
	mov ebx, 1            ; file descriptor: stdout
	mov ecx, hello        ; pointer to the string
	mov edx, 17           ; length of the string
	int 0x80              ; interrupt to invoke syscall

	; exit the program
	mov eax, 1            ; syscall: exit
	xor ebx, ebx          ; exit code 0
	int 0x80              ; interrupt to invoke syscall
