/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:34:09 by drecours          #+#    #+#             */
/*   Updated: 2017/07/19 15:31:52 by drecours         ###   ########.fr       */
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
			ft_printf(" %s ", pwd->pw_name);
		if ((grp = getgrgid(content->buff->st_gid)) != NULL)
			ft_printf("%s", grp->gr_name);
		ft_printf(" %llu", content->buff->st_size);
		ft_printf(" %.12s ", &ctime(&content->buff->st_ctime)[4]);
	}
	if ((name = ft_strrchr(content->path, '/')) == NULL)
		ft_printf("%s\n", content->path);
	/// ERREUR ICIIIII ///
	else
		ft_printf("%s\n", &name[1]);
}
