/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/06/30 16:24:16 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct dirent* readdir(DIR* repertoire) ;

void		manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	DIR				*rep = NULL;
	struct dirent	*fichierLu = NULL;
	int				a;

	ft_printf("\n%s:\n", dir->name);
	rep = opendir(dir->name);
	if (rep == NULL)
		exit(1);
	a = (!(ft_strchr(env->flag, 'a'))) ? 0 : 1;
	content = ft_memalloc(sizeof(t_content));
	fichierLu = readdir(rep);
	while ((fichierLu = readdir(rep)) != NULL)
		if (!(fichierLu->d_name[0] == '.' && a == 0))
			content = new_elem(content, fichierLu->d_name, dir->name);
	dir = display_file(content, dir, env, 0);
	if (closedir(rep) == -1)
		exit(-1);
	if (dir->next != NULL)
		manage_dir(dir, env);
}
