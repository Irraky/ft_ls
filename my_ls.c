/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:27:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/24 14:02:32 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			init_env(t_env *env)
{
	env->pflag = 0;
	env->flagname = 0;
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
//		sort_args(content);
		count(content, dir, &env, spaces);
		dir = display_file(content, dir, &env, 1, spaces);
		if (dir && dir->dname)
			manage_dir(dir, &env);
	}
	return (0);
}
