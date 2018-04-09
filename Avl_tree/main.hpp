//
//  main.hpp
//  tests
//
//  Created by 宁沛荣 on 2018/3/14.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#ifndef main_h
#define main_h
typedef int ElementType;
struct Avlnode;
typedef struct Avlnode *Position;
typedef struct Avlnode *AvlTree;

struct Avlnode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
    
};


#endif /* main_h */
