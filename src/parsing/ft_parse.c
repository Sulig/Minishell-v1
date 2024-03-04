
#include "../../include/minishell_general_library.h"

char *ft_qt_check(char *line, char c)
{
    int     qt_start;
    int     qt_end;

    qt_start = 0;
    while (line[qt_start])
    {
        qt_end = qt_start;
        if (line[qt_start] == c)
        {
            while(line[qt_end])
            {
                if (line[qt_end] == c)
                    return (0); 
                qt_end++;
            }
        }
        qt_start++;
    }
    return(1);
}
ft_pipe_check()
{
}

ft_parse(char *line)
{
    //while loop to check for quotes
        //if quote found start ft_qt_check
    //check pipes
}