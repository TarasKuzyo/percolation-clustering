#include <stdlib.h>
#include "definitions.h"


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



