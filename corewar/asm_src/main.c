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

void	ft_free_stuff(t_obj *c)
{
	ft_lfree(&c->raw);
	free(c->info);
}

int		main(int ac, char **av)
{
	t_obj		*c;
	int			fdr;
	int			fdw;
	unsigned char *put;
	int i;
	
	ft_check_input(ac, av);
	c = ft_memalloc(sizeof(t_obj));
	ft_init(c);
	fdr = open(av[1], O_RDONLY);
	ft_read_file(c, fdr);
	print(c->raw);
	ft_free_stuff(c);
	ft_putnbr(ft_alloc_size("2,23,%34"));

	fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	put = ft_sti("r1,r1,%:live,%1");
	i = 0;
	ft_putuchar_fd(COREWAR_EXEC_MAGIC , fdw);
	while (i < ft_alloc_size("r1,r1,%:live,%1") + 2)
	{
		ft_putuchar_fd(put[i], fdw);
		i++;
	}
	// ft_putstr_fd(ft_strrchr(line, ' ') + 2, fdw);
	// while (1)
	// 	;
	return (0);
}
