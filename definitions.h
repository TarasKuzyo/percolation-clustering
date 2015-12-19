#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include "clustering.h"

#define SITE_BLOCK 0
#define SITE_OPEN  1
#define SITE_FULL  2


typedef struct
{
    int width;
    int height;
    int *cells;

} grid;


grid* grid_allocate(int width, int height);
void grid_free(grid *grd);

void grid_create(grid *grd, double prob);
cl_list* clusterization(grid *grd);


#endif /* __DEFINITIONS_H__ */
