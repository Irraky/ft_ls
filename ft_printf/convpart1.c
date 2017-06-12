/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:36:48 by drecours          #+#    #+#             */
/*   Updated: 2017/06/12 11:15:56 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			convuplus(t_envpf *env)
{
	int		i;

	i = ft_strlen(env->conv.nb);
	while (i < env->conv.precision)
		i++;
	if (env->conv.nb[0] == '0')
		i = 0;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", -1);
		else
			ft_putinit(env, " ", -1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!(env->conv.nb[0] == '0' && env->conv.precision == 0))
		ft_putinit(env, env->conv.nb, -1);
}

void				convu(va_list args, t_envpf *env)
{
	int		i;

	convitoabase(args, env, 10);
	i = ft_strlen(env->conv.nb);
	if (env->conv.neg == 1)
	{
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!(env->conv.nb[0] == '0' && env->conv.precision <= 0
					&& env->conv.champ != 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convuplus(env);
}

static void			convguplus(t_envpf *env)
{
	int		i;

	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	while (i < env->conv.precision)
		i++;
	if (env->conv.nb[0] == '0')
		i = 0;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", 1);
		else
			ft_putinit(env, " ", 1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", 1);
	if (!(env->conv.nb[0] == '0' && env->conv.precision > -1))
		ft_putinit(env, env->conv.nb, -1);
}

void				convgu(va_list args, t_envpf *env)
{
	int		i;

	ft_itoa_base(va_arg(args, unsigned long long), 10, env->conv.nb);
	i = ft_strlen(env->conv.nb);
	if (env->conv.neg == 1)
	{
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!(env->conv.nb[0] == '0' && env->conv.precision <= 0
					&& env->conv.champ != 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convguplus(env);
}
