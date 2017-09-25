/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:43:53 by drecours          #+#    #+#             */
/*   Updated: 2017/09/25 18:05:23 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_space(t_content *content, int space)
{
	int		dir;
	int		file;

	dir = 0;
	file = 0;
	while (content && content->path)
	{
		if (S_ISDIR(content->buff->st_mode) ||
				(S_ISLNK(content->buff->st_mode) && verify_link(content) == 1))
			dir = 1;
		else
			file = 1;
		if (dir == 1 && file == 1)
			return (1);
		content = content->next;
	}
	if (dir == 1 && space == 1)
		return (space);
	return (0);
}

static t_dir	*init_env(t_env *env, int *space)
{
	t_dir	*dir;

	ft_bzero(env, sizeof(t_env));
	*space = 0;
	dir = NULL;
	if (!(dir = ft_memalloc(sizeof(t_dir))))
		exit(-1);
	env->first_elem = dir;
	env->start = 1;
	return (dir);
}

static void		clean_first(t_env *env)
{
	if (env->first_elem && env->first_elem->dname)
	{
		free(env->first_elem->dname);
		env->first_elem->dname = NULL;
	}
	free(env->first_elem);
	env->first_elem = NULL;
}

int				main(int argc, char **argv)
{
	t_env		env;
	t_content	*content;
	t_dir		*dir;
	int			space;
	int			spaces[5];

	dir = init_env(&env, &space);
	if (get_data(argv, &env) == 1)
	{
		if ((content = parsing_args(argv, argc, &env, &space)) == NULL)
			exit(-1);
		env.bgn = content;
		content = lst_sort(content, env.flag[4] ? 0 : 1, &env);
		count(content, dir, &env, spaces);
		space = ft_space(content, space);
		dir = display_file(content, dir, &env, spaces);
		if (space == 1)
			write(1, "\n", 1);
		env.start = 0;
		while (dir && dir->dname)
			dir = manage_dir(dir, &env);
		clean_first(&env);
	}
	return (0);
}
