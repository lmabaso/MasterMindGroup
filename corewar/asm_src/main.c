#include "../includes/corewar.h"
#include <fcntl.h>
#include <stdio.h>

void	print(t_node *raw)
{
	while (raw)
	{
		if (raw->entry.label)
			ft_putstr(raw->entry.label);
		ft_putstr(" - ");
		ft_putstr(raw->entry.opcode);
		ft_putstr(" - ");
		ft_putendl(raw->entry.data);
		raw = raw->next;
	}
}

int		ft_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_puthex(int hex, int fd)
{
	if (hex > 255)
		ft_puthex(hex / 256, fd);
	ft_putchar_fd(hex % 256, fd);
	
}

void	ft_free_stuff(t_obj *c)
{
	ft_lfree(&c->raw);
	free(c->info);
}

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
	while (i < COMMENT_LENGTH + 6)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void				ft_writer(t_obj	*c)
{
	int				fdw;
	// unsigned char	*put;
	int				i;

	fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	// put = ft_sti("r1,r1,%:live,%1");
	i = 0;
	// ft_puthex(COREWAR_EXEC_MAGIC , fdw);
	ft_putuchar_fd(0, fdw);
	ft_puthex(COREWAR_EXEC_MAGIC, fdw);
	ft_write_name(c->info->prog_name, fdw);
	ft_write_comment(c->info->comment, fdw);
	// while (i < ft_alloc_size("r1,r1,%:live,%1") + 2)
	// {
	// 	ft_putuchar_fd(put[i], fdw);
	// 	i++;
	// }
}
int		main(int ac, char **av)
{
	t_obj		*c;
	int			fdr;
	
	ft_check_input(ac, av);
	c = ft_memalloc(sizeof(t_obj));
	ft_init(c);
	fdr = open(av[1], O_RDONLY);
	ft_read_file(c, fdr);
	// print(c->raw);
	ft_free_stuff(c);
	// ft_putnbr(ft_alloc_size("2,23,%34"));
	ft_writer(c);
	// ft_putstr_fd(ft_strrchr(line, ' ') + 2, fdw);
	while (1)
		;
	return (0);
}
