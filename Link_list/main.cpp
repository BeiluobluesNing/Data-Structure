//
//  Created by 宁沛荣 on 2017/12/27.
//  Copyright © 2017年 宁沛荣. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.hpp"

struct Node
{
    int Element;
    Position next;
};

List makeEmpty(List L)
{
    return L->next = NULL;
}

int isEmpty(List L)
{
    return(L->next == NULL);
}

int  isLast(List L,Position p)
{
    return(p->next == NULL);
}

Position FindNode(int x ,List L)
{
    Position P;
    P = L->next;
    while (P != NULL && P->Element != x)
    {
        P = P->next;
    }
    return P;
}

Position findPreivious(int x,List L)
{
    Position p;
    p = L->next;
    if (p->next != NULL && p->next->Element != x)
    {
        p = p->next;
    }
    return p;
}

void Delete(int x, List L)
{
    Position p, tempcell;
    p = findPreivious(x, L);
    if(!isLast(L, p))
    {
        tempcell = p->next;
        p->next = tempcell->next;
        free(tempcell);
    }
}

void Insert(int x,List L,Position p)
{
    Position tempcell;
    tempcell = (Node *)malloc(sizeof(struct Node));
    if(tempcell == NULL)
        printf("out of space!");
    tempcell->Element = x;
    tempcell->next = p->next;
    p->next = tempcell;
}
















