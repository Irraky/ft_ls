/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 12:32:37 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent* readdir(DIR* repertoire) ;

void		manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	DIR				*rep;
	struct dirent	*cur_file = NULL;
	struct stat		data;
	int			spaces[5];

	if (lstat(dir->dname, &data) == -1)
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
	}
	else
	{
		if (data.st_mode & S_IRUSR)
		{
			content = NULL;
			if (!(content = ft_memalloc(sizeof(t_content))))
				exit(-1);
			if (data.st_mode & S_IXUSR)
			{
				if (!(rep = opendir(dir->dname)))
					exit(1);
				while ((cur_file = readdir(rep)))
					content = new_elem(content, cur_file->d_name, dir->dname);
				if (closedir(rep) == -1)
					exit(-1);
			}
			content = lst_sort(content, env->flag[4] ? 0 : 1);
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
