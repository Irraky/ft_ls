/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/07/17 13:21:20 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *name)
{
	struct stat		buf;
	t_content		*new;

	new = ft_memalloc(sizeof(t_content));
	new->path = ft_strdup(name);
	new->buff = (struct stat *)ft_memalloc(sizeof(struct stat));
	lstat(name, &buf);
	*new->buff = buf;
	new->next = content;
	return (new);
}
