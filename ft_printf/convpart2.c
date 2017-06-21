/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:54:51 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:04:36 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		putnwchar(const wchar_t *str, t_e *env)
{
	int					printed;
	int					i;

	printed = 0;
	i = 0;
	while (str[i] && printed + ft_wcsize(str[i]) <= env->conv.precision)
	{
		printed += ft_wcsize(str[i]);
		trick(str[i], env);
		i++;
	}
}

static int		lgs(t_e *env, const wchar_t *str)
{
	int					i;
	int					size;

	i = 0;
	size = 0;
	env->conv.precision = (env->conv.precision == -1) ? ft_wstrlen(str) :
		env->conv.precision;
	while (str[i] && size + ft_wcsize(str[i]) <= env->conv.precision)
		size += ft_wcsize(str[i]);
	return (env->conv.champ - size);
}

void			convgs(va_list args, t_e *env)
{
	const wchar_t		*str = va_arg(args, wchar_t *);
	int					i;
	int					j;

	if (str == (wchar_t *)NULL)
		ft_putinit(env, "(null)", -1);
	else
	{
		j = -1;
		i = lgs(env, str);
		if (env->conv.neg == 1)
		{
			putnwchar(str, env);
			while (++j < i)
				ft_putinit(env, " ", -1);
		}
		else
		{
			while (++j < i)
				ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
			putnwchar(str, env);
		}
	}
}

void			convgc(va_list args, t_e *env)
{
	int					i;
	const wchar_t		s = va_arg(args, wchar_t);
	const int			j = ft_wcsize(s);

	i = -1;
	if (env->conv.neg == 1)
	{
		trick(s, env);
		while (++i < env->conv.champ - j)
			ft_putinit(env, " ", -1);
	}
	else
	{
		while (++i < env->conv.champ - j)
			ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
		trick(s, env);
	}
}
