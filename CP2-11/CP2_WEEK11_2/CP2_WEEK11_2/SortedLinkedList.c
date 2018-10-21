//
//  SortedLinkedList.c
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "SortedLinkedList.h"

struct _SortedLinkedList {
    int _size;
    Node* _head;
};

SortedLinkedList* SortedLinkedList_new() {   // 순서 리스트 객체 생성
    SortedLinkedList* _this = NewObject(SortedLinkedList);
    _this->_size = 0;
    _this->_head = NULL;
    
    return _this;
}

void SortedLinkedList_delete(SortedLinkedList* _this){  // 순서 리스트 객체 소멸
    free(_this);
}

Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this){  // 순서 리스트가 비었는지 검사
    return (_this->_size == 0);
}

Boolean SortedLinkedList_isFull(SortedLinkedList* _this){   // 순서 리스트가 꽉 찼는지 검사
    return FALSE;
}

Boolean SortedLinkedList_add(SortedLinkedList* _this, Element anElement) {   // 순서 리스트에 삽입
    Node* currentNode = _this->_head;
    Node* addedNode = Node_new();
    addedNode->_element = anElement;
    addedNode->_next = NULL;
    
    if( _this->_head == NULL ) {
        _this->_head = addedNode;
        _this->_size++;
    }
    else if( addedNode->_element <= currentNode->_element  ) {
        addedNode->_next = currentNode;
        _this->_head = addedNode;
        _this->_size++;
    }
    else {
        while( (currentNode->_next != NULL) && ( addedNode->_element <= currentNode->_next->_element) ) {
            currentNode = currentNode->_next;
        }
        addedNode->_next = currentNode->_next;
        currentNode->_next = addedNode;
        _this->_size++;
    }
    return TRUE;
    
}

Element SortedLinkedList_min(SortedLinkedList* _this) {  // 순서 리스트에서 최소값 찾기
    return _this->_head->_element;
}

Element SortedLinkedList_removeMax(SortedLinkedList* _this) {    // 순서 리스트에서 최대값 삭제
    Node* currentNode = _this->_head;
    Element removedElement;
    
    while ( currentNode->_next != NULL ) {
        currentNode = currentNode->_next;
    }
    removedElement = currentNode->_element;
    currentNode = NULL;
    
    return removedElement;
}
