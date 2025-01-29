/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:06:45 by swendum           #+#    #+#             */
/*   Updated: 2025/01/27 15:18:57 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>

extern int	g_sig;

typedef struct s_monke
{
	size_t			j;
	size_t			t;
	size_t			c;
	size_t			w;
	int				p;
	int				d;
	int				s;
	unsigned char	bol;
	int				quotes;
}		t_monke;

typedef struct s_data
{
	char	**cmd;
	char	*token;
	char	**env;
	int		*id;
	int		*pfd;
	int		status;
	int		heredoc;
	int		expension;
}		t_data;

int		parsing(char *line, long unsigned int i, t_data *data);
int		ft_neosplit(const char *s, t_data *data);
int		count_pipes(t_data *data);
t_data	*create_data(char **env, int i);
char	*get_env(char **env, char *str);
void	free_tab(char **tab);
int		clean_data(t_data *data, int i, char *file, char *temp);
char	**extract_exe_only(t_data *data, int i, int u, int j);
void	wait_children(t_data *data);
int		divise_the_thing(t_data *data, int pipes, int i);
void	do_part(t_data *data, int i, int u, int p);
int		do_the_cd(char **cmd, t_data *data, char *newpath, char *path);
void	do_redirection(t_data *data, int i, int fd, int dup);
int		launch(t_data *data, int i);
int		do_direct(t_data *data, int i, int b, int id);
void	close_pfd(int i, t_data *data);
int		reboot_data(t_data *data, int i, char *file, char *temp);
int		do_the_exit(char **cmd, t_data *data);
int		do_the_unset(char **cmd, t_data *data, int i);
int		do_shi_in(t_data *data, int b, int i, char **exe);
int		do_the_export(char **cmd, t_data *data, int i);
int		do_the_echo(char **cmd);
int		do_the_pwd(void);
int		do_the_env(t_data *data);
void	setup_signal_handlers(void);
void	link_heredoc_file(t_data *data, int i);
int		wait_the_doc(t_data *data, int i, char *line, int p);
int		is_empty(char *line);
int		add_env(t_data *data, char *str);
int		get_env_index(char **env, char *str);
char	*get_real_path(char **split_cmd, char *path);
int		grand_remplaced(t_data *data, int i, char *u, int c);
int		domain_expension(t_data *data, char *line);
void	neofilltab(const char *s, t_data *data, size_t i);
int		change_cash(t_data *data, int c, int w, const char *s);
void	tokenisation(t_data *data, int i, int b);
char	**mini_split(char *str, int i, int u);
void	do_nothing(int signo);
int		fix_parsing(t_data *data, int i);
char	*get_next_line_sig(int fd);

#endif
