//
//  SortedArrayList.c
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "SortedArrayList.h"

struct _SortedArrayList{
    int _maxSize;
    int _size;
    Element* _elements;
};

int SortedArrayList_positionUsingBinarySearch(SortedArrayList* _this, Element anElement);   // 삽입 위치 찾기
void SortedArrayList_addAt(SortedArrayList* _this, Element anElement, int aPosition);   // 주어진 위치에 삽입
Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition);    // 주어진 위치에서 원소 삭제

SortedArrayList* SortedArrayList_new(int aMaxSize){  // SortedArrayList 객체 생성
    SortedArrayList* _this = NewObject(SortedArrayList);
    _this->_maxSize = aMaxSize;
    _this->_elements = NewVector(Element, _this->_maxSize);
    
    _this->_size = 0;
    return _this;
}
void SortedArrayList_delete(SortedArrayList* _this){  // SortedArrayList 객체 소멸
    free(_this);
}

//삽입 위치 찾기
int SortedArrayList_positionUsingBinarySearch(SortedArrayList* _this, Element anElement){
    int left = 0;
    int right = _this->_size -1;
    int mid;
    while (left <= right){
        mid = (left + right) / 2;
        if(anElement == _this->_elements[mid])
            return mid;
        else if(anElement < _this->_elements[mid])
            return mid -1;
        else if(anElement > _this->_elements[mid])
            left = mid + 1;
    }
    return  left;
}

Boolean SortedArrayList_isEmpty(SortedArrayList* _this){    // 배열이 비었을 경우
    return (_this->_size == 0);
}

Boolean SortedArrayList_isFull(SortedArrayList* _this){ // 배열이 꽉찼을 경우
    return  (_this->_size == _this->_maxSize);
}

// 배열의 맨 끝에 삽입
Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement){
    if (SortedArrayList_isFull(_this))
        return FALSE ;
    else {
        //삽입할 위치를 결정한다.
        int positionForAdd = SortedArrayList_positionUsingBinarySearch (_this, anElement);
        // 찾아진 삽입 위치에 주어진 원소를 삽입한다.
        SortedArrayList_addAt (_this, anElement, positionForAdd);
        return TRUE ;
    }
}
//최대값 삭제
Element SortedArrayList_removeMax(SortedArrayList* _this){
    int maxPosition;
    Element max;
    
    maxPosition = _this->_size-1;
    max = SortedArrayList_removeAt(_this, maxPosition);
    
    return max;
}

// 최소값 얻기
Element SortedArrayList_min(SortedArrayList* _this){
    int min;
    min = 0;
   
    return min;
}

void SortedArrayList_addAt(SortedArrayList* _this, Element anElement, int aPosition){
    for(int i = (_this->_size-1);i>aPosition;i--){
        _this->_elements[i+1] = _this->_elements[i];
    }
    _this->_elements[aPosition] = anElement;
    (_this->_size)++;
}
// 주어진 위치의 원소를 삭제
Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition){
    Element removedElement = _this->_elements[aPosition];
    
    for(int i = (aPosition+1); i<(_this->_size); i++){
        _this->_elements[i-1] = _this->_elements[i];
    }
    
    _this->_size--;
    
    return removedElement;
}
