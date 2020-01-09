//
//  Tree.h
//  14.1.2
//
//  Created by Noah on 2019/11/29.
//  Copyright © 2019 Noah. All rights reserved.
//

#ifndef Tree_H
#define Tree_H
const int Max = 20;


struct TNode
{
    char data;
    TNode * firstchild, * rightsib;
};
//以下是树类Tree的声明
class Tree
{
public:
    Tree();
    ~Tree(){Release(root);}
    void PreOrder(){PreOrder(root);}
    void PostOrder(){PostOrder(root);}
private:
    TNode * root;
    void Release(TNode * bt);
    void PreOrder(TNode * bt);
    void PostOrder(TNode * bt);
};


#endif /* Tree_h */
