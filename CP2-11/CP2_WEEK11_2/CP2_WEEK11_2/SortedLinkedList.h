//
//  SortedLinkedList.h
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef SortedLinkedList_h
#define SortedLinkedList_h

#include <stdio.h>
#include "Common.h"
#include "Node.h"

typedef struct _SortedLinkedList SortedLinkedList;

SortedLinkedList* SortedLinkedList_new();   // 순서 리스트 객체 생성
void SortedLinkedList_delete(SortedLinkedList* _this);  // 순서 리스트 객체 소멸
Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this);  // 순서 리스트가 비었는지 검사
Boolean SortedLinkedList_isFull(SortedLinkedList* _this);   // 순서 리스트가 꽉 찼는지 검사
Boolean SortedLinkedList_add(SortedLinkedList* _this, Element anElement);   // 순서 리스트에 삽입
Element SortedLinkedList_min(SortedLinkedList* _this);  // 순서 리스트에서 최소값 찾기
Element SortedLinkedList_removeMax(SortedLinkedList* _this);    // 순서 리스트에서 최대값 삭제

#endif /* SortedLinkedList_h */
