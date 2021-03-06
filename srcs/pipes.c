#include "../lemin.h"

static int     ft_isalnumunderscore(int c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58) || c == '_')
        return (1);
    return (0);
}

static int  is_pipe(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '-')
            break;
        i++;
    }
    if (!ft_isalnumunderscore(str[i - 1]) || (!ft_isalnumunderscore(str[i + 1])))
        return (1);
    return (0);
}

void    assign_pipes(t_info *data)
{
    int i = data->pipestart;
    int j = 0;
    // printf("data->pipestart: %d\n", data->pipestart);
    while (data->file[i])
    {
        if (!(ft_strchr(data->file[i], '-')) && (data->file[i][0] != '#')){
            // printf("data->file[%d]: %s\n", i, data->file[i]);
            ft_error("\nnot a pipe ERROR");
        }
        if (ft_strchr(data->file[i], '-'))
        {
            if ((is_pipe(data->file[i]) == 1)){
                // printf("data->file[%d]: %s\t", i, data->file[i]);
                ft_error("\nis_pipe ERROR");
            }
            if (((i < data->start || i < data->end)) || (i == data->start || i == data->end))
                ft_error("\nassign pipes ERROR");
            else/* if (data->file[i][0] != '#')*/{
                data->pipes[j] = ft_strdup(data->file[i]);
                // printf("data->pipes[%d]: %s\n", j, data->pipes[j]);
            }
            j++;
        }
        i++;
    }
    data->pipes[j] = NULL;
    // check_pipe_duplicates(data);

}

void    parse_pipes(t_info *data, t_graph *graph)
{
	int i;
	i = 0;

    // data->vertex = (char **)ft_memalloc(sizeof(char *) * 2);
	while (data->pipes[i])
	{	
        data->vertex = ft_strsplit(data->pipes[i], '-');
        // printf("i: %d\tdata->vertex[0]: %s\t\t\tdata->vertex[1]: %s\n", i, data->vertex[0], data->vertex[1]);
        addEdgeString(graph, data->vertex[0], data->vertex[1]);
        ft_strdel(&data->vertex[0]);
        ft_strdel(&data->vertex[1]);   
        free(data->vertex);
        i++;  
	}
    
}
