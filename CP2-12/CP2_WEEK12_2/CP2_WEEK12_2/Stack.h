//
//  Stack.h
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include <stdio.h>
#include "Common.h"
#include "Node.h"

typedef struct _Stack Stack;


Stack* Stack_new(); // stack 객체 생성
void Stack_delete(Stack* _this);    // stack 객체 소멸
Boolean Stack_isEmpty(Stack* _this);    // 스택이 empty 이면 TRUE를, 아니면, FALSE를 얻는다.
Boolean Stack_isFull(Stack* _this); // 스택이 full 이면 TRUE 를, 아니면, FALSE 를 얻는다.
Element Stack_push(Stack* _this, Element anElement);    // 스택에 anElement 를 삽입
Element Stack_pop(Stack* _this);    // 스택의 top에서 원소를 삭제하고 그 값을 얻는다.
void Stack_reset(Stack* _this);    // 스택 초기화
int Stack_size(Stack* _this);   // 스택의 크기 리턴
Element Stack_elementAt(Stack* _this, int aPosition);  //스택 리스트의 aPosition 번째 원소를 얻는다.
Element Stack_peekElement(Stack* _this);   // top에 있는 원소를 리턴
Node* Stack_top(Stack* _this); // top 리턴

#endif /* Stack_h */
