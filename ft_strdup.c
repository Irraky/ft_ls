/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:24:56 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 16:27:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*truc;

	i = -1;
	len = ft_strlen(s1);
	if (!(truc = ft_memalloc(sizeof(char) * len + 1)))
		return (0);
	while (i++ != len)
		truc[i] = s1[i];
	truc[i] = '\0';
	return (truc);
}
