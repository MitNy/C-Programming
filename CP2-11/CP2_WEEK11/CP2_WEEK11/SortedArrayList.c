//
//  SortedArrayList.c
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "SortedArrayList.h"

int SortedLinkedList_positionUsingBinarySearch(SortedLinkedList* _this, Element anElement);
void SortedLinkedList_addAt(SortedLinkedList* _this, Element anElement, int aPosition);
Element SortedLinkedList_removeAt(SortedLinkedList* _this, int aPosition);

struct _SortedLinkedList {
    int _maxSize;
    int _size;
    Element* _elements;
};


SortedLinkedList* SortedLinkedList_new() {  // SortedArrayList 객체 생성
    SortedLinkedList* _this = NewObject(SortedLinkedList);
   // _this->_maxSize = aMaxSize;
    _this->_elements = NewVector(Element, _this->_maxSize);
    
    _this->_size = 0;
    return _this;
}

void SortedLinkedList_delete (SortedLinkedList* _this) {  // SortedArrayList 객체 소멸
    free(_this);
}

Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this) {   // 배열이 비었을 경우
    return (_this->_size == 0);
}

Boolean SortedLinkedList_isFull(SortedLinkedList* _this) {    // 배열이 꽉찼을 경우
    return (_this->_size == _this->_maxSize);
}

int SortedLinkedList_positionUsingBinarySearch(SortedLinkedList* _this, Element anElement) {
    int left = 0;
    int right = _this->_size-1;
    int mid;
    
    while( left <= right ) {
        mid = (left + right) /2;
        if( anElement == _this->_elements[mid]) {
            return mid;
        }
        else if( anElement < _this->_elements[mid]) {
            right = mid-1;
        }
        else if( anElement > _this->_elements[mid]) {
            left = mid+1;
        }
    }
    return left;
}


// 배열의 맨 끝에 삽입
Boolean SortedLinkedList_add (SortedLinkedList* _this, Element anElement) {
    if( SortedLinkedList_isFull(_this)) {
        return FALSE;
    }
    else {
        //삽입할 위치를 결정한다.
        int positionForAdd = SortedLinkedList_positionUsingBinarySearch(_this,anElement);
        // 찾아진 삽입 위치에 주어진 원소를 삽입한다.
        SortedLinkedList_addAt(_this, anElement,positionForAdd);
        
        return TRUE;
    }
}

void SortedLinkedList_addAt(SortedLinkedList* _this, Element anElement, int aPosition) {  // 주어진 위치에 원소 삽입
    for( int i=(_this->_size-1); i>aPosition; i-- ) {
        _this->_elements[i+1] = _this->_elements[i];
    }
    _this->_elements[aPosition] = anElement;
    (_this->_size)++;
}

Element SortedLinkedList_removeAt(SortedLinkedList* _this, int aPosition) {
    // aPosition 의 값은 반드시 _this->_size 값보다 작아야 한다.
    Element removedElement = _this->_elements[aPosition];
    for( int i = (aPosition+1); i<(_this->_size); i++ ) {
        _this->_elements[i-1] = _this->_elements[i];
    }
    _this->_size--;
    
    return removedElement;
}

Element SortedLinkedList_min (SortedLinkedList* _this) {
    int min;
    min = 0;
    
    return min;
}

//최대값 삭제
Element SortedLinkedList_removeMax(SortedLinkedList* _this){
    int maxPosition;
    Element max;
    
    maxPosition = _this->_size -1;
    max = SortedLinkedList_removeAt(_this,maxPosition);
    
    return max;
}
