//
//  UnsortedArrayList.c
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "UnsortedArrayList.h"
int UnsortedArrayList_minPositionRecursively(UnsortedArrayList* _this, int left, int right);    // 최소값 위치 찾기
int UnsortedArrayList_maxPositionRecursively (UnsortedArrayList* _this, int left, int right);   // 최대값 위치 찾기
Element UnsortedArrayList_removeAt(UnsortedArrayList* _this, int aPosition);    // 주어진 위치에서 원소 삭제

struct _UnsortedArrayList{
    int _maxSize;
    int _size;
    Element* _elements;
};

UnsortedArrayList* UnsortedArrayList_new (int aMaxSize){   // UnsortedArrayList 객체 생성
    UnsortedArrayList* _this = NewObject(UnsortedArrayList);
    _this->_maxSize = aMaxSize;
    _this->_elements = NewVector(Element, _this->_maxSize);
    
    _this->_size = 0;
    return _this;
}

void UnsortedArrayList_delete(UnsortedArrayList* _this){  // UnsortedArrayList 객체 소멸    free(_this);
}

Boolean UnsortedArrayList_isEmpty(UnsortedArrayList* _this){    // 배열이 비었을 경우
    return (_this->_size == 0);
}

Boolean UnsortedArrayList_isFull(UnsortedArrayList* _this){    // 배열이 꽉찼을 경우
    return  (_this->_size == _this->_maxSize);
}

Boolean UnsortedArrayList_add(UnsortedArrayList* _this, Element anElement){    // 배열의 맨 끝에 삽입
    if (UnsortedArrayList_isFull(_this)) {
        return FALSE;
    }
    else{
        _this->_elements[_this->_size] = anElement;
        (_this->_size)++;
        return TRUE;
    }
}

Element UnsortedArrayList_removeMax(UnsortedArrayList* _this){ // 최대값 삭제
    int maxPosition;
    Element max;
    
    maxPosition = UnsortedArrayList_maxPositionRecursively(_this,0,_this->_size-1);
    max = UnsortedArrayList_removeAt(_this, maxPosition);
    
    return max;
}

int UnsortedArrayList_maxPositionRecursively (UnsortedArrayList* _this, int left, int right){
      // 최대값 위치를 찾음

    if ( left == right ) {
        return left ;
    }
    else {
        int mid = (left+right) / 2 ;
        int maxPositionOfLeftPart = UnsortedArrayList_maxPositionRecursively (_this, left, mid);
        int maxPositionOfRightPart = UnsortedArrayList_maxPositionRecursively (_this, mid+1, right);
        if ( _this->_elements[maxPositionOfLeftPart] >= _this->_elements[maxPositionOfRightPart] ) {
            return maxPositionOfLeftPart;
        }
        else {
            return maxPositionOfRightPart;
        }
    }
}

Element UnsortedArrayList_removeAt(UnsortedArrayList* _this, int aPosition){    // 주어진 위치의 원소를 삭제
    // aPosition의 값은 반드시 _this->_size 값보다 작아야 함.
    Element removedElement = _this->_elements[aPosition];
    for( int i = (aPosition+1); i < (_this->_size); i++ ){
        _this->_elements[i-1] = _this->_elements[i];
    }
    _this->_size--;
    
    return removedElement;  // 삭제된 값은 return
}


Element UnsortedArrayList_min(UnsortedArrayList* _this){  // 최소값 얻기
    int minPosition;
    minPosition = UnsortedArrayList_minPositionRecursively (_this,0,_this->_size-1);
   
    return _this->_elements[minPosition];
}

int UnsortedArrayList_minPositionRecursively(UnsortedArrayList* _this, int left, int right){
    // 최소값의 위치를 얻음
    int minPosition;
    
    if ( left == right ) {
        return left ;
    }
    else {
        int mid = (left+right) / 2 ;
        int minPositionOfLeftPart = UnsortedArrayList_maxPositionRecursively (_this, left, mid);
        int minPositionOfRightPart = UnsortedArrayList_maxPositionRecursively (_this, mid+1, right);
        if ( _this->_elements[minPositionOfLeftPart] <= _this->_elements[minPositionOfRightPart] ) {
            minPosition = minPositionOfLeftPart;
        }
        else {
            minPosition = minPositionOfRightPart;
        }
    }
    
    return minPosition;
    
}
