#include <stdlib.h>
#include "definitions.h"
#include "clustering.h"


grid* grid_allocate(int width, int height)
{
    int *cells = malloc(width * height * sizeof(int));
    if (cells == NULL)
        return NULL;
    
    grid *grd = malloc(sizeof(grid));
    if (grd == NULL)
    {
        free(cells);
        return NULL;
    }
    
    grd->width  = width;
    grd->height = height;
    grd->cells  = cells;

    return grd;
}


void grid_free(grid *grd)
{
    free(grd->cells);
    free(grd);
}


/* returns a random number in range 0..1 */
inline double rand_num()
{
    return (double)rand() / (double)RAND_MAX;
}


/* generates a ramdom grid for given 
   site vacancy probability */
void grid_create(grid *grd, double prob)
{
    int i, j;
    
    for (i = 0; i < grd->height; i++)
        for (j = 0; j < grd->width; j++)
             grd->cells[grd->width * i + j] = (rand_num() < prob) ? SITE_OPEN : SITE_BLOCK;
    
}



/* checks if the grid structure percolates
   i.e., if any bottom layer cell is full 
 */
int percolates(grid *gd)
{
    int j;
    
    /* check if at least one of bottom cells is full */
    for (j = 0; j < gd->width; j++)
        if (gd->cells[(gd->height - 1) * gd->width + j] == SITE_FULL)
            return 1;
    
    return 0;
}


/* returns 1 if c1-th and c2-th cells are neighboring
   in the grd structure
 */
int check_neighborhood(grid *grd, int c1, int c2)
{
    int i1 = c1 / grd->width;
    int j1 = c1 % grd->width;
    
    int i2 = c2 / grd->width;
    int j2 = c2 % grd->width;
    
    if (i1 == i2 && (j1 == j2 + 1 || j1 == j2 - 1))
        return 1;
    if (j1 == j2 && (i1 == i2 + 1 || i1 == i2 - 1))
        return 1;
    
    return 0;
}


cl_list* find_neighbors(cl_list **clusters, grid *grd, int k)
{
    cl_list *current = *clusters;
    cl_list *neighboring = NULL, *next = NULL; 
    int_list  *list_head = NULL;
    int found;
    
    while (current != NULL)
    {
        found = 0;
        list_head = current->item->head;
        while (list_head != NULL && !found)
        {
            if (check_neighborhood(grd, k, list_head->item))
            {
                found = 1;
                // following lines affect current list
                // so save next poiter 
                next = current->next;
                cl_list_remove_node(clusters, current);
                cl_list_push_node(&neighboring, current);
                current = next;
            }
            list_head = list_head->next;
        }
        
        if (!found)
            current = current->next;
        // else current is already modified
    }
    
    return neighboring;
}


cl_list* clusterization(grid *grd)
{
    int_list *cell = NULL;
    cluster *parent = NULL;
    cl_list *current = NULL;
    cl_list *clusters = NULL;
    
    int k;
    
    for (k = 0; k < grd->width * grd->height; k++)
    {
        if (grd->cells[k] == SITE_OPEN)
        {
            cell = int_list_create_node(k);
            parent = cluster_create(cell, k < grd->width, k >= (grd->height - 1) * grd->width);
            
            // get list of clusters that contain grd->cells[k]
            current = find_neighbors(&clusters, grd, k);
            while (current != NULL)
            {
                cluster_join(&parent, &(current->item));
                free(current->item);
                current = current->next;
            }
            
            cl_list_push_item(&clusters, parent);
            grd->cells[k] = SITE_FULL;
            
        }
    }
    

    return clusters;
}




