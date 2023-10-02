#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * print_elf_header_info - Displays information from the ELF header of an
 * ELF file.
 *
 * @header: Pointer to the ELF header structure to extract information from.
 *
 * This function takes an ELF header structure as input and displays the
 * following information:
 * - Magic number
 * - ELF class (32-bit or 64-bit)
 * - Data encoding (little-endian or big-endian)
 * - ELF version
 * - OS/ABI (Operating System/Application Binary Interface)
 * - ABI Version
 * - File type (e.g., executable, shared object)
 * - Entry point address
 *
 * The information is displayed in a format similar to 'readelf -h'.
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("	Magic:	");
	for (i = 0; i < EI_NIDENT; i++)
	{
	printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("	Class:	");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
	printf("ELF32\n");
	break;
	case ELFCLASS64:
	printf("ELF64\n");
	break;
	default:
	printf("Unknown\n");
	break;
	}

	printf("	Data:	");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
	printf("2's complement, little endian\n");
	break;
	case ELFDATA2MSB:
	printf("2's complement, big endian\n");
	break;
	default:
	printf("Unknown\n");
	break;
	}

	printf("	Version:	%d (current)\n", header->e_ident[EI_VERSION]);
	printf("	OS/ABI:	");
	switch (header->e_ident[EI_OSABI]) {
	case ELFOSABI_SYSV:
	printf("UNIX - System V\n");
	break;
	case ELFOSABI_HPUX:
	printf("UNIX - HP-UX\n");
	break;
	case ELFOSABI_NETBSD:
	printf("UNIX - NetBSD\n");
	break;
	case ELFOSABI_LINUX:
	printf("UNIX - Linux\n");
	break;
	case ELFOSABI_SOLARIS:
	printf("UNIX - Solaris\n");
	break;
	case ELFOSABI_IRIX:
	printf("UNIX - IRIX\n");
	break;
	case ELFOSABI_FREEBSD:
	printf("UNIX - FreeBSD\n");
	break;
	case ELFOSABI_TRU64:
	printf("UNIX - TRU64\n");
	break;
	case ELFOSABI_ARM:
	printf("ARM\n");
	break;
	case ELFOSABI_STANDALONE:
	printf("Standalone App\n");
	break;
	default:
	printf("UNIX - Unknown\n");
	break;
	}

	printf("	ABI Version:	%d\n", header->e_ident[EI_ABIVERSION]);
	printf("	Type:	");
	switch (header->e_type) {
	case ET_NONE:
	printf("No file type\n");
	break;
	case ET_REL:
	printf("Relocatable file\n");
	break;
	case ET_EXEC:
	printf("Executable file\n");
	break;
	case ET_DYN:
	printf("Shared object file\n");
	break;
	case ET_CORE:
	printf("Core file\n");
	break;
	default:
	printf("Unknown (%#x)\n", header->e_type);
	break;
	}

	printf("	Entry point address:	%#lx\n", header->e_entry);
}


/**
 * main - The entry point of the ELF header information display program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * This function performs the following tasks:
 * 1. Validates the command-line arguments and checks if the correct number
 * of arguments is provided.
 * 2. Opens the specified ELF file for reading and performs error checking.
 * 3. Reads and parses the ELF header of the file, displaying information using
 * the print_elf_header_info function.
 * 4. Checks if the file is a valid ELF file, displaying an error message if
 * it's not.
 * 5. Exits with a status code of 98 and an error message if any errors occur
 * during file operations or if the file is not valid.
 *
 * Return: 0 on successful execution, otherwise exits with a status code of
 * 98 on error.
 */
int main(int argc, char *argv[])
{
	const char *elf_filename = argv[1];
	int fd = open(elf_filename, O_RDONLY);
	struct stat st;

	Elf64_Ehdr header;

	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	return (98);
	}

	if (fd == -1)
	{
	perror("Error");
	return (98);
	}

	if (fstat(fd, &st) == -1)
	{
	perror("Error");
	close(fd);
	return (98);
	}

	if ((off_t)st.st_size < (off_t)sizeof(Elf64_Ehdr))
	{
	fprintf(stderr, "Error: File is not a valid ELF file.\n");
	close(fd);
	return (98);
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
	perror("Error");
	close(fd);
	return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
	fprintf(stderr, "Error: File is not a valid ELF file.\n");
	close(fd);
	return (98);
	}

	print_elf_header_info(&header);

	close(fd);
	return (0);
}

