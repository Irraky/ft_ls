/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:10:46 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 19:06:47 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		get_features(t_e *env, const char *format, int i, va_list arg)
{
	if (env->conv.conversion != 15)
		env->indexstr = env->indexstr + i + 1;
	else
		env->indexstr += 1;
	getchamp(env, format, arg);
	getprecision(env, format, arg);
	littleflags(env, format);
}

static int		get_conv(t_e *env, int j, int i, const char *format)
{
	env->conv.conversion = j;
	if (format[env->indexstr + i - 1] == 'l')
	{
		if (format[env->indexstr + i - 2] == 'l')
			env->ll = 1;
		else
			env->l = 1;
	}
	if (format[env->indexstr + i - 1] == 'h')
	{
		if (format[env->indexstr + i - 2] == 'h')
			env->hh = 1;
		else
			env->h = 1;
	}
	if (format[env->indexstr + i - 1] == 'j')
		env->j = 1;
	if (format[env->indexstr + i - 1] == 'z')
		env->z = 1;
	return (1);
}

void			get_d(t_e *env, const char *format, va_list arg)
{
	int			i;
	int			j;
	const char	*conversions = "SspDdiOoUuXxCc%";

	i = 1;
	j = -1;
	env->i = env->indexstr;
	while (format[env->indexstr + i])
	{
		while (conversions[++j])
			if (format[env->indexstr + i] == conversions[j])
				if (get_conv(env, j, i, format) == 1)
					break ;
		if (env->conv.conversion >= 0)
			break ;
		j = -1;
		i++;
	}
	if (env->conv.conversion == 15 || env->conv.conversion == -1)
	{
		env->conv.conversion = 15;
	}
	get_features(env, format, i, arg);
	if (env->conv.precision < -1)
		env->conv.precision = -1;
}
