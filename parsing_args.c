/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:59:49 by drecours          #+#    #+#             */
/*   Updated: 2017/09/27 13:59:53 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_alpha(char **arg)
{
	int				ite;
	char			*tmp;

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

static t_content	*no_elem(void)
{
	t_content		*new;

	if (!(new = ft_memalloc(sizeof(t_content))))
		exit(-1);
	new->path = ft_strdup(".");
	if (!(new->buff = (struct stat*)ft_memalloc(sizeof(struct stat))))
		exit(-1);
	if (lstat(new->path, new->buff) == -1)
	{
		write(2, "ls: ", 4);
		perror(new->path);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static t_content	*sort_type(char **arg, t_content *content, t_env *env)
{
	struct stat		buf;
	int				i;

	i = -1;
	if (arg[0] == NULL)
		content = no_elem();
	while (arg[++i])
		if (lstat(arg[i], &buf) == -1)
		{
			write(2, "ls: ", 4);
			perror(arg[i]);
		}
	i = -1;
	while (arg[++i])
	{
		if (lstat(arg[i], &buf) != -1)
			content = new_elem(content, arg[i], NULL);
		if (i == 0)
			env->end = content;
	}
	return (content);
}

t_content			*parsing_args(char **arg, int arc, t_env *env)
{
	int				begin;
	t_content		*content;

	begin = 1;
	content = NULL;
	if (arc > 1)
		while (arg[begin])
		{
			if (ft_strcmp(arg[begin], "--") == 0)
			{
				begin++;
				break ;
			}
			if (arg[begin][0] == '-' && arg[begin][1] != '\0')
				begin++;
			else
				break ;
		}
	env->flagname = (arc - begin <= 1) ? 1 : env->flagname;
	env->nbthing = (arc - begin > 1) ? 1 : env->nbthing;
	if (arg[begin] != NULL)
		sort_alpha(&arg[begin]);
	content = sort_type(&arg[begin], content, env);
	return (content);
}
