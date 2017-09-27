/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:24:56 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 16:43:36 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*truc;

	i = 0;
	len = ft_strlen(s1);
	if (!(truc = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i != len)
	{
		truc[i] = s1[i];
		++i;
	}
	truc[len] = '\0';
	return (truc);
}
