/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/23 17:32:36 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_alpha(char **arg)
{
	int		ite;
	char	*tmp;

	ite = 0;
	while (arg[ite + 1])
	{
		if (ft_strcmp(arg[ite], arg[ite + 1]) > 0)
		{
			tmp = arg[ite];
			arg[ite] = arg[ite + 1];
			arg[ite + 1] = tmp;
			ite = 0;
		}
		ite++;
	}
}

t_content	*sort_type(char **arg, t_content *content)
{
	struct stat buf;
	int			i;

	i = -1;
	if (arg[0] == NULL)
		content = new_elem(content, ".");
	while (arg[++i])
		if (lstat(arg[i], &buf) == -1)
		{
			ft_printf("ls: %s: ", arg[i]);
			perror("");
		}
	i--;
	while (i >= 0)
	{
		if (lstat(arg[i], &buf) != -1)
			content = new_elem(content, arg[i]);
		i--;
	}
	return (content);
}

void			manage_args(char **arg, int arc, t_env *env)
{
	int		i;
	int		begin;
	
	i = 0;
	begin = 1;
	t_content *content = ft_memalloc(sizeof(t_content));

	if (arc > 1)
		while (arg[begin] && arg[begin][0] == '-')
			begin++;
	if (arc - begin == 1 || 0)
		env->flagname = 1;
	if (arg[begin] != NULL)
		sort_alpha(&arg[begin]);
	content = sort_type(&arg[begin], content);
	while (content->name != NULL)
	{
		if(!S_ISDIR(content->buff->st_mode))
			ft_printf("\nvalid : %s\n", content->name);
		content = content->next;
	}
}
