//
//  main.hpp
//  tests
//
//  Created by 宁沛荣 on 2018/3/14.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#ifndef main_h
#define main_h


struct Node;
typedef struct Node *Ptrnode;
typedef Ptrnode List;
typedef Ptrnode Position;

List makeEmpty(List L);
int isEmpty(List L);
int isLast(List L);
Position FindNode(int x ,List L);
Position findPreivious(int x,List L);
void Delete(int x, List L);
void Insert(int x,List L,Position p);


#endif /* main_h */
