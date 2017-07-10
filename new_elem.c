/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/07/10 13:37:35 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *str, char *path)
{
	char			*tmp;
	struct stat		buf;
	t_content		*new = ft_memalloc(sizeof(t_content));


	if (path && path[0])
	{
		if (path[0] != '/' && path[1] == '/' && path[2] == '\0')
			tmp = ft_strdup("./");
		else
			tmp = ft_joinfree(path, "/", 0);
		tmp = ft_joinfree(tmp, str, 1);
	}
	else
		tmp = ft_strdup(str);
	new->buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	lstat(tmp, &buf);
	*new->buff = buf;
	new->path = ft_strdup(tmp);
	new->name = ft_strdup(str);
	new->next = content;
	free(tmp);
	return (new);
}
