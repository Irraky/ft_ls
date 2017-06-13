/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/06/13 18:51:13 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

static void			type(mode_t x)
{
	if (S_ISLNK(x))
		write(1, "l", 1);
	else if (S_ISREG(x))
		write(1, "-", 1);
	else if (S_ISDIR(x))
		write(1, "d", 1);
	else if (S_ISCHR(x))
		write(1, "c", 1);
	else if (S_ISBLK(x))
		write(1, "b", 1);
	else if (S_ISFIFO(x))
		write(1, "p", 1);
	else if (S_ISSOCK(x))
		write(1, "s", 1);
}

static void			rights(mode_t x)
{
	write(1, (S_IRUSR & x) ? "r" : "-", 1);
	write(1, (S_IWUSR & x) ? "w" : "-", 1);
	write(1, (S_IXUSR & x) ? "x" : "-", 1);
	write(1, (S_IRGRP & x) ? "r" : "-", 1);
	write(1, (S_IWGRP & x) ? "w" : "-", 1);
	write(1, (S_IXGRP & x) ? "x" : "-", 1);
	write(1, (S_IROTH & x) ? "r" : "-", 1);
	write(1, (S_IWOTH & x) ? "w" : "-", 1);
	write(1, (S_IXOTH & x) ? "x" : "-", 1);
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
