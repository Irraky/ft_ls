/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/06/16 13:38:23 by drecours         ###   ########.fr       */
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

void				details(char *str, struct stat buf)
{
	struct passwd *pwd;
	struct group *grp;

	(void)str;
	type(buf.st_mode);
	rights(buf.st_mode);
	//details -> @ / +
	ft_printf("%*ld", 4, buf.st_nlink);
	if ((pwd = getpwuid(buf.st_uid)) != NULL)
		ft_printf(" %s ", pwd->pw_name);
	if ((grp = getgrgid(buf.st_gid)) != NULL)
		ft_printf("%s", grp->gr_name);
	ft_printf(" %llu\n", buf.st_size);
}
