#ifndef __CLUSTERING_H__
#define __CLUSTERING_H__


typedef struct __int_list
{
    int item;
    struct __int_list *next;

} int_list;


typedef struct
{
    int_list *head;
    int_list *tail;
    int size;
    int upper_boundary;
    int lower_boundary;
} cluster;


typedef struct __cl_list
{
    cluster *item;
    struct __cl_list *prev;
    struct __cl_list *next;

} cl_list;


/* ------------------------------------------------------- */

int_list *int_list_create_node(int item);
int       int_list_push_node(int_list **d, int_list *node);
int       int_list_push_item(int_list **d, int item);
void      int_list_free(int_list *current);

/* ------------------------------------------------------- */

cluster* cluster_create(int_list *node, int upper, int lower);
int      cluster_join(cluster **cl1, cluster *cl2);
void     cluster_free(cluster *cl);

/* ------------------------------------------------------- */

cl_list* cl_list_create_node(cluster *item);
int      cl_list_push_node(cl_list **d, cl_list *node);
int      cl_list_push_item(cl_list **d, cluster *cl);
int      cl_list_length(cl_list *current);
int      cl_list_remove_node(cl_list **d, cl_list *node);
void     cl_list_free(cl_list *current);
void     cl_list_print(cl_list *current);
void     cl_list_sort(cl_list **d);



#endif /* __CLUSTERING_H__ */


