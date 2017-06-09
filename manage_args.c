/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/09 17:55:11 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

static void		sort_alpha(char **arg)
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

static void		sort_type(char **arg)
{
	struct stat buf;
	while (*arg)
	{
		if (lstat(*arg++, &buf) == 0)
		{
		}
		//else

	}
}

void			manage_args(char **arg, int arc)
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
		sort_type(&arg[begin]);
	}
	/*else
	 * mettre '.' dans liste dossier*/
}
