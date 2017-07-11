/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/07/11 05:36:22 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent* readdir(DIR* repertoire) ;

void		manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	DIR				*rep = NULL;
	struct dirent	*fichierLu = NULL;
	char			*name;

	ft_printf("\n%s:\n", dir->dname);
	rep = opendir(dir->dname);
	if (rep == NULL)
		exit(1);
	content = NULL;
	content = ft_memalloc(sizeof(t_content));
	fichierLu = readdir(rep);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		if ((name = ft_strrchr(fichierLu->d_name, '/')) + 1)
			name = fichierLu->d_name;
		if (!(name[0] == '.' && !env->flag[2]))
			content = new_elem(content, fichierLu->d_name, "");
	}
	dir = display_file(content, dir, env, 0);
	if (closedir(rep) == -1)
		exit(-1);
	if (dir->next != NULL)
		manage_dir(dir, env);
}
