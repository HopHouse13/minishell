

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_node	*list;

	(void)av; // utilisation de av pour pourvoir compiler sans erreurs.
	if (ac == 1)
	{
		while (1)
		{
			ft_manag_signals(); // fonction gestion signal_des_touches? -> ctrl+c/ctrl+d/crtl+'\'
			ft_manag_build_list(&list);
			ft_manag_exec(&list, &env);
			ft_manag_free(&list)
		}
		ft_printf("ok\n"); // savoir si tout s'est bien passe
	}
	else
	{
		errno = EINVAL; // code error du nombre d'arg inscrit dans la macro errno.
		perror("Error main ");
		exit(EXIT_FAILURE);
	}
}
