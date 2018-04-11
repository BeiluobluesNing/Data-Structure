//
//
//  Created by 宁沛荣 on 2017/12/27.
//  Copyright © 2017年 宁沛荣. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.hpp"
bool isPrime(int num)
{
    if (num == 2 || num == 3)
    {
        return true;
    }
    if (num % 6 != 1 && num % 6 != 5)
    {
        return false;
    }
    for (int i = 5; i*i <= num; i += 6)
    {
        if (num % i == 0 || num % (i+2) == 0)
        {
            return false;
        }
    }
    return true;
}

int NextPrime(int n)
{
    bool state=isPrime(n);
    while(!state)
    {
        state=isPrime(++n);
        
    }
    return n;
}  

HASH_TABLE initialize_table( unsigned int table_size ) {
    HASH_TABLE H;
    int i;
    if(table_size <MIN_TABLE_SIZE)
    {
        return (nullptr);
    }
    
    H = (HASH_TABLE)malloc(sizeof(struct hash_tbl));

    if( H == NULL )
        printf("out of space!!");
    H->table_size =NextPrime(table_size);
    // allocate array of lists
    H->the_lists = (position *) malloc( sizeof (LIST) * H->table_size );
    if( H->the_lists == NULL )
        printf("Out of space!!!");
    // Allocate list header
    for(i=0; i<H->table_size; i++ )
    {
        H->the_lists[i] = (LIST) malloc ( sizeof (struct list_node) );
        if( H->the_lists[i] == NULL )
            printf("Out of space!!!");
        else
            H->the_lists[i]->next = NULL;
    }
        return H;
}
//
position Find(element_type key, HASH_TABLE Table)
{
    position P;
    LIST L = nullptr;
//    L = Table->the_lists[hash(key, Table->table_size)];
    P = L->next;
    if(P->element != key && P !=nullptr)
        P = P->next;
    return P;
}

void Insert(element_type  key,HASH_TABLE Table)
{
    position Pos,newcell = nullptr;
    LIST L = nullptr;
    Pos = Find(key, Table);
    if(Pos == nullptr)
    {
        //要先为newcell分配内存！！！
        newcell = (position)malloc(sizeof(position));
        if(newcell == nullptr)
        {
            printf("out of space!!!");
        }
//        L = Table->the_lists[hash(key, Table->table_size)];
        newcell->next = L->next;
        newcell->element = key;
        L->next = newcell;

    }
}


int main()
{
    int a;
    printf("请输入");
    scanf("%d",&a);
    printf("%d",NextPrime(a));
}
