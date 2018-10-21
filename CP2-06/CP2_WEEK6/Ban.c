//
//  Ban.c
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Ban.h"
#include "Common.h"

struct _Ban {
    int _maxSize;
    int _size;
    int* _elements;
};

Ban* Ban_new(void){ // 객체 생성자
    Ban* _this = NewObject(Ban);
 
    _this->_maxSize = DEFAULT_CAPACITY; // 최대 학생 수 설정
    _this->_elements = NewVector(int, _this->_maxSize);
    _this->_size = 0;   // 객체를 생성한 직후의 학생수는 0명
    
    return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity) {   //최대 학생 수 설정 및 초기 학생수 설정
    Ban* _this = NewObject(Ban);
    _this->_maxSize = givenCapacity;    // 최대 학생 수 설정
    _this->_elements = NewVector(int, givenCapacity);
    _this->_size = 0;   // 객체를 생성한 직후의 학생수는 0명
    
    return _this;
}

Boolean Ban_scoreIsValid(int aScore) {  // 점수가 0보다 작거나 큰지 검사
    return ( aScore >= 0 && aScore <= 100 );
}

char Ban_scoreToGrade(int aScore) {
    if( aScore >= 90 ) {
        return 'A';
    }
    else if( aScore >= 80 ) {
        return 'B';
    }
    else if( aScore >= 70 ) {
        return 'C';
    }
    else if( aScore >= 60 ) {
        return 'D';
    }
    else {
        return 'F';
    }
}

void Ban_delete(Ban* _this){    // 객체 소멸자
    free(_this);
}
// Ban객체의 상태 알아보기
int Ban_maxSize(Ban* _this){
    return (_this->_maxSize);
}

int Ban_size(Ban* _this) {
    return (_this->_size);
}

Boolean Ban_isEmpty(Ban* _this) {
    return (_this->_size == 0);
}

Boolean Ban_isFull(Ban* _tihs) {
    return (_tihs->_size >=_tihs->_maxSize);
}

// 학생 개인 정보 입력 받아 저장
Boolean Ban_add(Ban* _this,int aScore) {
    //성적을 배열에 저장
    if( Ban_isFull(_this)) {
        return FALSE;   // 저장 공간 부족
    }
    else {
        // 배열의 맨 마지막 위치에 넣는다.
        _this->_elements[_this->_size] = aScore;
        _this->_size++;
        return TRUE;
    }
}

// Ban에 저장된 원소 얻어내기
int Ban_elementAt(Ban* _this,int anOrder) {
    if( anOrder >= _this->_size) {
        // 주어진 위치에 원소가 존재하지 않는다.
        return -1;
    }
    else {
        // 원소가 정상적으로 존재한다.
        return (_this->_elements[anOrder]);
    }
}

// 학생 정보 정렬(성적 순)
void Ban_sortStudentsByScore(Ban* _this) {
    int size = _this->_size;
    
    // 정렬할 데이터는 _this->_elements[0] ~  _this->_elements[size-1]
    // 퀵 정렬 실행
    if( size >= 2 ) {   // 개수가 2개 이상이면
        //최소값의 위치를 찾는다.
        int minPosition = 0;
        for( int i=1; i<size; i++ ) {
            if(_this->_elements[i] < _this->_elements[minPosition]) {
                minPosition = i;
            }
        }
        // 최소값을 원소 구간의 맨 끝으로 옮긴다.
        SWAP(int, _this->_elements[minPosition], _this->_elements[size-1]);
        
        // 정렬 시작
        Ban_quickSortRecursively(_this, 0, size-2);
    }
}
// 학생 정보 정렬( 성적 순)
void Ban_quickSortRecursively(Ban* _this,int left, int right) {
    if( left < right ) {
        int mid = Ban_partition(_this, left, right);
        Ban_quickSortRecursively(_this, left, mid-1);
        Ban_quickSortRecursively(_this, mid+1, right);
    }
}

int Ban_partition(Ban* _this, int left, int right) {
    int pivot = left;
    int pivotScore = _this->_elements[pivot];
    
    right++;
    do {
        do { left++; }  while (_this->_elements[left] > pivotScore );
        do { right--; } while (_this->_elements[right] < pivotScore );
        if( left < right ) {
            SWAP(int, _this->_elements[left], _this->_elements[right]);
        }
    }   while ( left < right );
    SWAP(int, _this->_elements[pivot], _this->_elements[right]);
    return right;
    }

float Ban_averageScore(Ban* _this){ // 평균을 계산하여 return 값으로 돌려준다.
    float sumOfScores = (float) Ban_sumOfScoreRecursively(_this, 0, _this->_size-1);
    float average = sumOfScores / (float) _this->_size;
    return average;
}

int Ban_maxScore(Ban* _this) {   // 최고점을 찾아서 return 값으로 돌려준다
    return Ban_maxScoreRecursively(_this, 0, _this->_size-1);
}

int Ban_minScore(Ban* _this){   // 최저점을 찾아서 return 값으로 돌려준다.
    return Ban_minScoreRecursively(_this, 0, _this->_size-1);
}

//재귀함수로 구현
int Ban_sumOfScoreRecursively(Ban* _this,int left, int right) {
    // 성적 합계를 계산하여 return 값으로 돌려준다.
    // 크기를 (N-1)로 줄이는 재귀함수
    if( left > right ) {
        return 0;
    }
    else {
        return (_this->_elements[left] + Ban_sumOfScoreRecursively(_this, left+1, right));
    }
}

int Ban_maxScoreRecursively(Ban* _this,int left, int right) {
    // 최고점을 찾아서 return 값으로 돌려준다
    // 두개의 구간으로 나누는 재귀함수
    int maxOfLeft;
    int maxOfRight;
    int middle;
    
    if( left == right ) {   // left 와 right 같을때
        return _this->_elements[left];  // _elements의 left값 반환
    }
    else {
        middle = (left + right )/2; // middle은 left+right를 2로 나눈 값
        maxOfLeft = Ban_maxScoreRecursively(_this, left, middle);
        maxOfRight = Ban_maxScoreRecursively(_this, middle+1, right);
        
        if( maxOfLeft >= maxOfRight ) { // maxOfLeft가 maxOfRight보다 크거나 같을 때
            return maxOfLeft;
        }
        else {
            return maxOfRight;
        }
    }
    
}

int Ban_minScoreRecursively(Ban* _this,int left, int right) {
    // 최저점을 찾아서 return 값으로 돌려준다.
    // 크기를 (N-1)로 줄이는 재귀함수
    int minOfLeft;
    int minOfRight;
    int middle;
    
    if( left == right ) {   // left 와 right 같을때
        return _this->_elements[left];  // _elements의 left값 반환
    }
    else {
        middle = (left + right)/2;  // middle은 left+right를 2로 나눈 값
        minOfLeft = Ban_minScoreRecursively(_this, left, middle);
        minOfRight = Ban_minScoreRecursively(_this, middle+1, right);
        
        if( minOfLeft <= minOfRight ) { // maxOfLeft가 maxOfRight보다 작거나 같을 때
            return minOfLeft;
        }
        else {
            return minOfRight;
        }
    }
    
}

// 평균 이상인 학생 수 세기
int Ban_numberOfStudentsAboveAverage(Ban* _this) {
    float average = Ban_averageScore(_this);
    int numberOfStudentsAboveAverage = 0;
    
    for( int i=0; i<_this->_size; i++ ) {
        if( ((float)_this->_elements[i]) >= average) {
            numberOfStudentsAboveAverage ++;
        }
    }
    return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_countGrades(Ban* _this) { //학점 별 학생수를 구함
    char currentGrade;
    GradeCounter* gradeCounter = GradeCounter_new();
    
    for( int i=0; i<_this->_size; i++ ) {
        currentGrade = Ban_scoreToGrade(_this->_elements[i]);
        GradeCounter_count(gradeCounter, currentGrade);
    }
    return gradeCounter;
}
