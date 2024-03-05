
#include "../../include/minishell_general_library.h"

ft_pipe_check(char *line)
{
	//this is stupid
	//here it's already tokens so just check that there's a token which is not a space
}

int	ft_qt_check(char *line, char c)
{
	int	qt_end;
	
	qt_end = 1;
	while(line[qt_end])
	{
		if (line[qt_end] == c)
			return (0);
		qt_end++;
	}
	// print quote error and exit
}

int	ft_parse(char *line)
{
	int		i;
	char	c;
	
	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == '"' || line == "'")
		{
			c = line[i];
			ft_qt_check(line[i], c);
			while (line[i] != c)
				i++;
			i++;
		}
		if (line[i] == '|')
			ft_pipe_check(line);
		i++;
	}
}
