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



#endif /* __CLUSTERING_H__ */


