//
//  SortedArrayList.h
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef SortedArrayList_h
#define SortedArrayList_h
#include "Common.h"
#include "AppController.h"

typedef struct _SortedArrayList SortedArrayList;

SortedArrayList* SortedArrayList_new(int aMaxSize); // SortedArrayList 객체 생성
void SortedArrayList_delete(SortedArrayList* _this);   // SortedArrayList 객체 소멸
Boolean SortedArrayList_isEmpty(SortedArrayList* _this);    // 배열이 비었을 경우
Boolean SortedArrayList_isFull(SortedArrayList* _this); // 배열이 꽉찼을 경우
Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement);     // 배열의 맨 끝에 삽입
Element SortedArrayList_removeMax(SortedArrayList* _this);  // 최대값 삭제
Element SortedArrayList_min(SortedArrayList* _this);    // 최소값 얻기

#endif /* SortedArrayList_h */
