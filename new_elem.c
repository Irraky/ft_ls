/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/06/30 16:03:30 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *str, char *path)
{
	char	*tmp;
	t_content *new = ft_memalloc(sizeof(t_content));

	tmp = ft_joinfree(path, "/", 0);
	tmp = ft_joinfree(tmp, str, 1);
	new->buff = (struct stat*)ft_memalloc(sizeof(struct stat));
	lstat(tmp, new->buff);
	new->name = ft_strdup(str);
	new->next = content;
	free(tmp);
	return (new);
}
