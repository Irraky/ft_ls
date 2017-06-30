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

t_content	*new_elem(t_content *content, char *str, char *str2)
{
	t_content *new = ft_memalloc(sizeof(t_content));

	new->buff = (struct stat*)ft_memalloc(sizeof(struct stat));
	lstat(str, new->buff);
	if (S_ISDIR(new->buff->st_mode) && ft_strchr(str2, '/'))
			new->name = ft_strdup(str2);
	else
			new->name = ft_strdup(str);
	new->next = content;
	return (new);
}
