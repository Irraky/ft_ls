/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:20:05 by drecours          #+#    #+#             */
/*   Updated: 2017/09/27 13:38:32 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			verify_spaces(int spaces[5], t_content *content)
{
	int	tmp;

	tmp = ft_ilen(content->buff->st_nlink) + 1;
	spaces[0] = tmp > spaces[0] ? tmp : spaces[0];
	if (getpwuid(content->buff->st_uid))
		tmp = ft_strlen((getpwuid(content->buff->st_uid))->pw_name) + 1;
	else
		tmp = ft_ilen(content->buff->st_uid);
	spaces[1] = tmp > spaces[1] ? tmp : spaces[1];
	if (getpwuid(content->buff->st_uid))
		tmp = ft_strlen((getgrgid(content->buff->st_gid))->gr_name) + 1;
	else
		tmp = ft_ilen(content->buff->st_gid);
	spaces[2] = tmp > spaces[2] ? tmp : spaces[2];
	if ((content->buff->st_mode & S_IFMT) == S_IFCHR)
	{
		tmp = ft_ilen(minor(content->buff->st_rdev));
		spaces[4] = tmp > spaces[4] ? tmp : spaces[4];
		tmp = ft_ilen(major(content->buff->st_rdev));
	}
	else
		tmp = ft_ilen(content->buff->st_size) + 1;
	spaces[3] = tmp > spaces[3] ? tmp : spaces[3];
}

static void			count_spaces(int spaces[5], t_content *content)
{
	spaces[0] = 2;
	spaces[1] = 5;
	spaces[2] = 5;
	spaces[3] = 2;
	spaces[4] = 2;
	while (content && content->buff)
	{
		verify_spaces(spaces, content);
		content = content->next;
	}
}

static t_content	*add_total(t_content *content, int *total)
{
	char		*name;

	name = (ft_strrchr(content->path, '/') == NULL) ? content->path
		: (ft_strrchr(content->path, '/') + 1);
	*total += content->buff->st_blocks;
	content = content->next;
	return (content);
}

void				count(t_content *content, t_env *env, int spaces[5],
					t_dir *dir)
{
	int			total;
	t_content	*tmp;

	total = 0;
	tmp = content;
	if (content != NULL)
	{
		count_spaces(spaces, content);
		while (content && content->path)
			content = add_total(content, &total);
	}
	if (dir && dir->dname && tmp != NULL && env->flag[0])
		ft_printf("total %d\n", total);
	env->flagname = 0;
}
