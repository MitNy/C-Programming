//
//  SortedLinkedList.h
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef SortedLinkedList_h
#define SortedLinkedList_h

#include "Common.h"
#include <stdio.h>

typedef struct _SortedLinkedList SortedLinkedList;
SortedLinkedList* SortedLinkedList_new (void) ;
void SortedLinkedList_delete (SortedLinkedList* _this) ;
Boolean SortedLinkedList_isEmpty (SortedLinkedList* _this) ;
Boolean SortedLinkedList_isFull (SortedLinkedList* _this) ;
Boolean SortedLinkedList_add (SortedLinkedList* _this, Element anElement) ;
Element SortedLinkedList_min (SortedLinkedList* _this) ;
Element SortedLinkedList_removeMax (SortedLinkedList* _this) ;

#endif /* SortedLinkedList_h */
