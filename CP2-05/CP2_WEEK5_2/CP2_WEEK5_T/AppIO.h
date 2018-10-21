//
//  AppIO.h
//  CP2_WEEK5_T
//
//  Created by stu2017s10 on 2017. 4. 5..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>

void AppIO_output(char* aMessage);  // 배열을 받음 , == char aMessage[]
void AppIO_outputLine(char* aMessage);  // \n 포함
void AppIO_outputExecutionTime(int anOrder, long anExecutionTime); // 성능 측정 값 출력

#endif /* AppIO_h */
