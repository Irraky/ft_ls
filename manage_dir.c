/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/09/09 14:10:22 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent* readdir(DIR* repertoire) ;

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

	cur_file = NULL;
	if (!(content = ft_memalloc(sizeof(t_content))))
		exit(-1);
	if (data.st_mode & S_IXUSR)
	{
		if (!(rep = opendir(dir->dname)))
			exit(1);
		while ((cur_file = readdir(rep)))
		{
			content = new_elem(content, cur_file->d_name, dir->dname);
			if (S_ISLNK(content->buff->st_mode))
				env->device = 1;
		}
		if (closedir(rep) == -1)
			exit(-1);
	}
	content = lst_sort(content, env->flag[4] ? 0 : 1, env);
	return (content);
}

void				manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	struct stat		data;
	int			spaces[5];

	if (lstat(dir->dname, &data) == -1)
		dir = stat_error(env, dir);
	else
	{
		if (data.st_mode & S_IRUSR)
		{
			content = readit(NULL, dir, data, env);
			count(content, dir, env, spaces);
			dir = display_file(content, dir, env, 0, spaces);
		}
		else
		{
			write(2, "ls: ", 4);
			write(2, dir->dname, ft_strlen(dir->dname));
			write(2, " Permission denied\n", 19);
			dir = clean_it(dir);
		}
	}
	if (dir->dname != NULL)
		manage_dir(dir, env);
}
