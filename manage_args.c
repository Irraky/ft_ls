/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:44:34 by drecours          #+#    #+#             */
/*   Updated: 2017/06/20 17:06:15 by drecours         ###   ########.fr       */
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

static t_content	*sort_type(char **arg, t_env *env, t_content *content)
{
	struct stat buf;
	char	**tmp;

	(void)env;
	tmp = arg;
	while (*arg)
	{
		if (lstat(*arg, &buf) == -1)
		{
			ft_printf("ls: %s: ", *arg);
			perror("");
		}
		arg += 1;
	}
	while (*tmp)
	{
		if (lstat(*tmp, &buf) != -1)
			content = new_elem(content, *tmp);
		tmp += 1;
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
		content = sort_type(&arg[begin], env, content);
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
