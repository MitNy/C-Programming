//
//  AppIO.c
//  CP2_WEEK5_T
//
//  Created by stu2017s10 on 2017. 4. 5..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"

void AppIO_output(char* aMessage) {  // 배열을 받음 , == char aMessage[]
    printf("%s", aMessage); // main에서 문자열을 받고 aMessage에 저장
}
void AppIO_outputLine(char* aMessage) { // \n 포함
    printf("%s\n", aMessage); // main에서 문자열을 받고 aMessage에 저장
}
void AppIO_outputExecutionTime(int anOrder, long anExecutionTime) { // 성능 측정 값 출력
    printf("차수 : %2d, 시간: %ld(마이크로 초)\n", anOrder,anExecutionTime);
}
