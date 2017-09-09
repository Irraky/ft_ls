/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/09/09 13:04:01 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				type(mode_t x)
{
	if (S_ISLNK(x))
		ft_printf("l");
	else if (S_ISREG(x))
		ft_printf("-");
	else if (S_ISDIR(x))
		ft_printf("d");
	else if (S_ISCHR(x))
		ft_printf("c");
	else if (S_ISBLK(x))
		ft_printf("b");
	else if (S_ISFIFO(x))
		ft_printf("p");
	else if (S_ISSOCK(x))
		ft_printf("s");
}

static void				ft_blocksandtime(struct stat *data, int spaces[5], t_env *env)
{
	char	*tmp;
	char	*year;

	if (S_ISCHR(data->st_mode) || S_ISBLK(data->st_mode))
	{
		ft_printf("%*d", spaces[3] - 1, major(data->st_rdev));
		ft_printf(", %*d ", spaces[4] - 1, minor(data->st_rdev));
	}
	else
		ft_printf(" %*d ", (env->device == 1) ? spaces[3] +
				spaces[4] - 1 : spaces[3], data->st_size);
	if ((time(NULL) - data->st_mtime) >= (525600 * 60 / 2))
	{
		tmp = ft_strsub(ctime(&(data->st_mtime)), 4, 7);
		year = ft_strsub(ctime(&(data->st_mtime)), 19, 5);
		ft_printf("%s%s ", tmp, year);
		ft_strdel(&year);
	}
	else
	{
		tmp = ft_strsub(ctime(&(data->st_mtime)), 4, 12);
		ft_printf("%s ", tmp);
	}
	ft_strdel(&tmp);
}

static void			ft_name(t_content *content, t_env *env)
{
	char	*name;
	char	link[PATH_MAX];
	int	i;

	i = PATH_MAX;
	while (i >= 0)
		link[--i] = '\0';
	if ((name = ft_strrchr(content->path, '/')) == NULL)
		ft_printf("%s", content->path);
	else
		ft_printf("%s", &name[1]);
	if (env->flag[0] && S_ISLNK(content->buff->st_mode))
		if (readlink(content->path, link, 1024) != -1)
			ft_printf(" -> %s", link);
	ft_printf("\n");
}

void				details(t_content *content, t_env *env, int spaces[5])
{
	struct passwd	*pwd;
	struct group	*grp;

	if (env->flag[0] && !(env->flagname == 1 && S_ISDIR(content->buff->st_mode)))
	{
		type(content->buff->st_mode);
		rights(content);
		ft_printf("%*d ", spaces[0], content->buff->st_nlink);
		if ((pwd = getpwuid(content->buff->st_uid)) != NULL && pwd->pw_name)
			ft_printf("%*-s ", spaces[1], pwd->pw_name);
		else
			ft_printf("%*-d ", spaces[1], content->buff->st_uid);
		if ((grp = getgrgid(content->buff->st_gid)) != NULL && grp->gr_name)
			ft_printf("%*-s", spaces[2], grp->gr_name);
		else
			ft_printf("%*-d ", spaces[2], content->buff->st_gid);
		ft_blocksandtime(content->buff, spaces, env);
	}
	if (!(env->flagname == 1 && S_ISDIR(content->buff->st_mode)))
		ft_name(content, env);
}
