/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/07/19 16:11:48 by drecours         ###   ########.fr       */
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

	if (env->flagname == 1)
		env->flagname = 0;
	else
		ft_printf("%s:\n", dir->dname);
	lstat(dir->dname, &data);
	if (S_IRUSR & data.st_mode)
	{
		if (!(rep = opendir(dir->dname)))
			exit(1);
		content = NULL;
		content = ft_memalloc(sizeof(t_content));
		while ((cur_file = readdir(rep)) != NULL)
			content = new_elem(content, cur_file->d_name, dir->dname);
		if (closedir(rep) == -1)
			exit(-1);
		dir = display_file(content, dir, env, 0);
	}
	else
	{
		write(2, "ls: ", 4);
		write(2, dir->dname, ft_strlen(dir->dname));
		write(2, " Permission denied\n", 19);
		dir = clean_it(dir);
	}
	if (dir->dname != NULL)
		manage_dir(dir, env);
}
