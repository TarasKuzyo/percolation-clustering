#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "definitions.h"


int main(int argc, char **argv)
{
    srand(time(NULL));
    clock_t beg, end;

    grid *grd = grid_allocate(10, 10);

    
    beg = clock();
    cl_list* clusters = clusterization(grd);
    end = clock();
    
    grid_free(grd);
    
    printf("Finished in %g sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
    
    return 0;
}
