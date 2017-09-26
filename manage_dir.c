/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:55:32 by drecours          #+#    #+#             */
/*   Updated: 2017/09/26 19:26:50 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_dir		*stat_error(t_env *env, t_dir *dir)
{
	write(2, "ls: ", 4);
	if (env->flag[1])
	{
		write(2, dir->dname, ft_strlen(dir->dname));
		write(2, ": directory causes a cycle\n", 27);
	}
	else
		perror(dir->dname);
	dir = clean_it(dir);
	return (dir);
}

static t_content	*readit(t_content *content, t_dir *dir,
		struct stat data, t_env *env)
{
	DIR				*rep;
	struct dirent	*cur_file;
	int				i;

	cur_file = NULL;
	i = 1;
	if (data.st_mode & S_IXUSR)
	{
		if ((rep = opendir(dir->dname)) != NULL)
		{
			while ((cur_file = readdir(rep)))
			{
				content = new_elem(content, cur_file->d_name, dir->dname);
				if (S_ISLNK(content->buff->st_mode))
					env->device = 1;
				if (i == 1)
				{
					i = 0;
					env->end = content;
				}
			}
			if ((closedir(rep)) == -1)
				exit(-1);
		}
		else
			exit(-1);
	}
	env->bgn = content;
	content = lst_sort(content, env->flag[4] ? 0 : 1, env);
	return (content);
}

void				permission_denied(t_dir *dir)
{
	char			*name;

	name = (ft_strrchr(dir->dname, '/') == NULL) ? dir->dname :
		(ft_strrchr(dir->dname, '/') + 1);
	write(2, "ls: ", 4);
	write(2, name, ft_strlen(name));
	write(2, ": Permission denied\n", 20);
	if (dir && dir->next && dir->next->dname)
		write(1, "\n", 1);
}

t_dir				*allowed_dir(t_dir *dir, t_env *env, struct stat data)
{
	int		spaces[5];
	t_content		*content;

	content = NULL;
	if (data.st_mode & S_IXUSR)
	{
		content = readit(env->bgn, dir, data, env);
		count(content, env, spaces, dir);
		dir = display_file(content, dir, env, spaces);
	}
	else
	{
		if (dir->next && dir->next->dname)
			write(1, "\n", 1);
		dir = clean_it(dir);
	}
	return (dir);
}

t_dir				*manage_dir(t_dir *dir, t_env *env)
{
	struct stat		data;

	env->bgn = NULL;
	env->end = NULL;
	if (lstat(dir->dname, &data) == -1)
		dir = stat_error(env, dir);
	else
	{
		if (env->nbthing == 1 || env->start == -1)
			ft_printf("%s:\n", dir->dname);
		if (data.st_mode & S_IRUSR)
			dir = allowed_dir(dir, env, data);
		else
		{
			permission_denied(dir);
			dir = clean_it(dir);
		}
	}
	env->start = -1;
	return (dir);
}
