//
//  main.cpp
//  Splay Tree
//
//  Created by 宁沛荣 on 2018/4/9.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#include <iostream>
#include "main.hpp"

void zig_left(splay_ptr x )
{
    splay_ptr p, B;
    p = x->parent;
    B = x->right;
    x->right = p; /* x's new right child is p*/
    x->parent = NULL;
    /* x will now be a root */
    if( B != NULL )
        B->parent = p;
    p->left = B;
    p->parent = x;
}

void zig_right(splay_ptr x )
{
    splay_ptr p, B;
    p = x->parent;
    B = x->left;
    x->left = p; /* x's new right child is p*/
    x->parent = NULL;
    /* x will now be a root */
    if( B != NULL )
        B->parent = p;
    p->right = B;
    p->parent = x;
}
void single_rotate(splay_ptr x )
{
    if( x->parent->left == x)
        zig_left( x );
    else
        zig_right(x);
}


void splay(splay_ptr current )
{
    splay_ptr father;
    father = current->parent;
    while( father != NULL )
    {
        if( father->parent == NULL )
            single_rotate (current );
//        else
//            double_rotate( current );
        father = current->parent;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
