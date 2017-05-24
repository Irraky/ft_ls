/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <drecours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:36:47 by drecours          #+#    #+#             */
/*   Updated: 2017/05/02 15:26:35 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_strrev2(char *s1)
{
	char			s2[65];
	size_t			i;
	size_t			j;

	ft_bzero(s2, 65);
	ft_strcpy(s2, s1);
	j = 0;
	i = ft_strlen(s1) - 1;
	while (s2[j])
	{
		s1[i] = s2[j];
		j++;
		i--;
	}
}

void			ft_itoa_base(unsigned long long num, unsigned long long base,
		char *nb)
{
	char			*str;
	int				i;

	str = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = 0;
	if (num == 0)
		nb[0] = '0';
	while (num > 0)
	{
		nb[i] = str[num % base];
		i++;
		num = num / base;
	}
	ft_strrev2(nb);
}
