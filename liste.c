/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:50:05 by drecours          #+#    #+#             */
/*   Updated: 2017/06/20 16:42:03 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		main(void)
{
	t_content *content = ft_memalloc(sizeof (t_content));
	t_content *ptr = content;

	t_content *new = ft_memalloc(sizeof (t_content));
	new->name = "canard";
	new->next = content;

	t_content *ne = ft_memalloc(sizeof (t_content));
	ne->name = "poisson";
	ne->next = content;

		while (ne != NULL)
		{
			printf("%s", ne->name);
			ne = ne->next;
		}
	return 0;
}
