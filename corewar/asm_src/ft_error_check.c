#include "../includes/corewar.h"

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