/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/07/05 18:15:46 by drecours         ###   ########.fr       */
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

void				details(char *name, t_env *env)
{
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		buff;

	lstat(name, &buff);
	//details -> @ / +
	if (ft_strchr(env->flag, 'l'))
	{
		type(buff.st_mode);
		rights(buff.st_mode);
		ft_printf("%*ld", 4, buff.st_nlink);
		if ((pwd = getpwuid(buff.st_uid)) != NULL)
			ft_printf(" %s ", pwd->pw_name);
		if ((grp = getgrgid(buff.st_gid)) != NULL)
			ft_printf("%s", grp->gr_name);
		ft_printf(" %llu", buff.st_size);
		ft_printf(" %.12s", &ctime(&buff.st_atime)[4]);
	}
	ft_printf(" %s\n", name);
}
