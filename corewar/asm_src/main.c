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

void				ft_writer(t_obj	*c)
{
	int				fdw;
	int				i;
	unsigned char	*put;

	fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	put = ft_sti("r1,%:live,%1");
	i = 0;
	// ft_puthex(COREWAR_EXEC_MAGIC , fdw);
	ft_write_header(c, fdw);
	ft_putustr_fd(put, fdw);
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
	ft_writer(c);
	// ft_putstr_fd(ft_strrchr(line, ' ') + 2, fdw);
	// while (1)
	// 	;
	return (0);
}
