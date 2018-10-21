//
//  AppIO.h
//  CP2_WEEK4
//
//  Created by stu2017s10 on 2017. 3. 28..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Common.h"

//메시지 출력 함수
void AppIO_out_msg_startSolvlingQuadEquation();    // <<<이차방정식 풀이>>> 메시지 출력
void AppIO_out_msg_endSolvingQuadEquation();    // <<<이차방정식 풀이를 종료합니다>>> 메시지 출력
void AppIO_out_msg_secondOrderTermCoefficientIsZero(void) ;    // 이차항의 계수가 0임을 알리는 메시지 출력
void AppIO_out_msg_determinantIsNegative (float aDeterminant) ; // 판별식의 값이 음수임을 알리는 메시지 출력

//입력 받는 함수
Boolean AppIO_in_solvingIsRequested (void) ; // 이차방정식 풀이를 할 것인지 종료할 것인지 묻는 메시지 출력
void AppIO_in_quadEquation (float* p_c0, float* p_c1, float* p_c2) ; // 계수를 각각 입력받아 돌려준다.

//실행 결과를 보여주는 함수
void AppIO_out_quadEquation (float c0, float c1, float c2) ;    // 주어진 방정식을 출력한다.
void AppIO_out_determinant(float aDeterminant);//판별식의 값을 보여준다.
void AppIO_out_roots (float root1, float root2) ;//방정식의 해를 보여준다

#endif /* AppIO_h */
