//
//  AppIO.h
//  cp2
//
//  Created by stu2017s10 on 2017. 3. 8..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Common.h" // Boolean 타입을 위해 선언


void AppIO_out_msg_startSolvingLinearEquation();    // <<<일차방정식 풀이>>> 메시지를 출력
void AppIO_out_msg_endSolvingLinearEquation();  // <<<일차방정식 풀이를 종료합니다>>> 메시지를 출력
void AppIO_out_linearEquation(float c0, float c1);  // 일차방정식을 보여주는 함수
void AppIO_out_root(float root);    // 방정식의 해를 출력해주는 함수
void AppIO_out_msg_firstOrderTermCoefficientIsZero();   // 일차항의 계수가 0일 때 일차항의 계수가 0이므로 방정식을 풀 수 없다는 메시지를 출력
Boolean AppIO_in_solvingIsRequested(); // 방정식을 풀려면 y, 풀이를 종료하려면 아무 문자나 입력하라는 메시지를 출력하고 사용자에게 입력을 받아 입력받은 값이 y일 때 풀이가 시작되고 그 외의 문자일 땐 종료한다.
void AppIO_in_linearEquation (float* p_c0, float* p_c1); // // 1차항의 계수와 상수항의 계수를 입력받는 함수


#endif /* AppIO_h */
