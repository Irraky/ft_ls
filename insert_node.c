/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:29:55 by drecours          #+#    #+#             */
/*   Updated: 2017/09/13 11:42:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*insert_node(t_dir *dir, t_dir *first, char *name)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = dir;
	new = new_node(first, name);
	if (first == dir)
		new->next = NULL;
	while (tmp && tmp != first && tmp->next && tmp->next != first)
		tmp = tmp->next;
	if (tmp && tmp != first)
		tmp->next = new;
	if (dir && dir->dname && dir != first)
		return (dir);
	return (new);
}
