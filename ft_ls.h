/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:09:19 by drecours          #+#    #+#             */
/*   Updated: 2017/06/12 11:38:13 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
#include <string.h>

# define WRONG_FLAG -1

typedef struct				s_env
{
	int						pflag;
	char					flag[6];
}							t_env;


char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_printf(const char *format, ...);
#endif
