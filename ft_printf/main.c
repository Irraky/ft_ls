/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:56:22 by drecours          #+#    #+#             */
/*   Updated: 2017/05/15 17:43:40 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include<stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int		main(void)
{

	
	setlocale(LC_ALL, "en_US.UTF-8");
// ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", 
//			L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
//	printf("i%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", 
//			L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	//printf("\n|valeur printf: %d|\n", printf("%c", L'a'));
	//printf("%d", MB_CUR_MAX);
	//printf("\n|valeur ft_printf: %d|\n", ft_printf("\n|%lc|", L'暖'));
	//ft_printf("{%}");
	// printf("|%*.*d|\n", 7, 2, );
	 //ft_printf("|%*.*d|", 7);
	//printf("printf : |%D|\n", LONG_MAX);
	//printf("ft_printf : |%li|\n", LONG_MAX);
	//ft_printf("|%sv|\n", "a");
	//ft_printf("{%*d}", 0, 0);
	//ft_printf("{%*s}", "test", 0);
	//ft_printf("{%*d}", 0, 0);
	//ft_printf("{%*s}", "test", 0);
	//printf("{%3*d}", 0, 0);
	//printf("pf: %d\n", printf("{%3c}\n", 0));
	//ft_printf("pf: %d\n", printf("% z", 0));
	//printf("ipf: %d\n", ft_printf("%.5p", &i));
	//printf("pf: %d\n", printf("%p", (void *)0));
	//printf("{%*d}", -5, 42);
	//ft_printf("i{%*d}", -5, 42);
	/*printf("%d\n", ft_printf("%10d",  42));
	printf("%d\n", printf("%10d",  42));
	printf("%d\n", ft_printf("%10d",  -42));
	printf("%d\n", printf("%10d",  -42));
	printf("%d\n", ft_printf("%+10d",  42));
	printf("%d\n", printf("%+10d",  42));
	printf("%d\n", ft_printf("% 03d",  0));
	printf("%d\n", printf("% 03d",  0));
	printf("%d\n", ft_printf("%+3d",  0));
	printf("%d\n", printf("%+3d",  0));
	printf("%d\n", ft_printf("%+d",  0));
	printf("%d\n", printf("%+d",  0));
	printf("%d\n", ft_printf("%-+15.4d", -42));
	printf("%d\n", printf("%-+15.4d",  -42));
	printf("ICI %d\n", ft_printf("%15.4d",  -42));
	printf("ICI %d\n", printf("%15.4d",  -42));
	printf("%d\n", ft_printf("f%03.2d",  0));
	printf("%d\n", printf("p%03.2d",  0));
	printf("%d\n", ft_printf("f%04.2d",  0));
	printf("%d\n", printf("p%04.2d",  0));
	printf("%d\n", ft_printf("f%4d",  0));
	printf("%d\n", printf("p%4d",  0));
	printf("%d\n", ft_printf("%15.4d",  -424242));
	printf("%d\n", printf("%15.4d",  -424242));
	printf("%d\n", ft_printf("%-15.4d",  -42252));
	printf("%d\n", printf("%-15.4d",  -42252));
	printf("%d\n", ft_printf("%15.4d",  -42));
	printf("%d\n", printf("%15.4d",  -42));*/
	//printf("%d\n", ft_printf("%.u",  0));
	//printf("%d\n", printf("%.u",  0));
      //ft_printf("{%c}", "\0";
	  //printf("|%.0p|, |%.p|\n", 0, 0);
	//ft_printf("|%10p|, |%5p|", &i, &i);
	//printf("%15.4S\n", L"我是一只猫。");
	//printf("%p\n", (void *)0);
	//printf("%hhC, %hhC", 0, L'米');
	//printf("|%ld|\n", (long)INT_MAX + 1);
	//ft_printf("|%ld|", (long)INT_MAX + 1);
	ft_printf("%.5s\n", "asdfghj");
	printf("%.5s\n", "asdfghj");

	return 0;
}
