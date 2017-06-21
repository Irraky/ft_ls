/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagspart1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:25:00 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:06:27 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	wildcard(t_e *env, va_list arg, const char *format)
{
	int		i;

	if (format[env->i + 1] == '*')
	{
		i = va_arg(arg, int);
		if (i >= 0)
			env->conv.champ = i;
		else
		{
			env->conv.champ = -i;
			env->conv.neg = 1;
		}
	}
}

void			getchamp(t_e *env, const char *format, va_list arg)
{
	int		add;
	int		place;
	char	transit[11];

	add = 1;
	place = -1;
	wildcard(env, arg, format);
	while (env->i + add < env->indexstr - 1 && format[env->i + add] != '.')
	{
		if (ft_isdigit(format[env->i + add]) && format[env->i + add] != '0')
		{
			while (ft_isdigit(format[env->i + add]))
			{
				transit[++place] = format[env->i + add];
				add++;
			}
			transit[place + 1] = '\0';
			if (format[env->i + add] != '*')
				env->conv.champ = ft_atoi(transit);
			else
				wildcard(env, arg, &format[env->i + add]);
			break ;
		}
		add++;
	}
}

void			getprecision(t_e *env, const char *format, va_list arg)
{
	int		add;
	int		place;
	char	transit[11];

	add = 1;
	place = -1;
	while (env->i + add < env->indexstr - 1)
	{
		if (format[env->i + add] == '.')
		{
			if (format[env->i + add + 1] == '*')
				env->conv.precision = va_arg(arg, int);
			while (ft_isdigit(format[env->i + ++add]))
				transit[++place] = format[env->i + add];
			if (add == 0)
				transit[++place] = '0';
			transit[place + 1] = '\0';
			if (env->conv.precision == -1)
				env->conv.precision = ft_atoi(transit);
			break ;
		}
		add++;
	}
}

void			littleflags(t_e *env, const char *format)
{
	int			var;

	var = 0;
	while (env->i + var < env->indexstr - 1)
	{
		if (format[env->i + var] == ' ')
			env->conv.space = 1;
		if (format[env->i + var] == '#')
			env->conv.sharp = 1;
		if (format[env->i + var] == '+')
			env->conv.plus = 1;
		if (format[env->i + var] == '-')
			env->conv.neg = 1;
		if (format[env->i + var] == '0' &&
				!(format[env->i + var - 1] <= '9' &&
					format[env->i + var - 1] >= '1') &&
				format[env->i + var - 1] != '.')
			env->conv.zero = 1;
		var++;
	}
}
