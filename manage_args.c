/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/13 15:49:52 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"
#include <unistd.h>
#include "details.c"

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
	while (*arg)
	{
		if (lstat(*arg, &buf) == -1)
		{
			ft_printf("ls: %s: ", *arg);
			perror("");
		}
		else
		{
			if (ft_strchr(env->flag, 'l'))
				details(*arg, buf);
			//fprintf (stdout, "Protection : %o\n", buf.st_mode);
		}
		arg += 1;
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
	if (arc > begin)
	{
		sort_alpha(&arg[begin]);
		sort_type(&arg[begin], env);
	}
	/*else
	 * mettre '.' dans liste dossier*/
}
