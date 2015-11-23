# percolation-clustering
2D site percolation clustering

#### Pseudo-code

- create a grid (percolation.c:grid_create)
- start a flow  (percolation.c:start_flow)
- perform clusterization:
-- for all cells that are open
-- create a cluster list (parent) containing a single node with 
   the value of current cell's index
-- get a list of all clusters that are neighboring 
   with current cell
-- if there are no neighboring clusters add parent to the list of clusters
-- if there is one neighbor add parent cluster to it
-- otherwise join all neighbors with parent cluster


## Notes

```
grd->cells[i][j] = grd->cells[grd->width * i + j]
```
