/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:14:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/13 08:34:30 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


void	lstadd_tok(t_toklist **lst, t_toklist *new_token)
{
	t_toklist	*current;

	if (new_token)
	{
		if (*lst)
		{
			current = *lst;
			while (current->next)
				current = current->next;
			current->next = new_token;
		}
		else
			*lst = new_token;
	}
}