/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:39:06 by drecours          #+#    #+#             */
/*   Updated: 2017/07/05 18:15:39 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			compare_flags(char *str, t_env *env)
{
	const char	*flags = "lRart";
	const char* test;

	while (*str++)
		if (!(test = ft_strchr(flags, *str)))
		{
			write(2, "ft_ls : illegal option -- ", 26);
			write(2, &*str, 1);
			write(2, "\nusage: ft_ls [Ralrt] [file...]\n", 32);
			return (WRONG_FLAG);
		}
		else
			env->flag[test - flags] = *str;
	return (0);
}

int			get_data(char **argv, t_env *env)
{
	int		i;

	i = 0;
	if (argv[1])
	{
		while (argv[++i] && argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				break;
			if (compare_flags(argv[i], env) == WRONG_FLAG)
				return (WRONG_FLAG);
		}
	}
	return (1);
}
	env->flag = (t_flag){0, 0, 0, 0, 0};
