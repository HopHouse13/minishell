

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_node	*list;
	char	*cmds_brut;

	(void)env;
	(void)av; // utilisation de av pour pourvoir compiler sans erreurs.
	if (ac == 1)
	{
		while (1)
		{
			ft_signals(); // fonction gestion signal_des_touches? -> ctrl+c/ctrl+d/crtl+'\'
			ft_make_input();
			cmds_brut = readline("minishell :");
			if (!cmds_brut)
			{
				if (errno)
					perror("error main ");
				else
					ft_printf("Exit minishell\n");	// en cas de ctrl+D quand on est entrain de remplir le heredoc. je pense devoir gerer le crtl ailleurs.
			}
			else
				if (ft_checks_cmds(&cmds_brut))		// controle de la syntaxe (l'ordre des elements est il correction selon leurs types? 
					ft_list_manag(&cmds_brut);		// types -> operateurs de redirection ( |, <, <<, >, >>) ou cmds ou arguments de la cmds.
		}
		



		free(cmds_brut);
		ft_printf("ok\n"); // savoir si tout s'est bien passe
	}
	else
	{
		errno = EINVAL; // code error du nombre d'arg inscrit dans la macro errno.
		perror("Error main ");
		exit(EXIT_FAILURE);
	}
}
