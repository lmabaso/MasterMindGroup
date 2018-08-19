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
			tmp = NULL;
			exit(0);
		}
	}
	
}

void	ft_process_input(t_obj *c)
{
	char		**tmp;
	int			i;

	tmp = NULL;
	if (ft_strlen(c->fixinput) != 0)
	{
		if (ft_islabel(c->fixinput))
		{
			tmp = ft_strsplit(c->fixinput, ' ');
			c->entry.label = ft_strdup(tmp[0]);
			c->entry.opcode = ft_strdup(tmp[1]);
			c->entry.data = ft_strdup(tmp[2]);
			ft_append(&c->raw, c->entry);
			i = 0;
			while (tmp[i])
			{
				free(tmp[i]);
				i++;
			}
			free(tmp);
			tmp = NULL;
		}
		else
		{
			tmp = ft_strsplit(c->fixinput, ' ');
			c->entry.label = NULL;
			c->entry.opcode = ft_strdup(tmp[0]);
			c->entry.data = ft_strdup(tmp[1]);
			ft_append(&c->raw, c->entry);
			i = 0;
			while (tmp[i])
			{
				free(tmp[i]);
				i++;
			}
			free(tmp);
			tmp = NULL;
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
		free(c->fixinput);
	}
}

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

void	ft_lfree(t_node **head)
{
	t_node  *current;
    t_node  *next;

    current = *head;
    while (current != NULL)
    {
		if (current->entry.label)
			free(current->entry.label);
		free(current->entry.opcode);
		free(current->entry.data);
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
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
	// while (1)
	// 	;
	return (0);
}
