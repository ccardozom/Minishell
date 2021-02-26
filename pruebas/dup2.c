#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

int main (int contargs, char *args[])
{
	int fd;

	fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("fallo en open");
		exit(EXIT_FAILURE);
	}	
	if (dup2(fd, 1) == -1)
	{
		perror("fallo en dup2");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		perror("fallo en close");
		exit(EXIT_FAILURE);
	}
	printf("HOLA MUNDO");
}
