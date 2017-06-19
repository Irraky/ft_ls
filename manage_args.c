/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/19 17:36:46 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_alpha(char **arg)
{
	int		ite;
	char	*tmp;

	ite = 0;
	while (arg[ite + 1])
	{
		if (ft_strcmp(arg[ite], arg[ite + 1]) > 0)
		{
			tmp = arg[ite];
			arg[ite] = arg[ite + 1];
			arg[ite + 1] = tmp;
			ite = 0;
		}
		ite++;
	}
}

static void		sort_type(char **arg, t_env *env)
{
	struct stat buf;
	char	**tmp;

	tmp = arg;
	while (*arg)
	{
		if (lstat(*arg, &buf) == -1)
		{
			ft_printf("ls: %s: ", *arg);
			perror("");
		}
		arg += 1;
	}
	while (*tmp)
	{
		printf("%s", *tmp);
		if (!(lstat(*arg, &buf) == 0))
		{
			if (ft_strchr(env->flag, 'l'))
				details(*arg, buf);
		}
		tmp += 1;
	}
}

void			manage_args(char **arg, int arc, t_env *env)
{
	int		i;
	int		begin;

	i = 0;
	begin = 1;
	if (arc > 1)
		while (arg[begin] && arg[begin][0] == '-')
			begin++;
	if (arc - begin == 1 || 0)
		env->flagname = 1;
	if (arc > begin)
	{
		sort_alpha(&arg[begin]);
		sort_type(&arg[begin], env);
	}
	else
	{
		/*mettre '.' dans liste chainee*/
		printf("principal directory");
	}
}
