/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:58:06 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:05:56 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_flags(t_e *env)
{
	if (env->conv.nb[0] == '-')
		ft_putinit(env, "-", 1);
	else if (env->conv.space == 1 || env->conv.plus == 1)
		ft_putinit(env, (env->conv.plus == 1) ? "+" : " ", 1);
}

static int		first_flags_d(t_e *env, int max, int lg)
{
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	if ((env->conv.nb[0] == '0' && env->conv.plus == 1 && env->conv.champ == 0)
			|| (env->conv.space == 1 && env->conv.precision > 0) ||
				(env->conv.nb[0] == '-' && lg <= env->conv.precision))
		flag = 1;
	if (env->conv.zero == 1)
		ft_flags(env);
	if (env->conv.plus == 1 && env->conv.precision > 0)
		flag = 1;
	while (env->conv.neg == 0 && env->conv.champ-- > max + flag)
		ft_putinit(env, (env->conv.zero == 1) ? "0" : "  ", 1);
	if (env->conv.zero == 0)
		ft_flags(env);
	if (env->conv.plus == 1 || env->conv.space == 1)
		flag = 1;
	while (env->conv.precision - i++ > lg - flag)
		ft_putinit(env, "0", 1);
	if (env->conv.precision < lg)
		flag = 0;
	return (flag);
}

void			convd(va_list args, t_e *env)
{
	int		flag;
	int		max;
	int		lg;

	convitoa(args, env);
	lg = (int)ft_strlen(env->conv.nb);
	if (env->conv.nb[0] != '-' && (env->conv.plus == 1 || env->conv.space == 1))
		lg++;
	if (env->conv.precision > -1)
		env->conv.zero = 0;
	if (env->conv.nb[0] == '0' && env->conv.precision == 0 &&
			env->conv.champ > 0)
		env->conv.champ++;
	max = (env->conv.precision > lg) ? env->conv.precision : lg;
	flag = first_flags_d(env, max, lg);
	lg = (int)ft_strlen(env->conv.nb);
	if (env->conv.nb[0] == '-')
		ft_putinit(env, &env->conv.nb[1], lg - 1);
	else if (!(env->conv.nb[0] == '0' && env->conv.precision == 0))
		ft_putinit(env, env->conv.nb, lg);
	while (env->conv.neg == 1 && env->conv.champ-- > max + flag)
		ft_putinit(env, " ", 1);
}

void			convgd(va_list args, t_e *env)
{
	env->l = 1;
	convd(args, env);
}

void			convi(va_list args, t_e *env)
{
	convd(args, env);
}
