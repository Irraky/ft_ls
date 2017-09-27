/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:53:04 by drecours          #+#    #+#             */
/*   Updated: 2017/09/27 13:11:01 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			swap_nodes(t_content *last, t_content *content)
{
	struct stat	tmp1;
	char		*tmp2;

	tmp1 = *last->buff;
	tmp2 = last->path;
	*last->buff = *content->buff;
	last->path = content->path;
	*content->buff = tmp1;
	content->path = tmp2;
}

static t_content	*test_swap(t_content *content, t_content *bigger,
		t_env *env, short fg)
{
	if (content->next == NULL)
		env->end = content;
	if ((fg == 0 && (content->buff->st_mtime < bigger->buff->st_mtime
			|| (content->buff->st_mtime == bigger->buff->st_mtime &&
			ft_strcmp(content->path, bigger->path) > 0))) ||
			(ft_strcmp(content->path, bigger->path) > 0 && fg == 1))
		return (content);
	return (bigger);
}

t_content			*lst_sort(t_content *content, short fg, t_env *env)
{
	t_content	*start;
	t_content	*end;
	t_content	*bigger;

	start = content;
	end = NULL;
	bigger = content;
	if (!start->next)
		env->end = start;
	while (start != end && start->next)
	{
		while (content && !(content->prev && content->prev == end))
		{
			bigger = test_swap(content, bigger, env, fg);
			if (content->next == end)
				end = content;
			content = content->next;
		}
		if (end && end != bigger)
			swap_nodes(end, bigger);
		bigger = start;
		content = start;
	}
	return (start);
}
