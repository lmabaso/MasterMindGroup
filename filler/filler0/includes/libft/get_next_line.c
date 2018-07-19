/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 20:20:54 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/01 17:58:23 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(int const fd, char **str)
{
	char	*buff;		// For reading a line in the 
	char	*tmp;		// Temporal holder for freeing str
	int		readchars;	// For holding the number of chars read

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1)))) // malloc to the buff size and accountfor the null terminator
		return (-1);
	readchars = read(fd, buff, BUFF_SIZE); // read from the file pointed by the file desciptor and return the numbers of charectors read
	if (readchars > 0) // if something is read
	{
		buff[readchars] = '\0'; // Null terminate at the end of what is read
		tmp = ft_strjoin(*str, buff); // join the last line with the new line read
		free(*str);	// Free what ever is in the string so we can have a fresh sring
		*str = tmp;	// Now we put the freshly created string to our str which is running from our gnl funtion
	}
	free(buff); // we now free aur buff since we done uning is
	return (readchars); // we return number of chars read
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL; // This variable runs at the start up of this program
	char		*next_line;	// This will hold the location of the new line from str
	int			readchars;	// This holds the number if charectors read

	if ((!str && !(str = (char *)malloc(sizeof(*str)))) ||
			!line || fd < 0 || BUFF_SIZE < 0) // this evaluates our str if there is no str then it mallocs 
		return (-1); // Exit with an error
	next_line = ft_strchr(str, '\n'); // Check for a new line the point to it when found
	while (next_line == '\0')	// if nexline is pointing to nothing the keep the loop going
	{
		readchars = ft_read(fd, &str);	// This will return the number of charectors read, we pass the addess of str so str is passed as a referance
		if (readchars < 0) // if and error occures return this exit condition
			return (-1);
		if (!readchars && !ft_strlen(str)) // if we done reading return this exit condition
			return (0);
		if (!readchars) // if didn't read anything, but there something on str
			str = ft_strjoin(str, "\n"); // want to put end line on our str, happens at the end of the document
		next_line = ft_strchr(str, '\n'); // check for new line and points to it if found
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(next_line)); // This will cut the str and return the first part of the str from the '\n'->new line
	next_line = ft_strdup(next_line + 1); // we now allocating memory for the new line, preparing it to put it on out str, the static variable
	free(str); // This will free our str
	str = next_line; // now str is poinding to this new line memory
	return (1); //return this exit condition
}
