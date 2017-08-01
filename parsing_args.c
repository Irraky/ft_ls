/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:33:44 by drecours          #+#    #+#             */
/*   Updated: 2017/08/01 15:07:27 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sort_alpha(char **arg)
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

t_content		*sort_type(char **arg, t_content *content)
{
	struct stat buf;
	int			i;

	i = -1;
	if (arg[0] == NULL)
		content = new_elem(content, ".", "");
	while (arg[++i])
		if (lstat(arg[i], &buf) == -1)
		{
			write(2, "ls: ", 4);
			perror(arg[i]);
		}
	i = -1;
	while (arg[++i])
		if (lstat(arg[i], &buf) != -1)
			content = new_elem(content, arg[i], NULL);
	return (content);
}

t_content		*parsing_args(char **arg, int arc, t_env *env)
{
	int			begin;
	t_content	*content;

	begin = 1;
	content = NULL;
	if (!(content = ft_memalloc(sizeof(t_content))))
		exit(-1);
	if (arc > 1)
		while (arg[begin])
		{
			if (ft_strcmp(arg[begin], "--") == 0)
			{
				begin++;
				break;
			}
			if (arg[begin][0] == '-' && arg[begin][1] != '\0')
				begin++;
			else
				break;
		}
	if (arc - begin == 1 || arc - begin == 0)
		env->flagname = 1;
	if (arg[begin] != NULL)
		sort_alpha(&arg[begin]);
	content = sort_type(&arg[begin], content);
	return (content);
}
