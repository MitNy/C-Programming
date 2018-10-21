//
//  Node.h
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
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

Node* Node_new();   // 노드 객체 생성
void Node_delete(Node* _this);  // 노드 객체 소멸

#endif /* Node_h */
