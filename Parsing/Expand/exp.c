/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/15 15:51:10 by ibnada           ###   ########.fr       */
=======
/*   Updated: 2022/10/15 18:40:53 by obouizga         ###   ########.fr       */
>>>>>>> aa49bfff8d19d096ecb0e69914af59e3d12bf1bd
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

    //expand env variable in any given string
    //for example input:echo $USER$USER -> output:ibnadaibnada

char *expand_var_in_str(char *in)
{
    t_exp s;

    struct_init(&s);
    while (in[s.g_i] != '\0')
    {
        if(in[s.g_i] == '<')
        {
            in_here_doc_handle(&s, in);
            // s.g_i++;
            // s.out = ft_strjoin(s.out, "<");
            // if (in[s.g_i]  == '<')
            // {
            //     s.g_i++;
            //     s.out = ft_strjoin(s.out, "<");
            // }
            // while ((in[s.g_i] == ' ' || in[s.g_i] == '\t') && in[s.g_i])
            //     s.g_i++;
            // if (in[s.g_i] == DQ)
            // {
            //     s.g_i++;
            //     s.not_out = get_until_d_quote(&in[s.g_i]);
            //     s.out = ft_strjoin(s.out, s.not_out);
            //     s.g_i += ft_strlen(s.not_out) + 1;
            // }
            // else if (in[s.g_i] == SQ)
            //     sq_expanding(&s, in);   
            // else
            //     exp_else_sp(&s, in);
        }
        if (in[s.g_i] == '$' && !in[s.g_i + 1])
            dollar_only_case(&s, in);
        else if (in[s.g_i] == '$')
            dollar_expanding(&s,in);
        else if (in[s.g_i] == '\"')
            dq_expanding(&s, in);
        else if (in[s.g_i] == '\'')
            sq_expanding(&s, in);
        else
            exp_else(&s, in);
    }
    return (s.out);
}

int check_unrequired_by_subject(char *in)
{
    //error code -1: unclosed quote
    if (unclosed_quote(in) == 1)
        return(-1);
    return (0);
}

int main(int ac, char *av[], char *env[])
{
    int i;
    char *str;
    
    while(1)
    {
        str = readline("Minisell $> ");
        char *ptr = expand_var_in_str(str);
        printf("->%s\n", ptr);
        free(ptr);
        free(str);
    }
}