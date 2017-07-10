/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/10 14:56:23 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content		*clean(t_content *content)
{
	t_content		*tmp;

	tmp = content;
	if (content->next)
	content = content->next;
	if (tmp != NULL)
	{
		free(tmp->name);
		free(tmp->path);
		free(tmp->buff);
		free(tmp);
	}
	return (content);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start)
{
	dir = clean_it(dir);
	if (start != 1)
		dir = clean_it(dir);
	while (content != NULL && content->name != NULL)
	{
		if (content->buff && (!((S_ISDIR(content->buff->st_mode)))))
			details(content, env);
		else if (content->buff && (env->flag[1] || start == 1))
			dir = new_node(dir, content->path);
		content = content->next;
	}
	return (dir);
}
