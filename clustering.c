#include <stdlib.h>


typedef struct __int_list
{
    int item;
    struct __int_list next;

} int_list;


void list_free(list *d)
{
    list *dd, *current = d;

    while (current != NULL)
    {
        dd = current;
        current = current->next;
        free(dd);
    } 
}


int list_push(list **d, list *node)
{
    if (node == NULL)
        return 0;
    
    node->next = *d;
    *d = node; 

    return 1;
} 


list *create_node(void item)
{
    list *node = malloc(sizeof(list));
    if (node != NULL)
    {
        node->item = item;
        node->next = NULL;
    }
    
    return node;
}


int cluster_push(cluster *cl, cluster *node)
{
    if (node == NULL)
        return 0;
        
    node->next = cl->first;
    cl->first = node;
    
    cl->size += 1;
    cl->upper_boundary |= node->upper_boundary;
    cl->lower_boundary |= node->lower_boundary;
    return 1;
}

int cluster_join(cluster *cl1, cluster *cl2)
{
    cl1->last->next = cl2->first;
    cl1->size += cl2->size;
    cl1->upper_boundary |= cl2->upper_boundary;
    cl1->lower_boundary |= cl2->lower_boundary;
}




int cl_list_push_node(cl_list **d, cl_list *node)
{
    if (*d != NULL)
        *d->prev = node;
        
    node->prev = NULL;
    node->item = cl;
    node->next = *d;

    *d = node;
    return 1;
}


int cl_list_push_item(cl_list **d, cluster cl)
{
    cl_list *node = malloc(sizeof(cl_list));
    return cl_list_push_node(d, node);
}



int cl_list_remove_node(cl_list **d, cl_list *node)
{
    if (node == NULL)
        return 0;

    if (node == *d)
    {
        *d = node->next;
        if (*d != NULL)
        {
            *d->prev = NULL;
        }
    }
    else
    {
        node->prev->next = node->next;
        if (node->next != NULL)
        {
            node->next->prev = node->prev;
        }
    }
    
    free(node);
    return 1;
}


