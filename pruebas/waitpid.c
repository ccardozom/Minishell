#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	pid_t id_padre;
	pid_t id_hijo;
	int estado;

	printf("Ejemplo de waitpid.\n");
	printf("Inicio proceso padre. PID = %d\n",getpid());
	id_padre = getpid();
	if ((id_hijo = fork()) == 0)
	{
		printf("Inicio proceso hijo. PID = %d PPID = %d\n",getpid(), id_padre);
		sleep(3);
		printf("Salida proceso hijo. PID = %d\n", getpid());
		exit (getpid() > id_padre);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		while(waitpid(id_hijo, &estado, WNOHANG) != id_hijo);
		if (WIFEXITED(estado))
			printf("El proceso hijo ha recibido la señal %d\n", WTERMSIG(estado));
		if (WIFEXITED(estado))
		{
			if (WIFEXITED(estado) == 1)
				printf("PID hijo > PID padre.\n");
			else
				printf("PID padre > PID hijo.\n");
		}
		printf("FIN DEL PROCESO %d\n", getpid());
		exit(0);
		
	}
}
