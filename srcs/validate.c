#include "../lemin.h"

void    find_start(t_info *data)
{
    int i;
    i = 0;
    while (data->file[i])
    {
        if (ft_strstr("##start", data->file[i])){
            if (data->file[i + 1][0] == '#'){
                 // printf("data->file[i + 1]: %s\n", data->file[i + 1]);
                 ft_error("\ninvalid start room ERROR");
            }
            data->start = i;
            data->startcount++;
            // printf("startcount: %d\n", data->startcount);
            // break;
        }
        i++;
    }
    if (data->start == -1 || data->startcount > 1)
        ft_error("\nfind_startERROR");
    if (check_start_room(data)){
        ;
    }
    else
        ft_error("\nfind start 2ERROR");
}

void    find_end(t_info *data)
{
    int i;
    i = 0;

    while (data->file[i])
    {
        if (ft_strstr("##end", data->file[i])){
            data->end = i;
            break;
        }
        i++;
    }
    if (data->end == -1)
        ft_error("\ninfd_end ERROR");
    if (check_end_room(data)){
        ;
    }
    if (ft_strcmp(data->startstr, data->endstr) == 0)
        ft_error("\nfind end 2ERROR");
}

static void commentsafterpipes(t_info *data)
{
    int i;
    i = data->linecount - 1;
    int comment = 0;
    int commentcount = 0;
    int pipe = 0;
    // printf("i: %d\n", i);
    while (data->file[i])
    {
        if (data->file[i][0] == '#')
        {
            comment = i;
            commentcount++;
            // printf("comment: %d\tcommentcount: %d\n", comment, commentcount);
        }
        else if (ft_strchr(data->file[i], '-'))
        {
            pipe = i;
            // printf("pipe: %d\n", pipe);
            break;
        }
        i--;
    }
    if (comment > pipe)
        data->linecount -= commentcount;
}

void    find_pipes(t_info *data) 
{
    int i;
    i = 0;
    int commentcount = 0;

    while (data->file[i])
    {
        if ((ft_strchr(data->file[i], '-')) && (i < data->end))
            ft_error("\npipes in rooms ERROR");
        if ((ft_strchr(data->file[i], '-') || data->file[i][0] == '#') && i > data->end){
            if (data->file[i][0] != '#'){
                  data->pipestart = i;
                  break;
            }             
        }
        i++;
    }
    i = data->pipestart;
    while (data->file[i])
    {
        if ((ft_strchr(data->file[i], '-') || data->file[i][0] == '#') && i > data->end){
            if (data->file[i][0] == '#'){
                commentcount++;
            }
            data->pipecount++;
        }
        i++;
    }
    if (data->pipecount == 0)
        ft_error("\nfind pipesERROR");
    data->pipecount -= commentcount;
    commentsafterpipes(data);
    data->pipes = (char **)ft_memalloc(sizeof(data->pipes) * data->pipecount + 1);
    assign_pipes(data);
}

void    validate(t_info *data)
{

    find_start(data);
    find_end(data);
    // printf("before data->start: %d\nbefore data->end: %d\nbefore data->swap: %d\n", data->start, data->end, data->swap);
    if (data->start > data->end)
    {
        ft_swap(&data->end, &data->start);
        data->swap = 1;
    }
    // printf("after data->start: %d\nafter data->end: %d\nafter data->swap: %d\n", data->start, data->end, data->swap);
    find_pipes(data);
    assign_rooms(data);
}




