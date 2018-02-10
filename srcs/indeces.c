#include "../lemin.h"

int find_target_index(t_graph *graph, char *src)
{
    int targetindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            if (ft_strcmp(graph->name[graph->index], src) == 0)
            {
                targetindex = graph->index;
                // printf("targetindex: %d\tsrc: %s\n", targetindex, src);
                return (targetindex);
            }
         }
        graph->index++;
    }
    return (0);
}

int find_start_index(t_graph *graph, char *src)
{
    int startindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            if (ft_strcmp(graph->name[graph->index], src) == 0)
            {
                startindex = graph->index;
                // printf("startindex: %d\tsrc: %s\n", startindex, src);
                return (startindex);
            }
        }
        graph->index++;
    }
    return (0);
}

int find_src_index(t_graph *graph, char *src)
{
    int srcindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], src)){
            if (ft_strcmp(graph->name[graph->index], src) == 0)
            {
                srcindex = graph->index;
                // printf("srcindex: %d\tsrc: %s\n", srcindex, src);
                return (srcindex);
            }
        }
        graph->index++;
    }
    return (0);
}

int find_dest_index(t_graph *graph, char *dest)
{
    int destindex = -1;
    graph->index = 0;
    while (graph->name[graph->index])
    {
        if (ft_strstr(graph->name[graph->index], dest)){
            if (ft_strcmp(graph->name[graph->index], dest) == 0)
            {
                destindex = graph->index;
                // printf("destindex: %d\tdest:%s\n", destindex, dest);
                return (destindex);
            }
        }
        graph->index++;
    }
    return (0);
}