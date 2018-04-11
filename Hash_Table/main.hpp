//
//  main.hpp
//  tests
//
//  Created by 宁沛荣 on 2018/3/14.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#ifndef main_h
#define main_h
#define MIN_TABLE_SIZE 5
typedef struct list_node *node_ptr;
typedef int element_type;

struct list_node
{
    element_type element;
    node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

struct hash_tbl
{
    unsigned int table_size;
    LIST *the_lists;
};
typedef struct hash_tbl *HASH_TABLE;

element_type hash(element_type key, int table_size);

#endif /* main_h */
