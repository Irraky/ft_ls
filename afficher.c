/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:27:44 by drecours          #+#    #+#             */
/*   Updated: 2017/05/24 15:03:16 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<stdlib.h>
#include "ft_ls.h"
#include "get_data.c"

static void			init_env(t_env *env)
{
	env->pflag = 0;
}
/*
static void			destroy_env(t_env *env)
{
}
*/
int		main(int argc, char **argv)
{
	t_env env;
//	struct dirent *lecture;
//	struct	stat fichier;
	DIR *rep;
	(void)argc;
	rep = opendir("." );
	init_env(&env);
	if (get_data(argv, &env) != -1)
		printf("%s", env.flag);
	argv[1] = argv[2];
	//print_data;
//	destroy_env(&env);
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
