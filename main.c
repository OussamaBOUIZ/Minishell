/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:32 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 19:41:25 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "./Header/minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac; 
	(void)av;
	t_cmdl	*cmd_line;
	int fd;

	fd = dup(0);
	shell.env = set_env(env);
	while (1)
	{
		handle_signals();
		cmd_line = parser(shell);
		// print_parsing_lst(cmd_line);
		// exit(0);
		execute(cmd_line, shell, env);
		dup2(fd, STDIN_FILENO);
	}
	return (0);
}