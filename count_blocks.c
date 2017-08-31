/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:20:05 by drecours          #+#    #+#             */
/*   Updated: 2017/08/31 18:27:41 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				count_blocks(t_content *content, t_dir *dir, t_env *env)
{
	int			total;
	int			dossier;
	t_content	*tmp;

	total = 0;
	dossier = 0;
	tmp = content;
	while (content->path)
	{
		total += content->buff->st_blocks;
		if (S_ISDIR(content->buff->st_mode))
		   dossier = 1;
		content = content->next;
	}
	if (env->flagname == 0)
		ft_printf("%s:\n", dir->dname);
	if (tmp->path != NULL)
		ft_printf("total %d", total);
	env->flagname = 0;
}
