/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/09/27 13:20:28 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		double_joinfree(char *path, char *name, t_content *new)
{
	new->path = ft_joinfree(path, "/", 0);
	new->path = ft_joinfree(new->path, name, 1);
}

t_content		*new_elem(t_content *content, char *name, char *path)
{
	t_content		*new;

	if (!(new = ft_memalloc(sizeof(t_content))))
		exit(-1);
	if (ft_strcmp(name, "/") == 0 || path == NULL)
		new->path = ft_strdup(name);
	else if (ft_strcmp(path, "/") == 0 && !(ft_strcmp(name, "/") == 0))
		new->path = ft_joinfree("/", name, 0);
	else
		double_joinfree(path, name, new);
	if (!(new->buff = (struct stat*)ft_memalloc(sizeof(struct stat))))
		exit(-1);
	if (lstat(new->path, new->buff) == -1)
	{
		write(2, "ls: ", 4);
		perror(new->path);
	}
	new->next = content;
	if (content)
		content->prev = new;
	new->prev = NULL;
	return (new);
}
