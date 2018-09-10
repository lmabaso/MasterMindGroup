#include "../includes/corewar.h"

void	ft_write_name(char str[], int fd)
{
	int i;

	i = 0;
	while (i < PROG_NAME_LENGTH + 6)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	ft_write_comment(char str[], int fd)
{
	int i;

	i = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void    ft_write_header(t_obj *c, int fd)
{
    ft_putuchar_fd(0, fd);
	ft_puthex(COREWAR_EXEC_MAGIC, fd);
    ft_write_name(c->info->prog_name, fd);
    ft_puthex(0, fd);
    ft_puthex(c->info->prog_size, fd);
	ft_write_comment(c->info->comment, fd);
}