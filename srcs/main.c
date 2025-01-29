

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data
	(void)av; // utilisation de av pour pourvoir compiler sans erreurs.
	if (ac == 1)
	{
		printf("ok\n");
	}
	else
	{
		errno = EINVAL; // code error du nombre d'arg inscrit dans la macro errno.
		perror("Error main ");
		exit(EXIT_FAILURE);
	}
}