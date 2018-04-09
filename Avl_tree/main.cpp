//
//  dijkstra.cpp
//  algorithm_poj
//
//  Created by 宁沛荣 on 2017/12/27.
//  Copyright © 2017年 宁沛荣. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.hpp"

static int Height(Position P)
{
    if (P == NULL) {
        return -1;
    }
    else
        return P->Height;
}
template <class T>
T Max (T a, T b)
{
    
    T result;
    
    result = (a>b)? a : b;
    
    return (result);
    
}

static Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;      //借用一个节点
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max(Height(K2->Right), Height(K2->Left))+1;
    K1->Height = Max(Height(K1->Right), Height(K1->Left))+1;
    return K1;
}

static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithLeft(K3->Left);
    return SingleRotateWithLeft(K3);
}

AvlTree Insert(AvlTree T,ElementType X)
{
    if(T == NULL)
    {
        T = (Avlnode *)malloc(sizeof(struct Avlnode));
        if(T == NULL)
        {
            printf("WTF OUT OF SPACE???");
        }
        else
        {
            T->Element =X;
            T->Left = T->Right = NULL;
        }
    }
    else
        if (X < T->Element)
        {
            Insert(T->Left,X);
        }
        if(Height(T->Left) - Height(T->Right) == 2)
        {
            if(X < T->Left->Element)
                SingleRotateWithLeft(T);
            else
                DoubleRotateWithLeft(T);
        }
    else
        if (X > T->Element)
        {
            Insert(T->Right,X);
        }
    if(Height(T->Right) - Height(T->Left) == 2)
    {
        if(X > T->Right->Element)
            SingleRotateWithLeft(T);
        else
            DoubleRotateWithLeft(T);
    }
    T->Height =Max(Height(T->Right), Height(T->Left))+1;
    return T;
}








