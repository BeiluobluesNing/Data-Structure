//
//  main.cpp
//  Tree
//
//  Created by 宁沛荣 on 2018/3/27.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#include "main.hpp"
#include <iostream>


struct Treenode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T ->Left);
        MakeEmpty(T ->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X,SearchTree T)
{
    if (T ==NULL)
    {
        return NULL;
    }
    if (X < T -> Element) {
        return Find(X,T->Left);
    }
    if (X > T -> Element) {
        return Find(X, T->Right);
    }
    else
    {
        return T;
    }
}

Position FindMin(SearchTree T)
{
    if (T ==NULL)
    {
        return NULL;
    }
    if(T->Left == NULL)
    {
        return T;
    }
    else return (FindMin(T->Left));
}

Position FindMax(SearchTree T)
{
    if (T ==NULL)
    {
        return NULL;
    }
    while (T->Right != NULL)
    {
        T = T->Right;
    }
    return T;
}

SearchTree Insert(ElementType X , SearchTree T)
{
    if(T == NULL)
    {
        T = (Treenode *)malloc(sizeof(struct Treenode));
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
    else if(X < T->Element)
    {
        T->Left = Insert(X, T->Left);
    }
    else if (X > T->Element)
    {
        T->Right =Insert(X, T->Right);
    }
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position tempCell;
    if(T == NULL)
    {
        printf("Element not found!");
    }
    else if(X < T->Element)
    {
        T->Left = Delete(X , T->Left);
    }
    else if (X > T->Element)
    {
        T->Right =Delete(X, T->Right);
    }
    else if(T->Left && T->Right)        //Two Children
    {
        tempCell = FindMin(T->Right);
        T->Element = tempCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else
    {
        tempCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(tempCell);
    }
    return T;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
