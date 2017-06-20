/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:46:58 by drecours          #+#    #+#             */
/*   Updated: 2017/06/20 14:19:43 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = malloc(size)))
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}
