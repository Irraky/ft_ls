/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/10 13:37:41 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		clean(t_content		*content)
{
	if (content->name)
		free(content->name);
	if (content->path)
		free(content->path);
	if (content->buff)
		free(content->buff);
	if (content)
		free(content);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start)
{
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
