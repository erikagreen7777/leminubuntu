#include "../lemin.h"

int      check_start_room(t_info *data)
{
    while (data->file[data->start])
    {
        if (data->file[data->start][0] == '#')
            data->start++;
        if ((data->file[data->start][0] != '#') && (data->file[data->start][0] != 'L'))
        {
            data->startstr = room_trim(data->file[data->start]);
           // printf("start str: %s\n", data->startstr);
            return (1);
        }
    }
    return (0);
}

int      check_end_room(t_info *data)
{
    while (data->file[data->end])
    {
        if (data->file[data->end][0] == '#')
            data->end++;
        if ((data->file[data->end][0] != '#') && (data->file[data->end][0] != 'L'))
        {
            data->endstr = room_trim(data->file[data->end]);
           // printf("end str: %s\n", data->endstr);
            return (1);
        }
    }
    return (0);
}

static int  check_room(char *str)
{
    int i;
    int spacecount;
    i = 0;
    spacecount = 1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {   
            spacecount++;
            if ((!ft_isdigit(str[i + 1])) && (str[i + 1] != '-' && !ft_isdigit(str[i + 2])))
                return (1);
            // printf("i: %d\n", i);
        }
        i++;
    }
    if (spacecount != 3){
        // printf("str: %s\ti: %d\n", str, i);
        ft_error("\nspacecount ERROR");
    }
    return (0);
}

static void    check_room_duplicates(t_info *data)
{
    int i;
    i = 0;
    int j;
     while (i < data->roomcount)
    {
        j = i + 1;
        while (j < data->roomcount)
        {
            if (ft_strcmp(data->rooms[i], data->rooms[j]) == 0){
                // printf("data->rooms[i]: %s\n", data->rooms[i]);
                ft_error("\nrooms ERROR");
            }
            else
                j++;
        }
        i++;
    }   
}

char    *room_trim(char *str)
{
    int i = 0;
    char *temp;
    temp = ft_strdup(str);
    ft_strclr(str);
    while (temp[i])
    {
        if (temp[i] == ' ')
        {
            if (check_room(temp) == 1){
                // printf("str: %s\n", str);
                // printf("temp[%d]: %s\n", i, temp);
                ft_error("\nroom trim ERROR");
            }
            else{
                // printf("i: %d\n", i);
                break;
            }
        }
        i++;
    }
    // temp[i] = '\0';
    ft_strncpy(str, temp, i);
    ft_strdel(&temp);
    return (str);
}

void    assign_rooms(t_info *data)
{
    int i;
    i = 1;
    int j = 0;
    data->rooms = (char **)ft_memalloc(sizeof(char *) * data->linecount);
    while (data->file[i]/* && (i >= data->start && i <= data->end)*/)
    {
        if (data->file[i][0] == 'L'){
            // printf("data->file[%d]: %c\n", i, data->file[i][0]);
            ft_error("\nassign rooms ERROR");
        }
        // if (ft_strchr(data->file[i]))
        if ((!ft_strchr(data->file[i], '-') && (data->file[i][0] != '#'))/* && (i < data->pipestart)*/)
        {
            data->rooms[j] = ft_strdup(data->file[i]);
            room_trim(data->rooms[j]);
            // printf("data->rooms[%d]: %s\n", j, data->rooms[j]);
            data->roomcount++;
            j++;
        }
        i++;
    }
    // i = 0;
    // while (data->rooms[i])
    // {
    //     printf("data->rooms[%d]: %s\n", i, data->rooms[i]);
    //     i++;
    // }
    if (data->roomcount == 0)
        ft_error("\nassign rooms 2ERROR");
    check_room_duplicates(data);

    // i = -1;
    // while (++i < data->roomcount)
    //     printf("rooms[%d]: %s\n", i, data->rooms[i]);

}