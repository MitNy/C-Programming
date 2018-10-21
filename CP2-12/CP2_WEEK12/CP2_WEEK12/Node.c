//
//  Node.c
//  CP2_WEEK12
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Node.h"

Node* Node_new() {  // 노드 객체 생성
    Node* _this = NewObject(Node);
    _this->_element = 0;
    _this->_next = NULL;
    
    return _this;
}

void Node_delete(Node* _this) { // 노드 객체 소멸
    free(_this);
}

void Node_setElement(Node* _this, Element newElement) {  // 노드 element의 설정자
    _this->_element = newElement;
}

Element Node_element(Node* _this){  // 노드의 원소 리턴
    return _this->_element;
}

void Node_setNext(Node* _this, Node* newNext) {  // 노드 next의 설정자
    _this->_next = newNext;
}

Node* Node_next(Node* _this) {  // 노드의 next 리턴
    return _this->_next;
}
