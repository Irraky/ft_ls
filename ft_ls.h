/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:09:19 by drecours          #+#    #+#             */
/*   Updated: 2017/09/07 12:32:57 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/syslimits.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include "ft_printf/libftprintf.h"

# define WRONG_FLAG -1

typedef struct				s_content
{
	char					*path;
	struct stat				*buff;
	struct s_content		*next;
}							t_content;

typedef struct				s_dir
{
	char					*dname;
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
	int						start;
}							t_env;

/*
** FT_LS FUNCTIONS
*/

t_content	*parsing_args(char **arg, int arc, t_env *env);
void		details(t_content *content, t_env *env, int spaces[5]);
int			get_data(char **argv, t_env *env);
t_dir		*display_file(t_content *content, t_dir *dir, t_env *env, int start, int spaces[5]);
void		manage_dir(t_dir *dir, t_env *env);
void		rights(t_content *content);
void		count(t_content *content, t_dir *dir, t_env *env, int spaces[5]);
t_content	*lst_sort(t_content *content, short fg);
/*
** ADDITIONAL FONCTIONS
*/

t_dir		*new_node(t_dir *dir, char *str);
t_content	*new_elem(t_content *content, char *name, char *path);
t_content	*clean(t_content *content);
t_dir		*clean_it(t_dir *dir);
int			ft_printf(const char *format, ...);

char		*ft_strrchr(const char *s, int c);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strsub(const char *s, unsigned int start, int size);
char		*ft_joinfree(char const *s1, char const *s2, int nb);
void		ft_strdel(char **as);
void		ft_memdel(void **ap);
#endif
