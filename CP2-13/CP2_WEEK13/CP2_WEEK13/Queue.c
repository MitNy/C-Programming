//
//  Queue.c
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Queue.h"

struct _Queue {
    Node* _front;
    Node* _rear;
    int _size;
};

// Queue 객체의 생성과 소멸
Queue* Queue_new(void){ // Queue 객체의 생성
    Queue* _this;
    _this = NewObject(Queue);
    _this->_front = NULL;
    _this->_rear = NULL;
    _this->_size = 0;
    
    return _this;
}

void Queue_delete(Queue* _this) {   // queue  객체 소멸
    Queue_deleteLinkedChain(_this);
    free(_this);
}

// Queue 객체의 점검
Boolean Queue_isEmpty(Queue* _this){    // 큐가 empty이면 TRUE,아니면 FALSE
    return _this->_front == NULL;
}

Boolean Queue_isFull(Queue* _this){ // 큐가 full 이면 TRUE를, 아니면, FALSE
    return FALSE;
}

int Queue_size(Queue* _this){   // 큐의 길이, 즉 큐가 가지고 있는 원소의 개수
    return _this->_size;
}

// Queue 객체에 지시
Boolean Queue_add(Queue* _this, Element anElement){ // 큐의 rear에 item을 삽입
    Node* addedNode = Node_new();
    Node_setElement(addedNode, anElement);
    
    if( !Queue_isEmpty(_this)) {
        Node_setNext(_this->_rear, addedNode);
        _this->_rear = addedNode;
        _this->_size++;
        
        return TRUE;
    }
    else {
        _this->_front = addedNode;
        _this->_rear = addedNode;
        _this->_size++;
        
        return TRUE;
    }
}

Element Queue_remove(Queue* _this){ // 큐의 front에서 Element를 삭제하고 그 값을 얻는다
    if( _this->_size > 1 ) {
        Node* removedNode = _this->_front;
        Element removedElement = Node_element(_this->_front);
        _this->_front = Node_next(_this->_front);
        
        Node_delete(removedNode);
        _this->_size--;
        
        return removedElement;
    }
    else {
        Element removedElement = Node_element(_this->_front);
        Node_delete(_this->_front);
        
        _this->_front = NULL;
        _this->_rear = NULL;
        _this->_size--;
        
        return removedElement;
    }
}

void Queue_deleteLinkedChain(Queue* _this){ // 큐의 크기만큼 삭제
    int i;
    for( i=1; i < _this->_size; i++ ) {
        Queue_remove(_this);
    }
}

Element Queue_elementAt(Queue* _this, int aPosition){   //큐의 aPosition 번째 원소를 얻는다.
    Node* currentNode = _this->_front;
    int i;
    for( i=0; i < aPosition; i++ ) {
        currentNode = Node_next(currentNode);
    }
    return Node_element(currentNode);
}
