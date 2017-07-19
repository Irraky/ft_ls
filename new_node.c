/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:03:15 by drecours          #+#    #+#             */
/*   Updated: 2017/07/19 15:43:45 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*new_node(t_dir *dir, char *str)
{
	t_dir	*new;

	new = ft_memalloc(sizeof(t_content));
	new->dname = ft_strdup(str);
	new->next = dir;
	return (new);
}
