/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:03:15 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 17:23:01 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*new_node(t_dir *dir, char *str, char *str2, int start)
{
	t_dir	*new;

	new = ft_memalloc(sizeof(t_content));
	if (str && start == 1)
		new->name = ft_strdup(str);
	else
	{
		new->name = ft_joinfree(str2, "/", 0);
		new->name = ft_joinfree(new->name, str, 1);
		new->next = dir;
	}
	return (new);
}
