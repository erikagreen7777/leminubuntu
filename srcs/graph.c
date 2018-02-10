#include "../lemin.h"

t_node *createNode(int v)
{
    t_node *newNode = malloc(sizeof(t_node));
    newNode->index = v;
    newNode->name = NULL;
    newNode->next = NULL;
    return (newNode);
}


void addEdgeString(t_graph *graph, char *src, char *dest)
{
    int srcindex;
    int destindex;
    srcindex = find_src_index(graph, src);
    destindex = find_dest_index(graph, dest); 

    t_node *newNode = createNode(destindex);
    // printf("dest: %s\t\t", dest);
    newNode->name = dest;
    // printf("newNode->name: %s\n", newNode->name);
    newNode->next = graph->adjLists[srcindex];
    graph->adjLists[srcindex] = newNode; 
    
    newNode = createNode(srcindex);
    newNode->next = graph->adjLists[destindex];
    newNode->name = src;
    // printf("newNode->name: %s\n", newNode->name);
    graph->adjLists[destindex] = newNode; 
}


void printGraph(t_graph *graph, t_info *data)
{
    data->printgraph = 1;
    int i = 0;
    // while (i < data->roomcount && (data->solution[i] != NULL))
    // {
    //     ft_printf("data->solution[%d]: %s\n", i, data->solution[i]);
    //     i++;
    // }
    printf("graph->name: %s\n", graph->name[0]);
    int j = 1;
    while (j < data->roomcount && data->solution[j] != NULL)
    {     
        i = 1;
        while (i < data->ants + 1)
        {
            ft_printf("L%d-%s\n", i, data->solution[j]);
            i++;
        }
        j++;
    }
}

int DFS(t_graph *graph, t_info *data, int index)
{
    int targetindex;
    targetindex = find_target_index(graph, data->endstr);

    t_node *adjList = graph->adjLists[index];
    t_node *temp = adjList;
   
    graph->visited[index] = 1;

    data->solution[data->curr] = /*ft_strdup(*/graph->name[index]/*)*/;
    data->curr++;
    while(temp != NULL) 
    {
        printf("graph->name[graph->visited[index]: %s[%d]\n", graph->name[index], graph->visited[index]);
        int connectedVertex = temp->index;
        if (connectedVertex == targetindex)
        {

            data->solution[data->curr] = /*ft_strdup(*/data->endstr/*)*/;
            printGraph(graph, data);
            // printf("printgraph: %d\n", data->printgraph); 
             // while (1){

             // }
		   	exit(0);
        }
        else if (graph->visited[connectedVertex] == 0){
            // free(data->solution[data->curr]);
            DFS(graph, data, connectedVertex);
        }
        temp = temp->next;
    }
    // printf("printgraph: %d\n", data->printgraph); 
    // if (graph->visited[targetindex] == 0)
    //     ft_error("no solution ERROR");
    return(1);  
}

//loop1
//map14

