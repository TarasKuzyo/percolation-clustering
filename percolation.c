#include <stdlib.h>
#include "definitions.h"
#include "clustering.h"


grid grid_allocate(int width, int height)
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
inline double random()
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
             grd->cells[grd->width * i + j] = (random() < prob) ? SITE_OPEN : SITE_BLOCK;
    
}


/* fills upper layer cells that are open 
 */
void start_flow(grid *grd)
{
    int j;
    
    for (j = 0; j < grd->width; j++)
        if (gd->cells[j] == SITE_OPEN)
            gd->cells[j] = SITE_FULL;

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
    int i = c1 / grid->width;
    int j = c1 % grid->width;
    
    if (i > 0 && (i - 1)*grid->width + j == c2)
        return 1;
        
    if (j > 0 && i*grid->width + (j - 1) == c2)
        return 1;

    if (i + 1 < grd->height && (i + 1)*grid->width + j == c2)
        return 1;
    
    if (j + 1 < grd->width  && i*grid->width + (j - 1) == c2)
        return 1;
    
    return 0;
}


cl_list* find_neighbors(cl_list *clusters, grid *grd, int k)
{
    cl_list *current = clusters;
    cl_list *neighboring = NULL; 
    int_list  *list_head = NULL;
    
    while (current != NULL)
    {
        list_head = current->item->head;
        while (list_head != NULL)
        {
            if (check_neighborhood(grd, k, list_head->item))
            {
                cl_list_push_item(neighboring, current);
                break;
            }
            list_head = list_head->next;
        }
        
        current = current->next;
    }
    
    return neighboring;
}


cl_list* clusterization(grid *grd)
{
    int_list *cell;
    cluster *parent;
    cl_list *clusters = NULL, *neighboring = NULL; 
    
    int k, have_open = 1;
    
    for (k = 0; k < grd->width * grd->height; k++)
    {
        if (grd->cells[k] == SITE_OPEN)
        {
            cell = int_list_create_node(k);
            parent = cluster_create(cell, k < grd->width, k >= (gd->height - 1) * gd->width);
            
            // get list of clusters that contain grd->cells[k]
            neighboring = find_neighbors(clusters, grd, k);
            // if lst == NULL clusters add parent
            if (neighboring == NULL)
            {
                cl_list_push_item(clusters, parent);
            }
            // else parent join each item in lst
            else 
            {
                cluster_join(&(neighboring->item), parent);
                free(parent);
                
                // remove each item in lst
                current = neighboring->next;
                while (current != NULL)
                {
                    cluster_join(&(neighboring->item), current->item);
                    free(current->item);
                    current = current->next;
                }
            }
            
            grd->cells[k] == SITE_FULL;
        }
    
    }


    return clusters;
}


