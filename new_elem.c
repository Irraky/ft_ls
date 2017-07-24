/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/07/24 12:58:29 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *name, char *path)
{
	struct stat		buf;
	t_content		*new;

	if (!(new = ft_memalloc(sizeof(t_content))))
		exit(-1);
	if (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0
			|| ft_strcmp(name, "/") == 0 || path == NULL)
		new->path = ft_strdup(name);
	else if (ft_strcmp(path, "/") == 0 && !(ft_strcmp(name, "/") == 0))
		new->path = ft_joinfree("/", name, 0);
	else
	{
		new->path = ft_joinfree(path, "/", 0);
		new->path = ft_joinfree(new->path, name, 0);
	}
	new->buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	if (lstat(new->path, &buf) == -1)
	{
		write(2, "ls: ", 4);
		perror(new->path);
	}
	*new->buff = buf;
	new->next = content;
	return (new);
}
