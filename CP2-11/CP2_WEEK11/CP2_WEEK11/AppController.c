//
//  AppController.c
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
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

#define MIN_TEST_SIZE   1000
#define NUMBER_OF_TESTS 5
#define TEST_SIZE_INTERVAL  1000
#define MAX_DATA_SIZE   MIN_TEST_SIZE + (TEST_SIZE_INTERVAL*(NUMBER_OF_TESTS-1))

// 비공개 함수
void AppController_generateTestDataByRandomNumbers(AppController* _this,int aTestData[], int aMaxSize);  // 랜덤값 생성

long AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, Element aTestData[], int aTestSize);  // 삽입 시간
long AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize); // 최대값 삭제하는 시간
long AppController_timeForUnsortedvList_min (AppController* _this,UnsortedLinkedList* aList, int aTestSize);    // 최소값 찾는 시간

void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd,long aTimeForMin,long aTimeForRemoveMax);    // 결과값 출력

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

void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd,long aTimeForMin, long aTimeForRemoveMax) {    // 결과값 출력
    char results[255];
    sprintf(results, "크기 : %4d, 삽입 : %ld, 최소값얻기 : %ld, 최대값삭제 : %ld\n", aTestSize, aTimeForAdd, aTimeForMin, aTimeForRemoveMax);
    AppIO_out_message(_this->_appIO, results);
}

long AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, Element aTestData[], int aTestSize) { // 삽입 시간
    long duration = 0;
    int i;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isFull(aList)) {
            UnsortedLinkedList_add(aList, aTestData[i]);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
    
}

long AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize){ // 최대값 삭제 시간
    long duration = 0;
    int i;
    Element max;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isEmpty(aList)) {
            max = UnsortedLinkedList_min(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForUnsortedvList_min (AppController* _this,UnsortedLinkedList* aList, int aTestSize){    // 최소값 찾는 시간
    long duration = 0;
    int i;
    Element min;
    Timer* timer = Timer_new();
    
    for( i=0; i<aTestSize; i++ ) {
        Timer_start(timer);
        if( !UnsortedLinkedList_isEmpty(aList)) {
            min = UnsortedLinkedList_min(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    Timer_delete(timer);
    
    return duration;
}

void AppController_run(AppController* _this) {  // 실행
    int i;
    int testData[MAX_DATA_SIZE];
    int testSize = MIN_TEST_SIZE;
    double timeForAdd,timeForMin,timeForRemoveMax;
    
    AppIO_out_message(_this->_appIO, MSG_StartPerformanceMeasuring);
    AppIO_out_message(_this->_appIO, MSG_TitleForUnsortedArrayList);
   
    AppController_generateTestDataByRandomNumbers(_this,testData, MAX_DATA_SIZE);
    
    for( i=0; i<NUMBER_OF_TESTS; i++ ) {
        UnsortedLinkedList* aList = UnsortedLinkedList_new();
        timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, aList, testData, testSize);
        timeForMin = AppController_timeForUnsortedvList_min(_this, aList, testSize);
        timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, aList, testSize);
        
        AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
        UnsortedLinkedList_delete(aList);
        testSize += TEST_SIZE_INTERVAL;
    }
    AppIO_out_message(_this->_appIO, MSG_EndPerformanceMeasuring);
}
