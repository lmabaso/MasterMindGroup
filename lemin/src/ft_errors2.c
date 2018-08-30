#include "../includes/lem-in.h"

int         ft_err_pipes(t_string *tmp, t_string **input)
{
    if ((tmp->str && tmp->str[0] == 'L') ||
        (ft_strncmp(tmp->str, "###", 3) == 0))
        return (1);
    if (tmp->str && tmp->str[0] == '#')
    {
        if (!ft_strequ(tmp->str, "##start") && !ft_strequ(tmp->str, "##end"))
            deleteStr(input, tmp->str);
    }
    return (0);
}

int         ft_is_not_eof(t_string *tmp)
{
    while (tmp)
    {
        if (tmp->str && ft_strchr(tmp->str, '-'))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int         ft_first_check(t_string **tmp)
{
    if (!ft_isnumber((*tmp)->str) || ft_dup(*tmp) ||
			!ft_search(*tmp, "##start") || !ft_search(*tmp, "##end"))
		return (1);
	if (ft_isnumber((*tmp)->str))
	{
		if (ft_atoi((*tmp)->str) <= 0)
			return (1);
		(*tmp) = (*tmp)->next;
		if (ft_strequ((*tmp)->str, "##start"))
		{
			(*tmp) = (*tmp)->next;
			if ((*tmp)->next->str[0] == '#')
				return (1);
		} 
		else if ((*tmp)->str[0] == '#')
			return (1);
	}
    return (0);
}