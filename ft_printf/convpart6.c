/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:15:36 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:06:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		convoplus(t_e *env)
{
	int		i;

	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	if (env->conv.nb[0] == '0' && env->conv.sharp == 1)
		i--;
	while (i < env->conv.precision)
		i++;
	while (env->conv.champ > i)
	{
		if (env->conv.zero == 1)
			ft_putinit(env, "0", -1);
		else
			ft_putinit(env, " ", -1);
		env->conv.champ--;
	}
	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	if (env->conv.sharp == 1)
		ft_putinit(env, "0", -1);
	while (i++ < env->conv.precision)
		ft_putinit(env, "0", -1);
	if (!(env->conv.sharp == 1 && env->conv.nb[0] == '0') &&
			!(env->conv.precision == 0 && env->conv.nb[0] == '0'))
		ft_putinit(env, env->conv.nb, -1);
}

void			convo(va_list args, t_e *env)
{
	int		i;

	if (env->conv.conversion == 7)
		convitoabase(args, env, 8);
	if (env->conv.nb[0] == '0' && env->conv.precision == 0 &&
			env->conv.champ > -1)
		env->conv.champ++;
	i = ft_strlen(env->conv.nb) + env->conv.sharp;
	i = (env->conv.nb[0] == '0') ? i++ : i;
	if (env->conv.neg == 1)
	{
		if (env->conv.sharp == 1)
			ft_putinit(env, "0", -1);
		while (i++ < env->conv.precision)
			ft_putinit(env, "0", -1);
		if (!(env->conv.nb[0] == '0' && env->conv.precision <= 0 &&
					env->conv.champ != 0))
			ft_putinit(env, env->conv.nb, -1);
		if (env->conv.nb[0] == '0')
			i--;
		while (env->conv.champ-- >= i)
			ft_putinit(env, " ", -1);
	}
	else
		convoplus(env);
}

void			convgo(va_list args, t_e *env)
{
	ft_itoa_base(va_arg(args, long int), 8, env->conv.nb);
	convo(args, env);
}
