/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:27:44 by drecours          #+#    #+#             */
/*   Updated: 2017/05/18 18:08:46 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<stdlib.h>
#include "ft_ls.h"

int		main()
{
	t_env env;
	struct dirent *lecture;
	struct	stat fichier;
	DIR *rep;
	env.a = 1;
	rep = opendir("." );
	while ((lecture = readdir(rep))) {
		if (lecture->d_name[0] != '.' || env.a == 1)
		{printf("%s\n", lecture->d_name);
		lstat(lecture->d_name, &fichier);
		printf("     %o\n", fichier.st_mode);
		}
		
	closedir(rep);
	return (0);
}
