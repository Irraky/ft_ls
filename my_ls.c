/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:43:53 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 12:32:43 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			init_env(t_env *env)
{
	env->pflag = 0;
	env->flagname = 0;
	env->flag[0] = '\0';
	env->flag[1] = '\0';
	env->flag[2] = '\0';
	env->flag[3] = '\0';
	env->flag[4] = '\0';
}

int		main(int argc, char **argv)
{
	t_env		env;
	t_content	*content;
	t_dir		*dir;
	int		spaces[5];

	dir = NULL;
	if (!(dir = ft_memalloc(sizeof(t_dir))))
		exit(-1);
	init_env(&env);
	if (get_data(argv, &env) == 1)
	{
		content = parsing_args(argv, argc, &env);
		content = lst_sort(content, env.flag[4] ? 0 : 1);
		count(content, dir, &env, spaces);
		dir = display_file(content, dir, &env, 1, spaces);
		if (dir && dir->dname)
			manage_dir(dir, &env);
	}
	return (0);
}
