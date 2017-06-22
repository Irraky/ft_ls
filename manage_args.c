/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/22 15:40:41 by drecours         ###   ########.fr       */
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

static t_content	*sort_type(char **arg, t_content *content)
{
	struct stat buf;
	int			i;

	i = 0;
	while (arg[i])
	{
		if (lstat(arg[i], &buf) == -1)
		{
			ft_printf("ls: %s: ", arg[i]);
			perror("");
		}
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (lstat(arg[i], &buf) != -1)
			printf("%s", arg[i]);
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
	if (arc > begin)
	{
		sort_alpha(&arg[begin]);
		content = sort_type(&arg[begin], content);
	}
	else
	{
			content = new_elem(content, ".");
	}

	while (content != NULL)
	{
		ft_printf("\nvalid : %s\n", content->name);
		content = content->next;
	}
}
