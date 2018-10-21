//
//  UnsortedLinkedList.c
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "UnsortedLinkedList.h"

struct _UnsortedLinkedList {
    int _size;
    Node* _head;
};

UnsortedLinkedList* UnsortedLinkedList_new() {  //UnsortedArrayList 객체 생성
    UnsortedLinkedList* _this = NewObject(UnsortedLinkedList);
    _this->_size = 0;
    _this->_head = NULL;
    return _this;
}

void UnsortedLinkedList_delete (UnsortedLinkedList* _this) {  // UnsortedArrayList 객체 소멸
    free(_this);
}

//배열이 비었을 경우
Boolean UnsortedLinkedList_isEmpty (UnsortedLinkedList* _this) {    // 무순 리스트가 비었는지 검사
    return ( _this->_size == 0 );
}

// 배열이 꽉찼을 경우
Boolean UnsortedLinkedList_isFull (UnsortedLinkedList* _this) { // 무순 리스트가 꽉 찼는지 검사
    return FALSE;
}

Boolean UnsortedLinkedList_add (UnsortedLinkedList* _this, Element anElement) { // 무순 리스트에 삽입
    Node* addedNode;
    addedNode = Node_new();
    addedNode->_element = anElement;
    addedNode->_next = _this->_head;
    _this->_head = addedNode;
    _this->_size++;
    
    return TRUE;
}

Element UnsortedLinkedList_min (UnsortedLinkedList* _this) {    // 최소값 찾기
    int min = _this->_head->_element;
    
    Node* currentNode = _this->_head->_next;
    while( currentNode != NULL ) {
        if( min > currentNode->_element ) {
            min = currentNode->_element;
        }
        currentNode = currentNode->_next;
    }
    
    return min;
}

Element UnsortedLinkedList_removeMax(UnsortedLinkedList* _this) {   // 최대값 삭제
    int Max = _this->_head->_element;
    int removeElement;
    Node* removeMax = NULL;
    Node* preNode = _this->_head;
    Node* currentNode = _this->_head->_next;
    
    while( currentNode != NULL ) {
        if( Max < currentNode->_element ) {
            Max = currentNode->_element;
            removeMax = currentNode;
        }
        currentNode = currentNode->_next;
        preNode = preNode->_next;
    }
    
    removeElement = removeMax->_element;
    
    return removeElement;
}
