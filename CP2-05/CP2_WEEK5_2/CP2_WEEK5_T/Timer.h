//
//  Timer.h
//  CP2_WEEK5_T
//
//  Created by stu2017s10 on 2017. 4. 5..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#include <stdio.h>
#include <time.h>

typedef struct{
    clock_t startCounter;   // clock_t 는 cpu clock수를 저장하는 구조체
    clock_t stopCounter;
} Timer;

Timer* Timer_new(void); // 타이머 생성
void Timer_delete(Timer* _this);    // 타이머 소멸
void Timer_start(Timer* _this); // 타이머 작동 시작
void Timer_stop(Timer* _this);  // 타이머 작동 중지
long Timer_duration(Timer* _this);  // 타이머 작동 시작부터 중지까지의 시간

#endif /* Timer_h */
