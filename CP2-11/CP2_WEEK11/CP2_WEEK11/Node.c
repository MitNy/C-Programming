//
//  Node.c
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Node.h"


Node* Node_new() {  // 노드 객체 생성
    Node* _this = NewObject(Node);
    _this->_element = 0;
    _this->_next = NULL;
    return _this;
}

void Node_delete(Node* _this){  // 노드 객체 소멸
    free(_this);
}
