//
//  UnsortedArrayList.h
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef UnsortedArrayList_h
#define UnsortedArrayList_h
#include "Common.h"

typedef struct _UnsortedArrayList UnsortedArrayList;

UnsortedArrayList* UnsortedArrayList_new (int aMaxSize);    // UnsortedArrayList 객체 생성
void UnsortedArrayList_delete(UnsortedArrayList* _this);    // UnsortedArrayList 객체 소멸
Boolean UnsortedArrayList_isEmpty(UnsortedArrayList* _this);   // 배열이 비었을 경우
Boolean UnsortedArrayList_isFull(UnsortedArrayList* _this);    // 배열이 꽉찼을 경우
Boolean UnsortedArrayList_add(UnsortedArrayList* _this, Element anElement);   // 배열의 맨 끝에 삽입
Element UnsortedArrayList_min(UnsortedArrayList* _this);  // 최소값 얻기
Element UnsortedArrayList_removeMax(UnsortedArrayList* _this); // 최대값 삭제


#endif /* UnsortedArrayList_h */
