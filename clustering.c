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
    
    if (*d == NULL)
    {
        *d = node;
        return 1;
    }

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


