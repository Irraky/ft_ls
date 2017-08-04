/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/08/04 12:44:48 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			type(mode_t x)
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

static void			rights(mode_t x)
{
	ft_printf((S_IRUSR & x) ? "r" : "-");
	ft_printf((S_IWUSR & x) ? "w" : "-");
	ft_printf((S_IXUSR & x) ? "x" : "-");
	ft_printf((S_IRGRP & x) ? "r" : "-");
	ft_printf((S_IWGRP & x) ? "w" : "-");
	ft_printf((S_IXGRP & x) ? "x" : "-");
	ft_printf((S_IROTH & x) ? "r" : "-");
	ft_printf((S_IWOTH & x) ? "w" : "-");
	ft_printf((S_IXOTH & x) ? "x" : "-");
}

static void print_time(struct stat *data)
{
	char	*tmp;
	char	*year;

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

void				details(t_content *content, t_env *env)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*name;

	//details -> @ / +
	if (env->flag[0])
	{
		type(content->buff->st_mode);
		rights(content->buff->st_mode);
		ft_printf("%*ld", 4, content->buff->st_nlink);
		if ((pwd = getpwuid(content->buff->st_uid)) != NULL)
			if (pwd->pw_name)
				ft_printf(" %s ", pwd->pw_name);
		if ((grp = getgrgid(content->buff->st_gid)) != NULL)
			if (grp->gr_name)
				ft_printf("%s", grp->gr_name);
		ft_printf(" %llu", content->buff->st_size);
		print_time(content->buff);
	}
	if ((name = ft_strrchr(content->path, '/')) == NULL)
		ft_printf("%s\n", content->path);
	else
		ft_printf("%s\n", &name[1]);
}
