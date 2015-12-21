#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "definitions.h"


int main(int argc, char **argv)
{
    srand(time(NULL));
    clock_t beg, end;

    int size = 50;
    grid *grd = grid_allocate(size, size);

    beg = clock();
    grid_create(grd, 0.6);
    cl_list* clusters = clusterization(grd);
    end = clock();
    
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%d", grd->cells[i * size + j]);
        printf("\n");
    }
    cl_list_print(clusters);
    
    create_image("img.png", 2000, grd, clusters);
    
    grid_free(grd);
    
    printf("Finished in %g sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
    
    return 0;
}
