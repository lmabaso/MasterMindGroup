#include "../includes/push_swap.h"
#include <fcntl.h>

int		valid_arg(char *arg)
{
	return (ft_strequ(arg, "sa") || ft_strequ(arg, "sb") ||
			ft_strequ(arg, "ss") || ft_strequ(arg, "ra") ||
			ft_strequ(arg, "rb") || ft_strequ(arg, "pa") ||
			ft_strequ(arg, "pb") || ft_strequ(arg, "rr") ||
			ft_strequ(arg, "rra") || ft_strequ(arg, "rrb")
			|| ft_strequ(arg, "rra"));
}

int		getcmd(char **cmd, t_list *a, t_list *b)
{
	(void)b;
	while (get_next_line(0, cmd) > 0 && valid_arg(*cmd))
		ft_update(&a, &b, *cmd);
	if (*cmd && !valid_arg(*cmd))
		ft_putendl("error");
	else
		ft_putendl(ft_isdone(&a, &b) ? "OK" : "KO");
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char *line;

	line = NULL;
	init_check(ac, av, &a, &b);
	getcmd(&line, a, b);
	ft_lstfree(&a);
    ft_lstfree(&b);
	free(line);
	return (0);
}
