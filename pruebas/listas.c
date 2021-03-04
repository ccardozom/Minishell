#include <stdio.h>
#include <stdlib.h>

typedef struct s_lista
{
	char			*dato;
	struct s_lista	*siguiente;
}lista;

typedef struct s_control
{
	struct s_lista	*inicio;
	struct s_lista	*fin;
	int				contador;
} control;

void iniciarcontrol(control *lista)
{
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->contador = 0;
}



int main()
{
	
}