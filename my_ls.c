/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:27:44 by drecours          #+#    #+#             */
/*   Updated: 2017/07/04 17:14:47 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			init_env(t_env *env)
{
	env->pflag = 0;
	env->flagname = 0;
	env->flag = (t_flag){0, 0, 0, 0, 0};
}

int		main(int argc, char **argv)
{
	t_env		env;
	t_content	*content;
	t_dir		*dir;
//	t_dir		*tmp;
	//t_dir		*di;
//	struct dirent *lecture;
//	struct	stat fichier;
//	DIR *rep;
//	rep = opendir(".");
	dir = ft_memalloc(sizeof(t_dir));
	//tmp = dir;
	init_env(&env);
	if (get_data(argv, &env) == 1)
	{
		content = parsing_args(argv, argc, &env);
//		sort_args(content);
		ft_printf("|%s|", content->name);
		dir = display_file(content, dir, &env, 1);
		if (dir != NULL)
			manage_dir(dir, &env);
		/*while (dir != NULL)
		{
			di = dir;
			dir = dir->next;
			free(di->name);
			free(di);
		}*/
		//manage_list(list);
	}
//	free(tmp->name);
//	free(tmp);
	//print_data;
//	lecture = readdir(rep);
//	display_details(lecture);
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
//	closedir(rep);
//	while (1);
	return (0);
}
