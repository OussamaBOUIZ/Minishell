/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:43:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 13:09:05 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	print_args(char **args)
{
	int i;

	i = -1;
	if (!args)
		printf("args : NULL\n");
	else
	{
		printf("args : {");
		while (args[++i])
			printf("%s, ", args[i]);
		printf("%s", args[i]);
		printf("}\n");
	}
}

void print_parsing_lst(t_cmdl *cmd)
{
    while(cmd)
    {
        printf("-------------------------------\n");
        printf("idx : %d\n", cmd->idx);
        printf("path : %s\n", cmd->path);
		print_args(cmd->args);
        printf("in fd : %d\n", cmd->in_fd);
        printf("out fd : %d\n", cmd->out_fd);
        printf("isbuiltin : %d\n", cmd->builtin);
        printf("-------------------------------\n");
        cmd = cmd->next;
    }
}

t_cmdl	*parser(t_envl *envl)
{
	char		*red_line;
	t_toklist	*tokens;
	t_cmdl		*cmd_line;
	
	red_line = NULL;
	red_line = readline("Minishell pre-α $> ");
	if (red_line[0])
	{
		add_history(red_line);
		if (check_unrequired_by_subject(red_line) != 0)
			free(red_line);
		else
		{
			red_line = expander(envl, red_line);
			tokens = lexer(red_line);
			print_tokens(tokens->next);
			cmd_line = parse_list(tokens->next, shell.env);
			free(red_line);
			return (cmd_line);
		}
	}
	return (NULL);
}