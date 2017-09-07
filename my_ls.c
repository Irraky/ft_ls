/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:43:53 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 17:41:49 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
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
		if ((content = parsing_args(argv, argc, &env)) == NULL)
			exit(-1);
		if ((content = lst_sort(content, env.flag[4] ? 0 : 1)) == NULL)
			exit(-1);
		count(content, dir, &env, spaces);
		dir = display_file(content, dir, &env, 1, spaces);
		if (dir && dir->dname)
			manage_dir(dir, &env);
	}
	return (0);
}
