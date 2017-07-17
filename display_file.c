/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/17 17:20:42 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content		*clean(t_content *content)
{
	t_content		*tmp;

	tmp = content;
	content = content->next;
	if (tmp != NULL)
	{
		free(tmp->path);
		free(tmp->buff);
		free(tmp);
	}
	return (content);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start)
{
	char	*name;

	if (start != 1)
		dir = clean_it(dir);
	while (content != NULL && content->path != NULL)
	{
		if ((name = ft_strrchr(content->path, '/')) == NULL)
			name = content->path;
		if (content->buff && !(name[0] == '.' && env->flag[2] && start != 1))
			details(content, env);
		if (content->buff && S_ISDIR(content->buff->st_mode) &&(start == 1 || (env->flag[1] && name[0] != '.')))
			dir = new_node(dir, content->path);
		content = content->next;
	}
	return (dir);
}
