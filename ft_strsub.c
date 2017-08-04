/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:52:47 by drecours          #+#    #+#             */
/*   Updated: 2017/08/02 18:23:26 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strsub(char const *s, unsigned int start, int size)
{
	char	*troncon;
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(troncon = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size)
		troncon[i] = s[start + i];
	troncon[i] = '\0';
	return (troncon);
}
