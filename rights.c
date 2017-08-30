#include "ft_ls.h"

static void			usr_rights(mode_t x)
{
	ft_printf((S_IRUSR & x) ? "r" : "-");
	ft_printf((S_IWUSR & x) ? "w" : "-");
	if ((S_ISUID & x) && !(S_IXUSR & x))
		ft_printf("S");
	else if (S_ISUID & x)
		ft_printf("s");
	else
		ft_printf((S_IXUSR & x) ? "x" : "-");
}

static void			grp_rights(mode_t x)
{
	ft_printf((S_IRGRP & x) ? "r" : "-");
	ft_printf((S_IWGRP & x) ? "w" : "-");
	if ((S_ISGID & x) && !(S_IXGRP & x))
		ft_printf("S");
	else if (S_ISGID & x)
		ft_printf("s");
	else
		ft_printf((S_IXGRP & x) ? "x" : "-");
}

static void			oth_rights(mode_t x)
{
	ft_printf((S_IROTH & x) ? "r" : "-");
	ft_printf((S_IWOTH & x) ? "w" : "-");
	if ((S_ISVTX & x) && !(S_IXOTH & x))
		ft_printf("S");
	else if (S_ISVTX & x)
		ft_printf("s");
	else
		ft_printf((S_IXOTH & x) ? "x" : "-");
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
	acl = acl_get_link_np(content->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	acl_c = acl ? '+' : acl_c;
	acl_c = listxattr(content->path, NULL, 0, XATTR_NOFOLLOW) > 0 ? '@' : acl_c;
	ft_printf("%c", acl_c);
}
