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

t_dir		*manage_dir(t_dir *dir, t_env *env)
{
	t_content		*content;
	DIR				*rep = NULL;
	struct dirent	*fichierLu = NULL;
	char			*extend_name;

	ft_printf("\n%s:\n", dir->name);
	rep = opendir(dir->name);
	content = ft_memalloc(sizeof(t_content));
	if (rep == NULL)
		exit(1);
	fichierLu = readdir(rep);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		extend_name = ft_joinfree(dir->name, "/", 0);
		extend_name = ft_joinfree(extend_name, fichierLu->d_name, 1);
		content = new_elem(content, fichierLu->d_name, extend_name);
		free(extend_name);
	}
	dir = clean_it(dir);
	dir = display_file(content, dir, env);
	if (closedir(rep) == -1)
		exit(-1);
	return (dir);
}
