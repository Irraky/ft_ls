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

void				rights(mode_t x)
{
	usr_rights(x);
	grp_rights(x);
	oth_rights(x);
}
