/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:06:23 by drecours          #+#    #+#             */
/*   Updated: 2017/06/27 17:47:46 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*clean_it(t_dir *dir)
{
	t_dir		*tmp;

	tmp = dir;
	dir = dir->next;
	printf("|%s|", tmp->name);
	//free(tmp->name);
	//free(tmp);
	return (dir);
}

void		load_balance(t_dir *dir)
{
	ft_printf("%s", dir->name);

	clean_it(dir);
	//if (dir->name != NULL)
	//	load_balance(dir);
}
