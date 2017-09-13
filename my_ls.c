/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:43:53 by drecours          #+#    #+#             */
/*   Updated: 2017/09/13 15:56:43 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_env		env;
	t_content	*content;
	t_dir		*dir;
	int			spaces[5];

	dir = NULL;
	if (!(dir = ft_memalloc(sizeof(t_dir))))
		exit(-1);
	ft_bzero(&env, sizeof(t_env));
	env.start = 1;
	if (get_data(argv, &env) == 1)
	{
		if ((content = parsing_args(argv, argc, &env)) == NULL)
			exit(-1);
		env.bgn = content;
		if ((content = lst_sort(content, env.flag[4] ? 0 : 1, &env)) == NULL)
			exit(-1);
		count(content, dir, &env, spaces);
		dir = display_file(content, dir, &env, spaces);
		env.start = 0;
		if (dir && dir->dname)
			manage_dir(dir, &env);
	}
	return (0);
}
