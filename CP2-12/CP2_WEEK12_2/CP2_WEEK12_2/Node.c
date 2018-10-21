//
//  Node.c
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 31..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Node.h"

Node* Node_new() {
    Node* _this = NewObject(Node);
    return _this;
}

void Node_delete(Node* _this) {
    free(_this);
}

void Node_setElement(Node* _this, Element newElement) {
    _this->_element = newElement;
}

Element Node_element(Node* _this){
    return _this->_element;
}

void Node_setNext(Node* _this, Node* newNext) {
    _this->_next = newNext;
}

Node* Node_next(Node* _this) {
    return _this->_next;
}

