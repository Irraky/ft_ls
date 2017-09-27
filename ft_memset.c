/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:23:13 by drecours          #+#    #+#             */
/*   Updated: 2017/06/20 14:19:40 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char*)b;
	while (i != len)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}
