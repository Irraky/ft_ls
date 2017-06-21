/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:02:52 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:03:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convitoabase(va_list args, t_e *env, int base)
{
	int		i;

	i = -1;
	if (env->l == 1 || env->conv.conversion == 3)
		ft_itoa_base(va_arg(args, unsigned long), base, env->conv.nbp);
	else if (env->ll == 1)
		ft_itoa_base(va_arg(args, unsigned long long), base, env->conv.nbp);
	else if (env->hh == 1)
		ft_itoa_base((unsigned char)va_arg(args, int), base, env->conv.nbp);
	else if (env->h == 1)
		ft_itoa_base((unsigned short)va_arg(args, unsigned), base,
				env->conv.nbp);
	else if (env->j == 1)
		ft_itoa_base(va_arg(args, uintmax_t), base, env->conv.nbp);
	else if (env->z == 1)
		ft_itoa_base(va_arg(args, size_t), base, env->conv.nbp);
	else
		ft_itoa_base(va_arg(args, unsigned int), base, env->conv.nbp);
	while (env->conv.nbp[++i])
		if (env->conv.nbp[i] <= 'z' && env->conv.nbp[i] >= 'a' &&
				env->conv.conversion == 10)
			env->conv.nb[i] = env->conv.nbp[i] - 32;
		else
			env->conv.nb[i] = env->conv.nbp[i];
}

void	convitoa(va_list args, t_e *env)
{
	long long d;

	d = va_arg(args, long long);
	if (env->l == 1)
		ft_itoa((long)d, env->conv.nb);
	else if (env->ll == 1)
		ft_itoa((long long)d, env->conv.nb);
	else if (env->hh == 1)
		ft_itoa((char)d, env->conv.nb);
	else if (env->h == 1)
		ft_itoa((short)d, env->conv.nb);
	else if (env->j == 1)
		ft_itoa((long)d, env->conv.nb);
	else if (env->z == 1)
		ft_itoa((long)d, env->conv.nb);
	else
		ft_itoa((int)d, env->conv.nb);
}
