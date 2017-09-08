/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/09/08 12:23:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content		*clean(t_content *content)
{
	t_content		*tmp;

	tmp = content;
	content = content->next;
	ft_strdel(&tmp->path);
	ft_memdel((void**)&tmp->buff);
	ft_memdel((void**)&tmp);
	return (content);
}

static	int			verify_link(t_content *content)
{
	struct stat			data;

	stat(content->path, &data);
	if (S_ISDIR(data.st_mode))
		return (1);
	return (0);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start, int spaces[5])
{
	char	*name;

	if (start != 1)
		dir = clean_it(dir);
	while (content && content->path  && content->buff)
	{
		name = (ft_strrchr(content->path, '/') == NULL) ? content->path 
			: (ft_strrchr(content->path, '/') + 1);
		if (content->buff && !(name[0] == '.' && !env->flag[2] && start != 1) && !(start == 1 && S_ISDIR(content->buff->st_mode)))
			details(content, env, spaces);
		if (content->buff && S_ISDIR(content->buff->st_mode) && (start == 1
					|| (env->flag[1] && name[0] != '.')))
			dir = new_node(dir, content->path);
		if (S_ISLNK(content->buff->st_mode) && verify_link(content) && env->flag[0] && env->flag[1])
			if (readlink(content->path, name, 1024) != -1)
				dir = new_node(dir, name);
		content = content->next;
	//	clean(content);
	}
	if (dir->next && start == 0)
		ft_printf("\n");
	return (dir);
}
