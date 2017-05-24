/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:28:29 by drecours          #+#    #+#             */
/*   Updated: 2017/04/28 13:42:46 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wstrlen(const wchar_t *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if ((unsigned)*s < 0x80)
			i++;
		else if ((unsigned)*s <= 0x800)
			i += 2;
		else if ((unsigned)*s <= 0xd800 || (unsigned)*s - 0xE000 < 0x2000)
			i += 3;
		else if ((unsigned)*s - 0x10000 < 0x100000)
			i += 4;
		s++;
	}
	return (i);
}
