/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:33:44 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 18:22:34 by drecours         ###   ########.fr       */
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
		content = new_elem(content, ".");
	while (arg[++i])
		if (lstat(arg[i], &buf) == -1)
		{
			ft_printf("ls: %s: ", arg[i]);
			perror("");
		}
	i = -1;
	while (arg[++i])
		if (lstat(arg[i], &buf) != -1)
			content = new_elem(content, arg[i]);
	return (content);
}

t_content		*parsing_args(char **arg, int arc, t_env *env)
{
	int			i;
	int			begin;
	t_content	*content;

	i = 0;
	begin = 1;
	content = ft_memalloc(sizeof(t_content));
	if (arc > 1)
		while (arg[begin] && arg[begin][0] == '-')
			begin++;
	if (arc - begin == 1 || 0)
		env->flagname = 1;
	if (arg[begin] != NULL)
		sort_alpha(&arg[begin]);
	content = sort_type(&arg[begin], content);
	/*while (content->name != NULL)
	{
		if (!S_ISDIR(content->buff->st_mode))
			ft_printf("\nvalid : %s\n", content->name);
		content = content->next;
	}*/
	return (content);
}
