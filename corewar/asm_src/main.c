#include "../includes/corewar.h"
#include <fcntl.h>
#include <stdio.h>

void		ft_append(t_node** head, t_data new_data)
{
    t_node	*new_node;
    t_node	*last;

	new_node = ft_memalloc(sizeof(t_node));
	last = *head;
    new_node->entry = new_data;
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



int		ft_islabel(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (0);
		if (*str == ':')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strfix(char *str)
{
	char	*fix;
	size_t	i;

	i = 0;
	if (!(fix = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			fix[i] = ' ';
		else
			fix[i] = str[i];
		i++;
	}
	return (fix);
}

void	ft_check_input(int ac, char **ag)
{
	char *tmp;

	tmp = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage: ./asm [-a] <sourcefile.s>");
		ft_putendl("\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output");
		exit(0);
	}
	else
	{
		tmp = ft_strrchr(ag[1], '.');
		if (ft_strncmp(".s", tmp, 2))
		{
			ft_putendl("Invalid file input");
			exit(0);
		}
	}
	
}

void	ft_init(t_obj *c)
{
	c->info = ft_memalloc(sizeof(header_t));
	c->raw = NULL;
}

void	ft_init_header(t_obj *c)
{
	char		*fixinput;
	char		**tmp1;

	if (ft_strncmp(c->line, ".name", 5) == 0)
	{
		tmp1 = ft_strsplit(fixinput, ' ');
		ft_strcat(c->info->prog_name, tmp1[1]);
	}
	else if (ft_strncmp(c->line, ".comment", 8) == 0)
	{
		tmp1 = ft_strsplit(fixinput, ' ');
		ft_strcat(c->info->comment , tmp1[1]);
	}
}

void	ft_process_input(t_obj *c)
{
	char		**tmp1;

	tmp1 = NULL;
	if (ft_strlen(c->fixinput) != 0)
	{
		if (ft_islabel(c->fixinput))
		{
			tmp1 = ft_strsplit(c->fixinput, ' ');
			c->entry.label = tmp1[0];
			c->entry.opcode = tmp1[1];
			c->entry.data = tmp1[2];
			ft_append(&c->raw, c->entry);
		}
		else
		{
			tmp1 = ft_strsplit(c->fixinput, ' ');
			c->entry.label = NULL;
			c->entry.opcode = tmp1[0];
			c->entry.data = tmp1[1];
			ft_append(&c->raw, c->entry);
		}
	}
}

void	ft_read_file(t_obj *c, int fdr)
{
	while (get_next_line(fdr, &c->line))
	{
		c->fixinput = ft_strfix(c->line);
		if (c->line[0] == '.')
			ft_init_header(c);
		else
			ft_process_input(c);
		free(c->line);
	}
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

	while (c->raw)
	{
		if (c->raw->entry.label)
			ft_putstr(c->raw->entry.label);
		ft_putstr(" ");
		ft_putstr(c->raw->entry.opcode);
		ft_putstr(" ");
		ft_putendl(c->raw->entry.data);
		c->raw = c->raw->next;
	}
	return (0);
}
