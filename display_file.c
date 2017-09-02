/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/08/04 15:45:43 by drecours         ###   ########.fr       */
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

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start, int spaces[5])
{
	char	*name;

	if (start != 1)
		dir = clean_it(dir);
	ft_printf("\n\n");
	while (content != NULL && content->path != NULL && content->buff)
	{
		if ((ft_strrchr(content->path, '/')) == NULL)
			name = content->path;
		else
			name = (ft_strrchr(content->path, '/') + 1);
		if (content->buff && !(name[0] == '.' && !env->flag[2] && start != 1) && !(start == 1 && S_ISDIR(content->buff->st_mode)))
			details(content, env, spaces);
		if (content->buff && S_ISDIR(content->buff->st_mode) && (start == 1
					|| (env->flag[1] && name[0] != '.')))
		{
			dir = new_node(dir, content->path);
		}
		content = content->next;
		//clean(content);
	}
	ft_printf("\n");
	return (dir);
}
