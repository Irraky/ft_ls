/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/07/18 15:48:19 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent* readdir(DIR* repertoire) ;

void		manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	DIR				*rep = NULL;
	struct dirent	*cur_file = NULL;

	rep = opendir(dir->dname);
	if (rep == NULL)
		exit(1);
	content = NULL;
	content = ft_memalloc(sizeof(t_content));
	while ((cur_file = readdir(rep)) != NULL)
		content = new_elem(content, cur_file->d_name, dir->dname);
	if (env->flagname == 1)
		env->flagname = 0;
	else
		ft_printf("\n%s:\n", dir->dname);
	dir = display_file(content, dir, env, 0);
	if (closedir(rep) == -1)
		exit(-1);
	if (dir->next != NULL)
		manage_dir(dir, env);
}
