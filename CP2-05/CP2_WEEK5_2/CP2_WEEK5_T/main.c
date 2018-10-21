//
//  main.c
//  CP2_WEEK5_T
//
//  Created by stu2017s10 on 2017. 4. 5..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "MagicSquare.h"
#include "Common.h"
#include "Timer.h"
#include "AppIO.h"

int main() {
    MagicSquare* magicSquare;   // 저장 장소 선언
    Timer* timer;
    int order,count;
    long executionTime; // 성능 측정 값
    
    timer = Timer_new();    // 타이머 생성

    AppIO_outputLine("<<<마방진 풀이의 성능 측정을 시작합니다>>>");
    AppIO_outputLine("하나의 차수에 대해 10회 반복 실행한 시간을 측정합니다");
    
    // MAX_ORDER = 99
    for( order = 9; order<=MAX_ORDER; order+=10) {  // 차수는 입력받지 않고 9부터 10씩 증가시키며 반복
        Timer_start(timer); // 타이머 작동 시작
        for( count=0; count<10; count++ ) { // count는 0부터 10까지 1씩 증가
            magicSquare = MagicSquare_new();    // 객체 생성
            MagicSquare_setOrder(magicSquare,order);   // 객체의 속성값을 설정하는 함수
            MagicSquare_solve(magicSquare);   // 주어진 차수의 마방진을 푸는 함수
            MagicSquare_delete(magicSquare);    // 객체 소멸
        }
        Timer_stop(timer);  // 타이머 작동 중지
        executionTime = Timer_duration(timer);
        AppIO_outputExecutionTime(order,executionTime); // 성능 측정 값 출력
    }
    Timer_delete(timer);    // 타이머 소멸
    AppIO_outputLine(">>>성능측정을 마칩니다<<<");
    return 0;
}
