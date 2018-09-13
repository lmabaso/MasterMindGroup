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
	int				j;
	t_output		put;
	unsigned char	*code;
	t_node			*tmp;
	t_output		t;

	tmp = c->raw;
	fdw = open("test.cor", O_CREAT | O_WRONLY | O_TRUNC);
	put = ft_sti("r1,%1,1", c, 0);
	i = 0;
	code = ft_memalloc(c->info->prog_size);
	ft_write_header(c, fdw);
	while (tmp)
	{
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "sti"))
		{
			j = 0;
			t = ft_sti(tmp->entry.data, c, 1);
			while (j < t.size)
			{
				code[i] = t.bytes[j];
				i++;
				j++;
			}
		}
			
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "live"))
		{
			j = 0;
			t = ft_live(tmp->entry.data, c, 1);
			while (j < t.size)
			{
				code[i] = t.bytes[j];
				i++;
				j++;
			}
		}
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "and"))
		{
			j = 0;
			t =  ft_and(tmp->entry.data, c, 1);
			while (j < t.size)
			{
				code[i] = t.bytes[j];
				i++;
				j++;
			}
		}
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "zjmp"))
		{
			j = 0;
			t =  ft_zjmp(tmp->entry.data, c, 1);
			while (j < t.size)
			{
				code[i] = t.bytes[j];
				i++;
				j++;
			}
		}
		tmp = tmp->next;
	}
	ft_putustr_fd(c->info->prog_size, code, fdw);
}

void		ft_append_lable(t_lables** head, char *new_data, unsigned int addr)
{
    t_lables	*new_node;
    t_lables	*last;

	new_node = ft_memalloc(sizeof(t_lables));
	last = *head;
    new_node->lable = new_data;
	new_node->addr = addr;
    new_node->next = NULL;
    if (*head == NULL)
    {
       *head = new_node;
       return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return ;
}

unsigned int ft_get_prog_size(t_obj *c)
{
	unsigned int	size;
	t_node			*tmp;

	size = 0;
	tmp = c->raw;
	while (tmp)
	{
		if (tmp->entry.label)
			ft_append_lable(&c->lables, tmp->entry.label, size);
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "sti"))
			size += ft_sti(tmp->entry.data, c, 0).size;
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "live"))
			size += ft_sti(tmp->entry.data, c, 0).size;
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "and"))
			size += ft_sti(tmp->entry.data, c, 0).size;
		if (ft_strequ(ft_strtrim(tmp->entry.opcode), "zjmp"))
			size += ft_sti(tmp->entry.data, c, 0).size;
		tmp = tmp->next;
	}
	return (size + 1);
}

int		main(int ac, char **av)
{
	t_obj		*c;
	int			fdr;
	
	ft_check_input(ac, av);
	c = ft_memalloc(sizeof(t_obj));
	c->lables = NULL;
	ft_init(c);
	fdr = open(av[1], O_RDONLY);
	ft_read_file(c, fdr);
	c->info->prog_size = ft_get_prog_size(c);
	// print(c->raw);
	// ft_writer(c);
	ft_putnbr(c->info->prog_size);
	ft_free_stuff(c);
	// while (1)
	// 	;
	return (0);
}
