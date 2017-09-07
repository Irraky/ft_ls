/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:00:56 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 17:10:12 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_content	*swap_nodes(t_content *last, t_content *content)
{
	t_content	*tmp;

	if (last != content)
	{
		tmp = content->next;
		content->next = content->next->next;
		tmp->next = content;
		last->next = tmp;
	}
	else
	{
		tmp = content->next;
		content->next = content->next->next;
		tmp->next = content;	
	}
	return (tmp);
}

t_content			*lst_sort(t_content *content, short fg)
{
	t_content	*tmp;
	t_content	*start;

	start = content;
	tmp = content;
	while (content && content->next && content->next->next)
	{
		if ((ft_strcmp(content->path, content->next->path) > 0 && fg == 1) || 
				(fg == 0 && (content->buff->st_mtime < content->next->buff->st_mtime ||
							(content->buff->st_mtime == content->next->buff->st_mtime &&
							ft_strcmp(content->path, content->next->path) > 0))))
		{
			start = (tmp == content) ? content->next : start;
			content = swap_nodes(tmp, content);
			content = start;
			tmp = start;
		}
		else
		{
			tmp = (tmp != content) ? tmp->next : tmp;
			content = content->next;
		}
	}
	return (start);
}

