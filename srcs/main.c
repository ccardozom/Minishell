#include "../include/minishell.h"

int main(int argc, char *argv[], char *env[])
{
	t_all mini;
	
	mini.exit=0;
	capture_env(&mini, env);
	mini.line = strdup("");
	while (mini.exit == 0)
	{
		write(1,"minishell: ",12);
		mini.fd = read(0, mini.line, 1024);
		if (!mini.line)
			mini.line = "\n";
		else
			;
			
		printf("%s",mini.line);
	}
	return (0);
}

