/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:06:23 by drecours          #+#    #+#             */
/*   Updated: 2017/06/30 16:19:04 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*clean_it(t_dir *dir)
{
	t_dir		*tmp;

	tmp = dir;
	dir = dir->next;
	free(tmp->name);
	free(tmp);
	return (dir);
}

void		load_balance(t_dir *dir, t_env *env)
{
	int		r;

	r = (ft_strchr(env->flag, 'R') != NULL) ? 1 : 0;
	if (r == 0)
	{
		details(dir->name, env);
		dir = clean_it(dir);
	}
	else
		manage_dir(dir, env);
	if (dir->name != NULL)
		load_balance(dir, env);
}
