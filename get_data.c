/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:39:06 by drecours          #+#    #+#             */
/*   Updated: 2017/05/19 18:03:14 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			compare_flags(char *str, t_env *env)
{
	const char	*flags = "lRart";
	int			i;

	i = -1;
	while(++*str)
		if (!ft_strchr(flags, *str))
			return (WRONG_FLAG);
		else
			env->*str = 1;
	return (1);
}

int			get_data(char	**argv, t_env *env)
{
	int		i;

	i = 0;
	while(argv[i])
	{
		if (argv[i][0] == '-')
			if(!compare_flags(argv[i], env))
				return (WRONG_FLAG);
		i++;
	}
	return (1);
}
