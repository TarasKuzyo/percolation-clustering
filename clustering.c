#include <stdlib.h>

/* ------------------------------------------------------- */

int_list *int_list_create_node(int item)
{
    int_list *node = malloc(sizeof(int_list));
    if (node != NULL)
    {
        node->item = item;
        node->next = NULL;
    }
    
    return node;
}


int int_list_push_node(int_list **d, int_list *node)
{
    if (node == NULL)
        return 0;
    
    node->next = *d;
    *d = node; 

    return 1;
} 


int int_list_push_item(int_list **d, int item)
{
    int_list *node = int_list_create_node(item);
    return int_list_push_node(d, node);
}


void int_list_free(int_list *d)
{
    int_list *dd, *current = d;

    while (current != NULL)
    {
        dd = current;   /* node for deletion */
        current = current->next;
        free(dd);
    } 
}


/* ------------------------------------------------------- */


int cluster_push(cluster *cl1, int_list *node)
{
    int_list *head = cl1->head;
    int res = int_list_push_node(&(cl1->head), node);
    if (res)
    {    
        /* initilize a pointer to the tail node */
        if (head == NULL)
            cl->tail = cl->head;
        
        cl1->size += 1;
        cl1->upper_boundary |= ..;
        cl1->lower_boundary |= ..;
    }
    return res;
}


/* append nodes from cl2 to the end of cl1 */
int cluster_join(cluster **cl1, cluster *cl2)
{
    if (*cl1 == NULL)
        *cl1 = cl2;
    else
    {
        *cl1->tail->next = cl2->head;
        *cl1->size += cl2->size;
        *cl1->upper_boundary |= cl2->upper_boundary;
        *cl1->lower_boundary |= cl2->lower_boundary;
    }
    /* cl2 is no more responsible for its nodes */
    cl2->head = NULL;
    cl2->tail = NULL;    
}


/* ------------------------------------------------------- */

cl_list* cl_list_create_node(cluster item)
{
    cl_list *node = malloc(sizeof(cl_list));
    if (node != NULL)
    {
        node->item = item;
        node->next = NULL;
    }
    
    return node;
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
    cl_list *node = cl_list_create_node(cl);
    return cl_list_push_node(d, node);
}



int cl_list_remove_node(cl_list **d, cl_list *node)
{
    if (node == NULL)
        return 0;

    if (node == *d) /* removing a head node */
    {
        *d = node->next;
        if (*d != NULL) /* otherwise list is empty */
            *d->prev = NULL;
    }
    else
    {
        node->prev->next = node->next;
        if (node->next != NULL) /* otherwise tail node removed */
            node->next->prev = node->prev;
    }
    
    free(node);
    return 1;
}


void cl_list_free(cl_list *d)
{
    cl_list *dd, *current = d;

    while (current != NULL)
    {
        dd = current;
        current = current->next;
        free(dd);
    } 
}


