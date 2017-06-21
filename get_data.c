/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:39:06 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 18:45:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

static int			compare_flags(char *str, t_env *env)
{
	const char	*flags = "lRart";
	int			i;

	i = -1;
	while (*str++)
		if (!ft_strchr(flags, *str))
		{
			printf("ft_ls : illegal option -- %s", "usage: ft_ls [Ralrt] [file...]");
			return (WRONG_FLAG);
		}
		else if (!ft_strchr(env->flag, *str))
			env->flag[env->pflag++] = *str;
	return (1);
}

int			get_data(char **argv, t_env *env)
{
	int		i;

	i = 0;
	if (argv[1])
	{
		while (argv[++i])
		{
			write(1, "test\n", 5);
			if (compare_flags(argv[i], env) == WRONG_FLAG)
				return (WRONG_FLAG);
		}
	}
	return (1);
}
