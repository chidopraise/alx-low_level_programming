#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(const char *filename);

/**
 * main - Entry point for the ELF header display program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	const char *elf_filename = argv[1];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    display_elf_header(elf_filename);

    return 0;
}

/**
 * display_elf_header - Displays information contained in the ELF header of the given ELF file.
 * @filename: Path to the ELF file.
 */
void display_elf_header(const char *filename) {
    int fd = open(filename, O_RDONLY);
    int i;
    Elf64_Ehdr elf_header;

    if (fd == -1) {
        perror("Error");
        exit(98);
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error: Unable to read ELF header from file %s\n", filename);
        close(fd);
        exit(98);
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: %s is not an ELF file\n", filename);
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf(" %02x", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" : "Other");
    printf("  Entry point address:               %lx\n", (unsigned long) elf_header.e_entry);

    close(fd);
}
