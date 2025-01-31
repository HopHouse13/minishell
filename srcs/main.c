

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	//t_data	data;
	char	*input_line;
	(void)env;
	(void)av; // utilisation de av pour pourvoir compiler sans erreurs.
	if (ac == 1)
	{
		// line pour initialiser  je sais pas quoi ecnore (structure?)
		while (1)
		{
			// fonction signal_des_touches? -> ctrl+c/ctrl+d
			input_line = readline("minishell :");
			if (!input_line)
			{
				errno = //chercher code erreur aucune valeur d'entree
				perror("error main ");
			}
		}
		



		free(input_line);
		ft_printf("ok\n"); // savoir si tout s'est bien passe
	}
	else
	{
		errno = EINVAL; // code error du nombre d'arg inscrit dans la macro errno.
		perror("Error main ");
		exit(EXIT_FAILURE);
	}
}