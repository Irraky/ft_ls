/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/05 18:14:09 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		clean(t_content		*content)
{
	free(content->name);
	free(content);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start)
{
	t_content		*tmp;
	const char		*dnam = dir->name;

	if (start != 1)
		dir = clean_it(dir);
	while (content != NULL && content->name != NULL)
	{
		if (content->buff && (!((S_ISDIR(content->buff->st_mode))) /*|| (env->flag[1]  && start != 1 && ft_strchr(&content->name[1], '.')) || (ft_strchr(&content->name[1], '.') && env->flag[2])*/))
			details(content->name, env);
		else if (!ft_strchr(&content->name[1], '.') && content->buff && (env->flag[1] || start == 1))
			dir = new_node(dir, content->name, (char*)dnam, start);
		tmp = content;
		content = content->next;
		clean(tmp);
	}
	ft_printf("o%so", dir->name);
	free(content);
	return (dir);
}
