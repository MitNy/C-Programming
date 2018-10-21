//
//  Queue.c
//  CP2_WEEK13_2
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Queue.h"
#include "Common.h"

void Queue_deleteLinkedChain(Queue* _this);

struct _Queue {
    int _capacity;  // 배열로 리스트를 구현할 때 반드시 필요한 속성
    int _front;
    int _rear;
    Element* _elements;
};

// Queue 객체의 생성과 소멸
Queue* Queue_new(int givenCapacity){    // Queue 객체의 생성
    Queue* _this;
    _this = NewObject(Queue);
    _this->_capacity = givenCapacity;
    _this->_elements = NewVector(Element, givenCapacity);
    _this->_front = 0;
    _this->_rear = 0;
    
    return _this;
}

void Queue_delete(Queue* _this) {   // Queue 객체의 소멸
    free(_this->_elements);
    free(_this);
}

// Queue 객체의 점검
Boolean Queue_isEmpty(Queue* _this){    // 큐가 empty이면 TRUE,아니면 FALSE
    return (_this->_front == _this->_rear);
}

Boolean Queue_isFull(Queue* _this){ // 큐가 full 이면 TRUE를, 아니면, FALSE
    int nextRear = (_this->_rear+1) % _this->_capacity;
    return ( nextRear == _this->_front );
}

int Queue_size(Queue* _this){   // 큐의 길이, 즉 큐가 가지고 있는 원소의 개수
    int size = 0;
    if( _this->_front < _this->_rear ){
        size = _this->_rear - _this->_front;
    }
    else if( _this->_front > _this->_rear ) {
        size = _this->_capacity - (( _this->_front - _this->_rear)-1);
    }
    else {
        size = 0;
    }
    return size;
}

// Queue 객체에 지시
Boolean Queue_add(Queue* _this, Element anElement){ // 큐의 rear에 item을 삽입
    if( Queue_isFull(_this)) {
        return FALSE;   // Queue Full 처리
    }
    else {
        _this->_rear = (_this->_rear+1) % _this->_capacity;
        _this->_elements[_this->_rear] = anElement;
        
        return TRUE;
    }
}

Element Queue_remove(Queue* _this){ // 큐의 front에서 Element를 삭제하고 그 값을 얻는다
    Element removedElement;
    if( Queue_isEmpty(_this)) {
        return '\0';
    }
    else {
        _this->_front = (_this->_front+1) % _this->_capacity;
        removedElement = _this->_elements[_this->_front];
        return removedElement;
    }
}

Element Queue_elementAt(Queue* _this, int aPosition){   //큐의 aPosition 번째 원소를 얻는다.
    if( aPosition >= _this->_capacity ) {
        return '\0';
    }
    else {
        return _this->_elements[_this->_front+aPosition+1];
    }
}
