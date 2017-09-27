/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:20:24 by drecours          #+#    #+#             */
/*   Updated: 2017/09/25 16:06:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			usr_rights(mode_t x)
{
	ft_printf((S_IRUSR & x) ? "r" : "-");
	ft_printf((S_IWUSR & x) ? "w" : "-");
	if ((S_ISUID & x) && !(S_IXUSR & x))
		write(1, "S", 1);
	else if (S_ISUID & x)
		write(1, "s", 1);
	else
		write(1, (S_IXUSR & x) ? "x" : "-", 1);
}

static void			grp_rights(mode_t x)
{
	write(1, (S_IRGRP & x) ? "r" : "-", 1);
	write(1, (S_IWGRP & x) ? "w" : "-", 1);
	if ((S_ISGID & x) && !(S_IXGRP & x))
		write(1, "S", 1);
	else if (S_ISGID & x)
		write(1, "s", 1);
	else
		write(1, (S_IXGRP & x) ? "x" : "-", 1);
}

static void			oth_rights(mode_t x)
{
	write(1, (S_IROTH & x) ? "r" : "-", 1);
	write(1, (S_IWOTH & x) ? "w" : "-", 1);
	if ((S_ISVTX & x) && !(S_IXOTH & x))
		write(1, "S", 1);
	else if (S_ISVTX & x)
		write(1, "s", 1);
	else
		write(1, (S_IXOTH & x) ? "x" : "-", 1);
}

void				rights(t_content *content)
{
	char		acl_c;
	acl_t		acl;
	acl_entry_t	entry;

	acl_c = ' ';
	usr_rights(content->buff->st_mode);
	grp_rights(content->buff->st_mode);
	oth_rights(content->buff->st_mode);
	acl = NULL;
	acl = acl_get_link_np(content->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	acl_c = acl ? '+' : acl_c;
	acl_c = listxattr(content->path, NULL, 0, XATTR_NOFOLLOW) > 0 ? '@' : acl_c;
	ft_printf("%c", acl_c);
	if (acl)
		acl_free(acl);
}
