/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:27:44 by drecours          #+#    #+#             */
/*   Updated: 2017/05/19 18:02:54 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<stdlib.h>
#include "ft_ls.h"
#include "get_data.c"

static void			init_env(t_env *env)
{
}

static void			destroy_env(t_env *env)
{
}

int		main(int argc, char **argv)
{
	t_env env;
	struct dirent *lecture;
	struct	stat fichier;
	DIR *rep;
	(void)argc;
	env.a = 1;
	rep = opendir("." );
	init_env(&env);
	if (!get_data(argv, &env))
		printf("ls : illegal option --%c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 'c');
	else
	//print_data;
	destroy_env(&env);
/*	while ((lecture = readdir(rep))) 
	{
		if (lecture->d_name[0] = '.' || env->a == 1)
		info(lecture);
		printf("%s", (lecture->d_name[0] == '.') ? "point point point\n" :
				((lecture->d_name[0] == 'a') ? "a\n" : "normal\n"));
		if (lecture->d_name[0] != '.' || env.a == 1)
		{
			printf("%s\n", lecture->d_name);
			lstat(lecture->d_name, &fichier);
			printf("     %o\n", fichier.st_mode);
		//}
	}*/
	closedir(rep);
	return (0);
}
