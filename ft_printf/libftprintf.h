/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:44:23 by drecours          #+#    #+#             */
/*   Updated: 2017/06/12 11:21:07 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR -1
# define BUFF_SIZE 1024

typedef struct			s_conversion_pourcent
{
	int					conversion;
	char				nb[65];
	char				nbp[65];
	int					precision;
	int					champ;
	int					neg;
	int					zero;
	int					space;
	int					sharp;
	int					plus;
}						t_conversion_pourcent;

typedef struct			s_envpf
{
	int						indexstr;
	int						i;
	int						indexbuff;
	int						weight;
	char					buffer[BUFF_SIZE];
	int						j;
	int						h;
	int						hh;
	int						l;
	int						ll;
	int						z;
	char					wchar[5];
	t_conversion_pourcent	conv;
}						t_envpf;

int						ft_printf(const char *format, ...);
void					ft_putinit(t_envpf *env, char *addit, int size);
void					data(t_envpf *env, const char *format, va_list conv);
typedef void			(*t_con)(va_list arg, t_envpf *env);

/*
**CONVERSIONS
*/
void					convitoa(va_list arg, t_envpf *env);
void					convitoabase(va_list arg, t_envpf *env, int base);
void					trick(wchar_t args, t_envpf *env);

void					convgs(va_list arg, t_envpf *env);
void					convs(va_list arg, t_envpf *env);
void					convp(va_list arg, t_envpf *env);
void					convgd(va_list arg, t_envpf *env);
void					convd(va_list arg, t_envpf *env);
void					convi(va_list arg, t_envpf *env);
void					convgo(va_list arg, t_envpf *env);
void					convo(va_list arg, t_envpf *env);
void					convgu(va_list arg, t_envpf *env);
void					convu(va_list arg, t_envpf *env);
void					convgx(va_list arg, t_envpf *env);
void					convx(va_list arg, t_envpf *env);
void					convgc(va_list arg, t_envpf *env);
void					convc(va_list arg, t_envpf *env);
void					convpercent(va_list arg, t_envpf *env);

/*
**FLAGS
*/

void					getchamp(t_envpf *env, const char *format, va_list arg);
void					getprecision(t_envpf *env, const char *format,
						va_list arg);
void					littleflags(t_envpf *env, const char *format);

/*
**LIBFT
*/
int						ft_wcsize(wchar_t c);
int						ft_wstrlen(const wchar_t *s);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
void					ft_bzero(void *s, size_t n);
void					ft_exit(char *s, int status);
int						ft_ilen(long long n);
void					ft_itoa(long long n, char *nb);
void					ft_itoa_base(unsigned long long num, unsigned long long
						base, char *nb);
void					ft_putchar(char c);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcpy(char *dst, const char *src);
size_t					ft_strlen(const char *s);
int						ft_tolower(int c);

#endif
