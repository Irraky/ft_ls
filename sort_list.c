/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:53:04 by drecours          #+#    #+#             */
/*   Updated: 2017/09/25 11:29:50 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*static t_content	*swap_next(t_content *last, t_content *content, t_env *env)
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
}*/

static void			swap_nodes(t_content *last, t_content *content, t_env *env)
{

	(void)env;
	struct stat	*tmp1;
	char		*tmp2;

	tmp1 = last->buff;
	tmp2 = last->path;

	last->buff = content->buff;
	last->path = content->path;
	content->buff = tmp1;
	content->path = tmp2;
//	t_content	*tmp;

//	content = swap_next(last, content, env);
//	if (content->next)
//	{
//		tmp = content;
//		content = content->next;
//		content->prev = tmp;
//	}
//	else
//		env->end = content;
}

t_content			*lst_sort(t_content *content, short fg, t_env *env)
{
	t_content	*start;
	t_content	*end;
	t_content	*bigger;

	start = content;
	end = NULL;
	bigger = content;
	while (start != end && start->next)
	{
		while (content && !(content->prev && content->prev == end))
		{
			if ((fg == 0 && (content->buff->st_mtime < bigger->buff->st_mtime
					|| (content->buff->st_mtime == bigger->buff->st_mtime &&
					ft_strcmp(content->path, bigger->path) > 0))) ||
					(ft_strcmp(content->path, bigger->path) > 0 && fg == 1))
				bigger = content;
			if (content->next == end)
				end = content;
			content = content->next;
		}
		if (end && end != bigger)
			swap_nodes(end, bigger, env);
		bigger = start;
		content = start;
	}
	return (start);
}
