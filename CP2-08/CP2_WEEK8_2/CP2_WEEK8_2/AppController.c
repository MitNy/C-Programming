//
//  AppController.c
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "Common.h"
#include "AppIO.h"
#include "UnsortedArrayList.h"
#include "Message.h"
#include "Timer.h"
#include "SortedArrayList.h"
#include <time.h>

#define MIN_TEST_SIZE   1000
#define NUMBER_OF_TESTS 5
#define TEST_SIZE_INTERVAL  1000
#define MAX_DATA_SIZE   MIN_TEST_SIZE + (TEST_SIZE_INTERVAL*(NUMBER_OF_TESTS-1))



void AppController_generateTestDataByRandomNumbers(AppController* _this, int aTestData[], int aMaxSize);    //난수 생성
long AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, Element aTestData[], int aTestSize);    //무순 리스트 삽입 시 시간 측정
long AppController_timeForSortedArrayList_add(AppController* _this, SortedArrayList* aList, Element aTestData[], int aTestSize);    // 순서 리스트 삽입 시 시간 측정
long AppController_timeForUnsortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize);   //무순 리스트 최대값 삭제 시 시간 측정
long AppController_timeForSortedArrayList_removeMax(AppController* _this, SortedArrayList* aList, int aTestSize);   //순서 리스트 최대값 삭제 시 시간 측정
long AppController_measureTimeOfUnsortedArrayList_min(AppController* _this, UnsortedArrayList* aList, Element aTestData[], int aTestSize);  // 무순 리스트 최소값 얻을 때의 시간 측정
long AppController_measureTimeOfSortedArrayList_min (AppController* _this, SortedArrayList* aList, Element aTestData[], int aTestSize); // 순서 리스트 최소값 얻을 때의 시간 측정
void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd, long aTimeForMin, long aTimeForRemoveMax);    // 결과 출력


struct _AppController{
    AppIO* _appIO;
};

AppController* AppController_new(){    // AppController 객체 생성
    AppController* _this = NewObject(AppController);
    _this->_appIO = AppIO_new();
    return _this;
}

void AppController_delete(AppController* _this){   // AppController 객체 소멸
    AppIO_delete(_this->_appIO);
    free(_this);
}

void AppController_run(AppController* _this){   // 프로그램 실행
    int testData[MAX_DATA_SIZE];
    int testSize = MIN_TEST_SIZE;
    double timeForAdd, timeForMin, timeForRemoveMax;
    
    AppIO_out_message(_this->_appIO, MSG_StartPerformanceMeasuring);
    AppController_generateTestDataByRandomNumbers(_this, testData, MAX_DATA_SIZE);
    
    AppIO_out_message(_this->_appIO, MSG_TitleForUnsortedArrayList);
    
    for(int i = 0 ; i < NUMBER_OF_TESTS ; i++){
        UnsortedArrayList* listForTest = UnsortedArrayList_new(MAX_DATA_SIZE);
        timeForAdd = AppController_timeForUnsortedArrayList_add(_this, listForTest, testData, testSize);
        timeForMin = AppController_measureTimeOfUnsortedArrayList_min(_this, listForTest, testData, testSize);
        timeForRemoveMax = AppController_timeForUnsortedArrayList_removeMax(_this, listForTest, testSize);
        AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
        UnsortedArrayList_delete(listForTest);
        testSize += TEST_SIZE_INTERVAL;
    }
    
    testSize = MIN_TEST_SIZE;
    
    AppIO_out_message(_this->_appIO, MSG_TitleForSortedArrayList);
    for(int i = 0 ; i <NUMBER_OF_TESTS;i++){
        SortedArrayList* listForTest = SortedArrayList_new (MAX_DATA_SIZE);
        timeForAdd = AppController_timeForSortedArrayList_add(_this, listForTest, testData, testSize);
        timeForMin = AppController_measureTimeOfSortedArrayList_min(_this, listForTest, testData, testSize);
        timeForRemoveMax = AppController_timeForSortedArrayList_removeMax(_this, listForTest, testSize);
        AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
        SortedArrayList_delete(listForTest);
        testSize += TEST_SIZE_INTERVAL;
    }
    
    AppIO_out_message(_this->_appIO, MSG_EndPerformanceMeasuring);
}

void AppController_generateTestDataByRandomNumbers(AppController* _this, int aTestData[], int aMaxSize){    // 난수 생성
    srand((unsigned)time(NULL));
    for(int i = 0;i < aMaxSize;i++){
        aTestData[i] = rand();
    }
}

long AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, Element aTestData[], int aTestSize){    //  무순 리스트 삽입 시 시간 측정
    long duration = 0;
    Timer* timer = Timer_new();
    
    for(int i = 0 ; i <aTestSize ; i++){
        Timer_start(timer);
        if(!UnsortedArrayList_isFull(aList)){
            UnsortedArrayList_add(aList, aTestData[i]);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    
    return duration;
}

long AppController_timeForSortedArrayList_add(AppController* _this, SortedArrayList* aList, Element aTestData[], int aTestSize){    // 순서 리스트 삽입 시 시간 측정
    long duration = 0;
    Timer* timer = Timer_new();
    
    for(int i = 0 ; i <aTestSize ; i++){
        Timer_start(timer);
        if(!SortedArrayList_isFull(aList)){
            SortedArrayList_add(aList, aTestData[i]);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    
    return duration;
}


long AppController_measureTimeOfUnsortedArrayList_min (AppController* _this, UnsortedArrayList* aList, Element aTestData[],int aTestSize){  // 최소값 얻을 때의 시간 측정
    int i;
    Element min;
    long duration = 0;
    
    Timer* timer = Timer_new();
    
    for(i = 0 ; i < aTestSize; i++){
        //이곳의 측정에서는 리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복한다
        Timer_start(timer);
        if(!UnsortedArrayList_isEmpty(aList)){
            min = UnsortedArrayList_min(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    return duration;
}

long AppController_measureTimeOfSortedArrayList_min (AppController* _this, SortedArrayList* aList, Element aTestData[], int aTestSize){
    int i;
    Element min;
    long duration = 0;
    
    Timer* timer = Timer_new();
    
    for(i = 0 ; i < aTestSize; i++){
        //이곳의 측정에서는 리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복한다
        Timer_start(timer);
        if(!SortedArrayList_isEmpty(aList)){
            min = SortedArrayList_min(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    return duration;
}


long AppController_timeForUnsortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize){
    Element max;
    long duration = 0;
    
    Timer* timer = Timer_new();
    //리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복
    for(int i = 0; i <aTestSize ; i++){
        Timer_start(timer);
        if(!UnsortedArrayList_isEmpty(aList)){
            max = UnsortedArrayList_removeMax(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    
    return duration;
}


long AppController_timeForSortedArrayList_removeMax(AppController* _this, SortedArrayList* aList, int aTestSize){
    Element max;
    long duration = 0;
    
    Timer* timer = Timer_new();
    //리스트의 내용이 변하지 않은 상태에서 동일한 행위를 반복
    for(int i = 0; i <aTestSize ; i++){
        Timer_start(timer);
        if(!SortedArrayList_isEmpty(aList)){
            max = SortedArrayList_removeMax(aList);
        }
        Timer_stop(timer);
        duration += Timer_duration(timer);
    }
    
    Timer_delete(timer);
    
    return duration;
}

void AppController_showResults(AppController* _this, int aTestSize, long aTimeForAdd, long aTimeForMin, long aTimeForRemoveMax){
    char results[255];
    sprintf(results, "크기 : %4d, 삽입 : %ld, 최소값 얻기 : %ld, 최대값 삭제 : %ld\n", aTestSize, aTimeForAdd, aTimeForMin, aTimeForRemoveMax);
    AppIO_out_message(_this->_appIO, results);
}
