/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/09/18 15:37:19 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		double_joinfree(char *path, char *name, t_content *new)
{
	new->path = ft_joinfree(path, "/", 0);
	new->path = ft_joinfree(new->path, name, 0);
}

t_content		*new_elem(t_content *content, char *name, char *path)
{
	struct stat		buf;
	t_content		*new;

	if (!(new = ft_memalloc(sizeof(t_content))))
		exit(-1);
	if (ft_strcmp(name, "/") == 0 || path == NULL || !ft_strcmp(name, "."))
		new->path = ft_strdup(name);
	else if (ft_strcmp(path, "/") == 0 && !(ft_strcmp(name, "/") == 0))
		new->path = ft_joinfree("/", name, 0);
	else
		double_joinfree(path, name, new);
	new->buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	if (lstat(new->path, &buf) == -1)
	{
		write(2, "ls: ", 4);
		perror(new->path);
	}
	*new->buff = buf;
	new->next = content;
	if (content)
		content->prev = new;
	new->prev = NULL;
	return (new);
}
