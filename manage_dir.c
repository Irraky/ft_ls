/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/07/24 19:10:44 by drecours         ###   ########.fr       */
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
	t_dir *tmp;

	/*if (*/lstat(dir->dname, &data);/* == -1)*/
//	{
//		write(2, "ls: ", 4);
//		perror(dir->dname);
//	}
	if (data.st_mode & S_IRUSR)
	{
		if (env->flagname == 1)
			env->flagname = 0;
		else
			ft_printf("%s:\n", dir->dname);
		content = NULL;
		if (!(content = ft_memalloc(sizeof(t_content))))
			exit(-1);
		ft_printf("PLOP");
		if (data.st_mode & S_IXUSR)
		{
			ft_printf("%o", S_IXUSR);
			if (!(rep = opendir(dir->dname)))
				exit(1);
			ft_printf("paf");
			while ((cur_file = readdir(rep)))
				content = new_elem(content, cur_file->d_name, dir->dname);
			ft_printf("COIN");
			if (closedir(rep) == -1)
				exit(-1);
			ft_printf("PLOUF");
		}
		ft_printf("PLOP");
		dir = display_file(content, dir, env, 0);
	}
	else
	{
		write(2, "ls: ", 4);
		write(2, dir->dname, ft_strlen(dir->dname));
		write(2, " Permission denied\n", 19);
		dir = clean_it(dir);
	}
	tmp = dir;
	while (tmp->dname)
	{
		ft_printf("-> %s\n", tmp->dname);
		tmp = tmp->next;
	}
	if (dir->dname != NULL)
		manage_dir(dir, env);
}
