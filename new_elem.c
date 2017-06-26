/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:00:32 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 16:56:03 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content	*new_elem(t_content *content, char *str)
{
	t_content *new = ft_memalloc(sizeof(t_content));

	new->buff = (struct stat*)ft_memalloc(sizeof(struct stat));
	new->name = ft_strdup(str);
	lstat(str, new->buff);
	new->next = content;
	return (new);
}
