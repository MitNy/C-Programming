//
//  Node.h
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 31..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "Common.h"

typedef struct _Node Node;

struct _Node {
    Element _element;
    Node* _next;
};

Node* Node_new();
void Node_delete();
void Node_setElement(Node* _this, Element newElement);
Element Node_element(Node* _this);
void Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);


#endif /* Node_h */
