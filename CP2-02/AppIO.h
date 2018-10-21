//
//  AppIO.h
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#ifndef AppIO_h
#define AppIO_h

#include "Common.h"
#include <stdio.h>

//입력 관련 함수
Boolean AppIO_in_solvingIsRequested(void); // 이차방정식 풀이를 할 것인지 종료할 것인지 묻는 메시지 출력
void AppIO_in_quadEquation( float* p_c0, float* p_c1, float* p_c2 );   // 계수를 각각 입력받아서 돌려준다.

//출력 관련 함수
void AppIO_out_msg_startSolvingQuadEquation(void);  // <<<이차방정식 풀이>>> 메시지 출력
void AppIO_out_msg_endSolvingQuadEquation(void);   // <<<이차방정식 풀이를 종료합니다>>> 메시지 출력
void AppIO_out_msg_secondOrderTermCoefficientIsZero(void); // 이차항의 계수가 0임을 알리는 메시지 출력
void AppIO_out_msg_determinantIsNegative(float aDeterminant);  // 판별식의 값이 음수임을 알리는 메시지를 출력하고 판별식의 값을 보여준다.
void AppIO_out_quadEquation (float c0, float c1, float c2);    // 이차방정식을 보여줌 단, 계수의 값이 0인 항은 보이지 않게 하고 모든 계수가 0이면 0=0 을 출력
void AppIO_out_solution (float root1, float root2);    // 방정식의 해를 보여준다.

#endif /* AppIO_h */
