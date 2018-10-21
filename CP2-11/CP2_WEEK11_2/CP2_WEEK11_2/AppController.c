//
//  AppController.c
//  CP2_WEEK11_2
//
//  Created by stu2017s10 on 2017. 5. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "Common.h"
#include "Message.h"
#include "AppIO.h"
#include "Timer.h"
#include <time.h>
#include "UnsortedLinkedList.h"
#include "SortedLinkedList.h"

#define MIN_TEST_SIZE   10000
#define NUMBER_OF_TESTS 5
#define TEST_SIZE_INTERVAL  10000
#define MAX_DATA_SIZE   MIN_TEST_SIZE + (TEST_SIZE_INTERVAL*(NUMBER_OF_TESTS-1))

// 비공개 함수
void AppController_generateTestDataByRandomNumbers(AppController* _this,int aTestData[], int aMaxSize); // 랜덤값 생성성
long AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* uList, Element aTestData[], int aTestSize);  // 무순 리스트의 삽입 측정 시간
long AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* uList, int aTestSize); // 무순 리스트의 최대값 삭제 측정 시간
long AppController_timeForUnsortedLinkedList_min (AppController* _this,UnsortedLinkedList* uList, int aTestSize);   // 무순 리스트의 최소값 찾기 측정 시간

long AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* sList, Element aTestData[], int aTestSize);  // 순서 리스트의 삽입 측정 시간
long AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* sList, int aTestSize); // 순서 리스트의 최대값 삭제 측정 시간
long AppController_timeForSortedLinkedList_min (AppController* _this,SortedLinkedList* sList, int aTestSize);   // 순서 리스트의 최소값 찾기 측정 시간

void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd,long aTimeForMin,long aTimeForRemoveMax);  // 성능 측정 결과 값을 보여줌

struct _AppController {
    AppIO* _appIO;
};

AppController* AppController_new(void) {    // AppController 객체 생성
    AppController* _this = NewObject(AppController);
    _this->_appIO = AppIO_new();
    return _this;
}

void AppController_delete(AppController* _this) {   // AppController 객체 소멸
    AppIO_delete(_this->_appIO);
    free(_this);
}

void AppController_generateTestDataByRandomNumbers(AppController* _this,int aTestData[], int aMaxSize){    // 난수 생성
    srand((unsigned)time(NULL));
    for(int i = 0; i < aMaxSize; i++){
        aTestData[i] = rand();
    }
}

void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd,long aTimeForMin, long aTimeForRemoveMax) {
    char results[255];
    sprintf(results, "크기 : %4d, 삽입 : %ld, 최소값얻기 : %ld, 최대값삭제 : %ld\n", aTestSize, aTimeForAdd, aTimeForMin, aTimeForRemoveMax);
    AppIO_out_message(_this->_appIO, results);
}

long AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* uList, Element aTestData[], int aTestSize) {
    long duration = 0;
    int i;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isFull(uList)) {
            UnsortedLinkedList_add(uList, aTestData[i]);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
    
}

long AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* uList, int aTestSize){
    long duration = 0;
    int i;
    Element max;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isEmpty(uList)) {
            max = UnsortedLinkedList_min(uList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForUnsortedLinkedList_min (AppController* _this,UnsortedLinkedList* uList, int aTestSize){
    long duration = 0;
    int i;
    Element min;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isEmpty(uList)) {
            min = UnsortedLinkedList_min(uList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* sList, Element aTestData[], int aTestSize){
    long duration = 0;
    int i;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !SortedLinkedList_isFull(sList)) {
            SortedLinkedList_add(sList, aTestData[i]);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* sList, int aTestSize){
    long duration = 0;
    int i;
    Element max;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !SortedLinkedList_isEmpty(sList)) {
            max = SortedLinkedList_min(sList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForSortedLinkedList_min (AppController* _this,SortedLinkedList* sList, int aTestSize){
    long duration = 0;
    int i;
    Element min;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !SortedLinkedList_isEmpty(sList)) {
            min = SortedLinkedList_min(sList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

void AppController_run(AppController* _this) {
    int i;
    int testData[MAX_DATA_SIZE];
    int testSize = MIN_TEST_SIZE;
    double timeForAdd,timeForMin,timeForRemoveMax;
    
    AppIO_out_message(_this->_appIO, MSG_StartPerformanceMeasuring);
    AppController_generateTestDataByRandomNumbers(_this, testData, MAX_DATA_SIZE);
    AppIO_out_message(_this->_appIO, MSG_TitleForUnsortedArrayList);
    
    for( i=0; i<NUMBER_OF_TESTS; i++ ) {
        UnsortedLinkedList* uList = UnsortedLinkedList_new();
        timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, uList, testData, testSize);
        timeForMin = AppController_timeForUnsortedLinkedList_min(_this, uList, testSize);
        timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, uList, testSize);
        
        AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
        UnsortedLinkedList_delete(uList);
        testSize += TEST_SIZE_INTERVAL;
    }
    
    testSize = MIN_TEST_SIZE;

    AppIO_out_message(_this->_appIO, MSG_TitleForSortedArrayList);

    for( i=0; i<NUMBER_OF_TESTS; i++ ) {
        SortedLinkedList* sList = SortedLinkedList_new();
        timeForAdd = AppController_timeForSortedLinkedList_add(_this, sList, testData, testSize);
        timeForMin = AppController_timeForSortedLinkedList_min(_this, sList, testSize);
        timeForRemoveMax = AppController_timeForSortedLinkedList_removeMax(_this, sList, testSize);
       
        AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
        SortedLinkedList_delete(sList);
        testSize += TEST_SIZE_INTERVAL;
    }
    
    AppIO_out_message(_this->_appIO, MSG_EndPerformanceMeasuring);
    
}
