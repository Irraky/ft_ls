/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/08/01 17:54:25 by drecours         ###   ########.fr       */
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

	if (lstat(dir->dname, &data) == -1)
	{
		write(2, "ls: ", 4);
		perror(dir->dname);
	}
	if (data.st_mode & S_IROTH)
	{
		if (env->flagname == 1)
			env->flagname = 0;
		else
			ft_printf("%s:\n", dir->dname);
		content = NULL;
		if (!(content = ft_memalloc(sizeof(t_content))))
			exit(-1);
		ft_printf("C EST LE SON DE LA POLICE \n");
		if (data.st_mode & S_IXOTH)
		{
			ft_printf("AHTATATTATATTATATATATAT");
			if (!(rep = opendir(dir->dname)))
				exit(1);
			while ((cur_file = readdir(rep)))
				content = new_elem(content, cur_file->d_name, dir->dname);
			if (closedir(rep) == -1)
				exit(-1);
		}
		dir = display_file(content, dir, env, 0);
	}
	else
	{
		write(2, "ls: ", 4);
		write(2, dir->dname, ft_strlen(dir->dname));
		write(2, " Permission denied\n", 19);
		dir = dir->next;
	}
	if (dir->dname != NULL)
		manage_dir(dir, env);
}
