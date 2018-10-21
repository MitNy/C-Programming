//
//  UnsortedLinkedList.h
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef UnsortedLinkedList_h
#define UnsortedLinkedList_h

#include <stdio.h>
#include "Common.h"
#include "Node.h"

typedef struct _UnsortedLinkedList  UnsortedLinkedList;

UnsortedLinkedList* UnsortedLinkedList_new();   // 객체 생성
void UnsortedLinkedList_delete(UnsortedLinkedList* _this);  // 객체 소멸
Boolean UnsortedLinkedList_isEmpty (UnsortedLinkedList* _this); // 무순 리스트가 비었는지 검사
Boolean UnsortedLinkedList_isFull (UnsortedLinkedList* _this);  // 무순 리스트가 꽉 찼는지 검사
Boolean UnsortedLinkedList_add (UnsortedLinkedList* _this,Element anElement);   // 삽입
Element UnsortedLinkedList_min (UnsortedLinkedList* _this); // 최소값 찾기
Element UnsortedLinkedList_removeMax(UnsortedLinkedList* _this);    // 최대값 삭제

#endif /* UnsortedLinkedList_h */
