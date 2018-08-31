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
	
	ft_check_input(ac, av);
	c = ft_memalloc(sizeof(t_obj));
	ft_init(c);
	fdr = open(av[1], O_RDONLY);
	ft_read_file(c, fdr);
	print(c->raw);
	ft_free_stuff(c);
	ft_putnbr(ft_encode("r2,23,%34"));
	// while (1)
	// 	;
	return (0);
}
