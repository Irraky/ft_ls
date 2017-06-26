/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:09:19 by drecours          #+#    #+#             */
/*   Updated: 2017/06/26 18:51:54 by drecours         ###   ########.fr       */
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
#include <time.h>
#include "ft_printf/libftprintf.h"

# define WRONG_FLAG -1

typedef struct				s_content
{
	char					*name;
	struct stat				*buff;
	struct s_content		*next;
}							t_content;

typedef struct				s_dir
{
	char					*name;
	struct s_dir			*next;
}							t_dir;
/*
typedef struct				s_list
{
	t_dir					*start;
	t_content				*lname;
}							t_list;
*/
typedef struct				s_env
{
	int						pflag;
	char					flag[6];
	int						flagname;
}							t_env;

/*
** FT_LS FUNCTIONS
*/

t_content	*parsing_args(char **arg, int arc, t_env *env);
void		details(t_content *content);
int			get_data(char **argv, t_env *env);
t_dir		*display_file(t_content *content, t_dir *dir);
/*
** ADDITIONAL FONCTIONS
*/

t_dir		*new_node(t_dir *dir, char *str);
t_content	*new_elem(t_content *content, char *str);
int			ft_printf(const char *format, ...);

void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
#endif
