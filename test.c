/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:20:13 by drecours          #+#    #+#             */
/*   Updated: 2017/06/23 17:32:42 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



struct dirent* readdir(DIR* repertoire) ;

int main()
{
	struct stat buf;

	DIR* rep = NULL;
	struct dirent* fichierLu = NULL; /* Déclaration d'un pointeur vers la structure dirent. */
	rep = opendir(".");
	if (rep == NULL)
		exit(1);

	fichierLu = readdir(rep); /* On lit le premier répertoire du dossier. */
	while ((fichierLu = readdir(rep)) != NULL)
	{
		lstat(fichierLu->d_name, &buf);
		if (S_ISDIR( buf.st_mode))
		    ft_printf("Le fichier lu s'appelle '%s'\n", fichierLu->d_name);
	}
	if (closedir(rep) == -1)
		exit(-1);

	return 0;
}

