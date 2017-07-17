/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/07/17 16:57:52 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *name, char *path)
{
	struct stat		buf;
	t_content		*new;

	new = ft_memalloc(sizeof(t_content));
	if ((ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
			|| ft_strcmp(path, ".") == 0)
		new->path = ft_strdup(name);
	else
	{
		new->path = ft_joinfree(path, "/", 0);
		new->path = ft_joinfree(new->path, name, 0);
	}
	new->buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	lstat(new->path, &buf);
	*new->buff = buf;
	new->next = content;
	return (new);
}
