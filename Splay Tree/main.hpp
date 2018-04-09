
//
//  main.hpp
//  Splay Tree
//
//  Created by 宁沛荣 on 2018/4/9.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#ifndef main_h
#define main_h
typedef int element_type;

typedef struct splay_node *splay_ptr;
struct splay_node
{
    element_type element;
    splay_ptr left;
    splay_ptr right;
    splay_ptr parent;
};
typedef splay_ptr SEARCH_TREE;
#endif /* main_h */
