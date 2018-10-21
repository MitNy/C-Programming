//
//  Stack.c
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Stack.h"
#include "Common.h"
#define MAX_STACK_SIZE 5

struct _Stack {
    int _maxSize;
    int _top;
    Element* _elements; // 배열을 동적으로 할당
};

Stack* Stack_new(int givenMaxSize) {    // 스택 객체 생성
    Stack* _this;
    _this = NewObject(Stack);
    _this->_maxSize = givenMaxSize;
    _this->_elements = NewVector(Element, MAX_STACK_SIZE);
    _this->_top = -1;
    
    return _this;
}

void Stack_delete(Stack* _this) {    // 스택에 있는 원소와 스택 소멸
    free(_this->_elements);
    free(_this);
}

void Stack_reset(Stack* _this) {    // 스택 초기화
    _this->_top =-1;
}

void Stack_push(Stack* _this, Element anElement) {  // 스택에 원소를 넣음
    if(!Stack_isFull(_this)){
        _this->_top++;
        _this->_elements[_this->_top] = anElement;
    }
    // stack 이 empty이면 push를 무시
}

Boolean Stack_isEmpty(Stack* _this) {   // 스택이 비었는지 검사
    return ((_this->_top) < 0 );
}
Boolean Stack_isFull(Stack* _this) {    // 스택이 꽉 찼는지 검사
    return ( (_this->_top) == (MAX_STACK_SIZE-1) ) ;
}

Element Stack_pop(Stack* _this) {   // 스택에서 원소를 꺼내고 삭제
    // stack은 empty가 아니라고 가정
    Element poppedElement;
    poppedElement = _this->_elements[_this->_top];
    _this->_top--;
    return poppedElement;
}


Element Stack_elementAt(Stack* _this, int aPosition) {   //스택 리스트의 aPosition 번째 원소를 얻는다.
    return (_this->_elements[aPosition]);
    
}
Element Stack_topElement(Stack* _this) {    // 스택의 top에 있는 원소를 리턴
    return (_this->_elements[_this->_top]);
}
int Stack_size(Stack* _this) {  // 스택의 사이즈를 리턴
    return (_this->_top+1);
}
