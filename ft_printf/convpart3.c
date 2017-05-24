/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:06:36 by drecours          #+#    #+#             */
/*   Updated: 2017/05/16 17:09:26 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			trick(wchar_t args, t_env *env)
{
	ft_bzero(&env->wchar, 5);
	if ((unsigned)args < 0x80 || (MB_CUR_MAX == 1 && (unsigned)args <= 255))
		env->wchar[0] = args;
	else if ((unsigned)args <= 0x800 && MB_CUR_MAX != 1)
	{
		env->wchar[0] = ((args >> 6) + 0xC0);
		env->wchar[1] = ((args & 0x3F) + 0x80);
	}
	else if (((unsigned)args <= 0xd800 || (unsigned)args - 0xE000 < 0x2000)
			&& MB_CUR_MAX != 1)
	{
		env->wchar[0] = ((args >> 12) + 0xE0);
		env->wchar[1] = (((args >> 6) & 0x3F) + 0x80);
		env->wchar[2] = ((args & 0x3F) + 0x80);
	}
	else if ((unsigned)args - 0x10000 < 0x100000 && MB_CUR_MAX != 1)
	{
		env->wchar[0] = ((args >> 18) + 0xF0);
		env->wchar[1] = (((args >> 12) & 0x3F) + 0x80);
		env->wchar[2] = (((args >> 6) & 0x3F) + 0x80);
		env->wchar[3] = ((args & 0x3F) + 0x80);
	}
	ft_putinit(env, env->wchar, (!env->wchar[0]) ? 1 : -1);
	env->weight = (MB_CUR_MAX == 1 && args > 255) ? -1 : env->weight;
}

void			convc(va_list arg, t_env *env)
{
	int			i;
	char		c;
	char		s[1];

	i = -1;
	if (env->l == 1)
		convgc(arg, env);
	else
	{
		c = (char)va_arg(arg, char *);
		s[0] = c;
		if (env->conv.neg == 1)
		{
			ft_putinit(env, (!c) ? "\0" : s, 1);
			while (++i < env->conv.champ - 1)
				ft_putinit(env, " ", 1);
		}
		else
		{
			while (++i < env->conv.champ - 1)
				ft_putinit(env, (env->conv.zero == 1) ? "0" : " ", -1);
			ft_putinit(env, (!c) ? "\0" : s, 1);
		}
	}
}

static void		tricks(t_env *env, char *str)
{
	int		i;
	int		j;

	j = -1;
	i = (env->conv.precision > (int)ft_strlen(str)) ? (env->conv.champ -
			(int)ft_strlen(str)) : (env->conv.champ - env->conv.precision);
	i = (env->conv.precision < 0) ? env->conv.champ - ft_strlen(str) : i;
	if (env->conv.neg == 1)
	{
		ft_putinit(env, (char *)str, (env->conv.precision != -1 &&
					env->conv.precision < (int)ft_strlen(str)) ?
				env->conv.precision : (int)ft_strlen(str));
		while (++j < i)
			ft_putinit(env, " ", -1);
	}
	else
	{
		while (++j < i)
			ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
		ft_putinit(env, (char *)str, (env->conv.precision != -1 &&
					env->conv.precision < (int)ft_strlen(str)) ?
				env->conv.precision : (int)ft_strlen(str));
	}
}

void			convs(va_list args, t_env *env)
{
	char	*str;
	char	*null;

	if (env->l == 1)
	{
		null = NULL;
		convgs(args, env);
	}
	else
		null = va_arg(args, char *);
	str = (!null && env->l == 0) ? "(null)" : null;
	if (env->l == 0 && str)
		tricks(env, str);
}

void			convpercent(va_list args, t_env *env)
{
	int	i;

	(void)args;
	i = -1;
	if (env->conv.neg == 1)
	{
		ft_putinit(env, "%", -1);
		while (++i < env->conv.champ - 1)
			ft_putinit(env, " ", -1);
	}
	else
	{
		while (++i < env->conv.champ - 1)
			ft_putinit(env, ((env->conv.zero == 1) ? "0" : " "), -1);
		ft_putinit(env, "%", -1);
	}
}
