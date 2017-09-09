/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:00:56 by drecours          #+#    #+#             */
/*   Updated: 2017/09/09 14:28:21 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_content	*swap_next(t_content *last, t_content *content, t_env *env)
{
	t_content	*tmp;

	if (last != content)
	{
		tmp = content->next;
		content->next = tmp->next;
		tmp->next = content;
		last->next = tmp;
		tmp->prev = content->prev;
		content->prev = tmp;
	}
	else
	{
		tmp = content->next;
		content->next = content->next->next;
		tmp->next = content;
		content->prev = tmp;
		tmp->prev = NULL;
		env->bgn = tmp;
	}
	return (content);
}

static void			swap_nodes(t_content *last, t_content *content, t_env *env)
{
	t_content	*tmp;

	content = swap_next(last, content, env);
	if (content->next)
	{
		tmp = content;
		content = content->next;
		content->prev = tmp;
	}
	else
		env->end = content;
}

t_content			*lst_sort(t_content *content, short fg, t_env *env)
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
			swap_nodes(tmp, content, env);
			content = start;
			tmp = start;
		}
		else
		{
			tmp = (tmp != content) ? tmp->next : tmp;
			content = content->next;
		}
	}
	env->end = content;
	return (start);
}

