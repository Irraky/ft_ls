/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:43:48 by drecours          #+#    #+#             */
/*   Updated: 2017/05/16 16:58:27 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wcsize(wchar_t c)
{
	if ((unsigned)c < 0x80)
		return (1);
	else if ((unsigned)c <= 0x800)
		return (2);
	else if ((unsigned)c <= 0xd800 || (unsigned)c - 0xE000 < 0x2000)
		return (3);
	else if ((unsigned)c - 0x10000 < 0x100000)
		return (4);
	return (1);
}
