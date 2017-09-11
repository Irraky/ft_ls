/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:44 by drecours          #+#    #+#             */
/*   Updated: 2017/09/11 14:52:13 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content		*clean(t_content *content, t_env *env)
{
	t_content		*tmp;

	tmp = content;
	content = env->flag[3] ? content->prev : content->next;
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

static t_dir		*insert_node(t_dir *dir, t_dir *first, char *name)
{
	t_dir	*new;
	t_dir	*tmp;

	tmp = dir;
	new = new_node(first, name);
	if (first == dir)
		new->next = NULL;
	while (tmp && tmp != first && tmp->next && tmp->next != first)
		tmp = tmp->next;
	if (tmp && tmp != first)
		tmp->next = new;
	if (dir && dir->dname && dir != first)
		return (dir);
	return (new);
}

static t_dir		*new_dir(t_content *content, t_env *env, t_dir *dir, t_dir *first)
{
	char	*name;

	name = (ft_strrchr(content->path, '/') == NULL) ? content->path 
		: (ft_strrchr(content->path, '/') + 1);
	if (content->buff && S_ISDIR(content->buff->st_mode) && (env->start == 1
				|| (env->flag[1] && name[0] != '.')))
		dir = insert_node(dir, first, content->path);
	if (S_ISLNK(content->buff->st_mode) && verify_link(content) && env->flag[0] && env->flag[1])
		if (readlink(content->path, name, 1024) != -1)
			dir = insert_node(dir, first, name);
	return (dir);
}

t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int spaces[5])
{
	char	*name;
	t_dir	*tmp;


	tmp = NULL;
	if (env->start != 1)
		dir = clean_it(dir);
	content = env->flag[3] ? env->end : env->bgn;
	while (content && content->path && content->buff)
	{
		name = (ft_strrchr(content->path, '/') == NULL) ? content->path 
			: (ft_strrchr(content->path, '/') + 1);
		if (content->buff && !(name[0] == '.' && !env->flag[2] && env->start != 1) 
				&& !(env->start == 1 && S_ISDIR(content->buff->st_mode)))
			details(content, env, spaces);
		tmp = new_dir(content, env, tmp, dir);
		content = clean(content, env);
	}
	env->device = 0;
	if (tmp && tmp->dname)
		dir = tmp;
	if (dir && dir->dname && env->start == 0)
		ft_printf("\n");
	return (dir);
	}
