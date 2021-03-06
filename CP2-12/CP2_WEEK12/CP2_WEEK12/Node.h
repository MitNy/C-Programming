//
//  Node.h
//  CP2_WEEK12
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "Common.h"
#include "Stack.h"

typedef struct _Node Node;
struct _Node {
    Element _element;
    Node* _next;
};

Node* Node_new();   // 노드 객체 생성
void Node_delete(); // 노드 객체 소멸
void Node_setElement(Node* _this, Element newElement);  // 노드 element의 설정자
Element Node_element(Node* _this);  // 노드의 원소 리턴
void Node_setNext(Node* _this, Node* newNext);  // 노드 next의 설정자
Node* Node_next(Node* _this);   // 노드의  next 리턴


#endif /* Node_h */
