//
//  Stack.h
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include <stdio.h>
#include "Common.h"

typedef struct _Stack Stack;
typedef int Element;


Stack* Stack_new();    // 스택 객체 생성
void Stack_delete(Stack* _this);    // 스택에 있는 원소와 스택 소멸
void Stack_reset(Stack* _this); // 스택 초기화
void Stack_push(Stack* _this, Element anElement);  // 스택에 원소를 넣음
Boolean Stack_isEmpty(Stack* _this);   // 스택이 비었는지 검사
Boolean Stack_isFull(Stack* _this);    // 스택이 꽉 찼는지 검사
Element Stack_pop(Stack* _this);   // 스택에서 원소를 꺼내고 삭제
Element Stack_elementAt(Stack* _this, int aPosition);   //스택 리스트의 aPosition 번째 원소를 얻는다.
Element Stack_topElement(Stack* _this);    // 스택의 top에 있는 원소를 리턴
int Stack_size(Stack* _this);  // 스택의 사이즈를 리턴

#endif /* Stack_h */
