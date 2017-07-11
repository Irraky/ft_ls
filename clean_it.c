/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:06:23 by drecours          #+#    #+#             */
/*   Updated: 2017/07/11 01:34:19 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*clean_it(t_dir *dir)
{
	t_dir		*tmp;

	tmp = dir;
	if (dir->next != NULL)
	{
		dir = dir->next;
		free(tmp->dname);
		free(tmp);
	}
	return (dir);
}
