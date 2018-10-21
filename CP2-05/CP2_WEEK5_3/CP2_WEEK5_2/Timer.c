//
//  Timer.c
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Timer.h"
#include "Common.h"
#include <math.h>

Timer* Timer_new(void) {    // 타이머 생성
    Timer* _this = NewObject(Timer);
    return _this;
}

void Timer_delete(Timer* _this) {   // 타이머 소멸
    free(_this);
}
void Timer_start(Timer* _this) {    // 타이머 작동 시작
    _this->startCounter = clock();  // 실행 전 카운터 값을 얻음
}

void Timer_stop(Timer* _this) { // 타이머 작동 중지
    _this->stopCounter = clock();
}

long Timer_duration(Timer* _this) {
    return (long)(_this->stopCounter -_this->stopCounter*(long)1000000 / (long)CLOCKS_PER_SEC);
}
