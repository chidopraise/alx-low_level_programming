#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_elf_header - Displays information from the ELF header.
 * @header: Pointer to the ELF header structure.
 *
 * This function prints information from the ELF header to the console.
 */
void display_elf_header(const Elf64_Ehdr *header);

/**
 * main - Entry point for the ELF header display program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This program reads and displays information
 * from the ELF header of an ELF file.
 * Usage: elf_header elf_filename
 * It exits with status code 98 and displays an error message
 * if the file is not an ELF file or on other errors.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	if (fd == -1)
	{
		perror("Error");
		exit(98);
	}

	Elf64_Ehdr elf_header;

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		fprintf(stderr, "Error: Unable to read ELF header\n");
		close(fd);
		exit(98);
	}

	display_elf_header(&elf_header);

	close(fd);
	return (0);
}

void display_elf_header(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:%s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:%s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("  Version:%d\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:%d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:%d\n", header->e_type);
	printf("  Entry point address:%lx\n", (unsigned long)header->e_entry);
}
