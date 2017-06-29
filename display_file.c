/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/06/29 14:17:43 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		clean(t_content		*content)
{
	free(content->buff);
	free(content->name);
	free(content);
}

t_dir		*display_file(t_content *content, t_dir *dir)
{
	t_dir		*new;
	t_content	*tmp;
	
	new = ft_memalloc(sizeof(t_dir));
	new->next = dir;
	while (content->name != NULL)
	{
		if (content->buff && !(S_ISDIR(content->buff->st_mode)))
			details(content);
		else
			new = new_node(new, content->name);
		tmp = content;
		content = content->next;
		clean(tmp);
	}
	free(content);
	return (new);
}
