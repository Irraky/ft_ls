/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 18:17:12 by drecours         ###   ########.fr       */
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
	t_dir		*nw;
	t_content	*tmp;
	
	nw = ft_memalloc(sizeof(t_dir));
	nw->next = dir;
	while (content->name != NULL)
	{
		if (content->buff && !(S_ISDIR(content->buff->st_mode)))
			details(content);
		else
			nw = new_node(nw, content->name);
		tmp = content;
		clean(tmp);
		content = content->next;
	}
	while (nw != NULL && nw->name != NULL)
	{
		printf("%s\n", nw->name);
		nw = nw->next;
	}
	return (nw);
}
