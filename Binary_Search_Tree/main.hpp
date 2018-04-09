
//
//  main.hpp
//  Tree
//
//  Created by 宁沛荣 on 2018/3/27.
//  Copyright © 2018年 宁沛荣. All rights reserved.
//

#ifndef main_h
#define main_h
typedef  int ElementType;
struct Treenode;
typedef struct  Treenode *Position;
typedef struct  Treenode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position FindMin(SearchTree T);
Position Find(ElementType X,SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
Position FindMax(SearchTree T);


#endif /* main_h */
