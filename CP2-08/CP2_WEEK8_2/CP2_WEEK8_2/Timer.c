//
//  Timer.c
//  CP2_WEEK8_2
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Timer.h"
#include <time.h>

Timer* Timer_new(){//타이머 생성
    Timer* _this = NewObject(Timer);
    return _this;
}

void Timer_delete(Timer* _this){    //타이머 소멸
    free(_this);
}

void Timer_start(Timer* _this){ // 타이머 작동 시작
    _this->startCounter = clock();  // 실행 전 카운터 값을 얻음
}

void Timer_stop(Timer* _this){  //타이머 작동 중지
    _this->stopCounter = clock();//실행 후 카운터 값을 얻음
}

long Timer_duration(Timer* _this){//타이머 작동 시작부터 중지까지의 시간
    return (long)(_this->stopCounter - _this->startCounter)*(long)1000000 / (long)CLOCKS_PER_SEC;
}
