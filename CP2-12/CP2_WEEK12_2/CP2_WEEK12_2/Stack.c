//
//  Stack.c
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Stack.h"

struct _Stack {
    int _size;
    Node* _top;
};

void Stack_deleteLinkedNodes(Stack* _this);

Stack* Stack_new() {    // stack 객체 생성
    Stack* _this;
    _this = NewObject(Stack);
    _this->_top = NULL;
    _this->_size = 0;
    
    return _this;
}

void Stack_delete(Stack* _this){    // stack 객체 소멸
    Stack_deleteLinkedNodes(_this);
    free(_this);
}

void Stack_reset(Stack* _this) {    // 스택 초기화
    Stack_deleteLinkedNodes(_this);
    _this->_size = 0;
}

Boolean Stack_isEmpty(Stack* _this){    // 스택이 empty 이면 TRUE를, 아니면, FALSE를 얻는다.
    return ((_this->_size) == 0 );
}
Boolean Stack_isFull(Stack* _this){ // 스택이 full 이면 TRUE 를, 아니면, FALSE 를 얻는다.
    return FALSE;
}

int Stack_size(Stack* _this) {  // 스택의 크기 리턴
    return _this->_size;
}

Element Stack_push(Stack* _this, Element anElement){    // 스택에 anElement 를 삽입
    Node* addedNode = Node_new();
    
    if( Stack_isFull(_this)) {
        return FALSE;
    }
    Node_setElement(addedNode,anElement);
    Node_setNext(addedNode,_this->_top);
    _this->_top = addedNode;
    _this->_size++;
    
    return TRUE;
}

Element Stack_pop(Stack* _this){    // 스택의 top에서 원소를 삭제하고 그 값을 얻는다.
    Element removedElement;
    Node* removedNode = _this->_top;
    
    if( Stack_isEmpty(_this)) {

    }
    removedElement = Node_element(removedNode);
    _this->_top = Node_next(removedNode);
    Node_delete(removedNode);
    _this->_size--;
    
    return removedElement;
}

Element Stack_peekElement(Stack* _this) {   // top에 있는 원소를 리턴
    return Node_element(_this->_top);
}

Element Stack_elementAt(Stack* _this, int aPosition) {   //스택 리스트의 aPosition 번째 원소를 얻는다.
    Element top;
    Node* positionNode = _this->_top;
    
    for( int Position=0; Position < aPosition; Position++ ) {
        positionNode = Node_next(positionNode);
    }
    
    top = Node_element(positionNode);
    
    return top;
}

void Stack_deleteLinkedNodes(Stack* _this) {
    Node* currentNode = _this->_top;
    Node* nodeToBeDeleted = NULL;
    
    while( currentNode != NULL ) {
        nodeToBeDeleted = currentNode;
        currentNode = Node_next(currentNode);
        Node_delete(nodeToBeDeleted);
    }
}

Node* Stack_top(Stack* _this) { // top 리턴
    return _this->_top;
}
