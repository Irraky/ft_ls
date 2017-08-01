/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/26 14:10:25 by drecours         ###   ########.fr       */
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
//	t_dir	*tmp;
	t_content	*tp;

	if (start != 1)
		dir = clean_it(dir);
	tp = content;
	ft_printf("\n\nCONTENT :\n");
	while(tp)
	{
		ft_printf("\n-%s", tp->path);
		tp = tp->next;
	}
	ft_printf("\n\n");
	while (content != NULL && content->path != NULL && content->buff)
	{
		if ((ft_strrchr(content->path, '/')) == NULL)
			name = content->path;
		else
			name = (ft_strrchr(content->path, '/') + 1);
		if (content->buff && !(name[0] == '.' && !env->flag[2] && start != 1))
			details(content, env);
		if (content->buff && S_ISDIR(content->buff->st_mode) && (start == 1
					|| (env->flag[1] && name[0] != '.')))
		{
			ft_printf("\n HE HE ICI %s ICI ICI HE \n", content->path);
			dir = new_node(dir, content->path);
		}
		content = content->next;
	}
//	ft_printf("\n\nADD\n");
//	tmp = dir;
//	while (tmp)
//	{
//		ft_printf("->%s\n", tmp->dname);
//		tmp = tmp->next;
//	}
	ft_printf("\n");
	return (dir);
}
