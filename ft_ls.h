/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:09:19 by drecours          #+#    #+#             */
/*   Updated: 2017/06/21 18:55:39 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include "ft_printf/libftprintf.h"

# define WRONG_FLAG -1

typedef struct				s_content
{
	char					*name;
	struct s_content		*next;
//	struct s_content		*prev;
}							t_content;

typedef struct				s_dir
{
	char					*name;
	struct s_dir			*next;
	struct s_dir			*prev;
}							t_dir;

typedef struct				s_list
{
	t_dir					*start;
	t_content				*firstname;
}							t_list;

typedef struct				s_env
{
	int						pflag;
	char					flag[6];
	int						flagname;
}							t_env;

/*
** FT_LS FUNCTIONS
*/

void		manage_args(char **arg, int arc, t_env *env);
void		details(char *str, struct stat buf);
int			get_data(char **argv, t_env *env);
/*
** ADDITIONAL FONCTIONS
*/

t_content	*new_elem(t_content *content, char *str);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_printf(const char *format, ...);
#endif
