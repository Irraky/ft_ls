/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:09:19 by drecours          #+#    #+#             */
/*   Updated: 2017/07/05 13:18:29 by drecours         ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

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
	char					flag[6];
	int						pflag;
	int						flagname;
}							t_env;

/*
** FT_LS FUNCTIONS
*/

t_content	*parsing_args(char **arg, int arc, t_env *env);
void		details(char *name, t_env *env);
int			get_data(char **argv, t_env *env);
t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int deb);
void		manage_dir(t_dir *dir, t_env *env);
/*
** ADDITIONAL FONCTIONS
*/

t_dir		*new_node(t_dir *dir, char *str, char *str2, int start);
t_content	*new_elem(t_content *content, char *str, char *path);
void		clean(t_content *content);
t_dir		*clean_it(t_dir *dir);
int			ft_printf(const char *format, ...);

void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_joinfree(char const *s1, char const *s2, int nb);
#endif
