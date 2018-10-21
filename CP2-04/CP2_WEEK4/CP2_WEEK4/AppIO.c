//
//  AppIO.c
//  CP2_WEEK4
//
//  Created by stu2017s10 on 2017. 3. 28..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include "Common.h"
#include "QuadEquationProblem.h"

//메시지 출력 함수
void AppIO_out_msg_startSolvlingQuadEquation() {    // <<<이차방정식 풀이>>> 메시지 출력
    printf("<<<이차방정식 풀이>>>");
}
void AppIO_out_msg_endSolvingQuadEquation(){    // <<<이차방정식 풀이를 종료합니다>>> 메시지 출력
    printf("<<<이차방정식 풀이를 종료합니다>>>");
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero (void) {    // 이차항의 계수가 0임을 알리는 메시지 출력
    printf(">이차항의 계수가 0이어서, 이차방정식이 아닙니다.\n");
}
//판별식의 값을 보여준다
void AppIO_out_msg_determinantIsNegative (float aDeterminant) { // 판별식의 값이 음수임을 알리는 메시지
    printf(">판별식의 값이 음수여서 해가 존재하지 않습니다.\n");
}

//입력 받는 함수
Boolean AppIO_in_solvingIsRequested (void){ // 이차방정식 풀이를 할 것인지 종료할 것인지 묻는 메시지 출력
    char answer;
    printf("방정식을 풀려면 y, 풀이를 종료하려면 아무 키나 입력하시오 : ");
    fpurge(stdin);  // 이전에 입력되어 임시 보관중인 모든 입력 값을 없앤다.
    answer = getchar(); // 키보드로부터 키 한개를 입력받는다.
    return ( answer == 'y');    // 입력 받은 것이 y이면 TRUE,그 외의 값은 FALSE 반환
}

//판별식의 값을 보여준다.
void AppIO_out_determinant(float aDeterminant) {
    printf(">판별식의 값 : %0.1f\n",aDeterminant);
    
}
//계수를 입력 받아서 이차방정식 객체를 만든다
void AppIO_in_quadEquation (float* p_c0, float* p_c1, float* p_c2){ // 계수를 각각 입력받아 돌려준다.
    printf("2차항의 계수를 입력하시오 : ");
    scanf("%f",p_c2);   // 2차항의 계수
    
    printf("1차항의 계수를 입력하시오 : ");
    scanf("%f",p_c1);   // 1차항의 계수
    
    printf("상수항의 계수를 입력하시오 : ");
    scanf("%f",p_c0);   // 상수항의 계수
}



//실행 결과를 보여주는 함수
// 계수의 값이 0인 항은 보이지 않는다 ( 모든 계수가 0이면 "0=0" 을 출력 )
void AppIO_out_quadEquation (float c0, float c1, float c2){
    Boolean nonZeroTermDoesExist = FALSE;
    printf(">주어진 방정식 : ");
    // 매크로를 사용하여 0인지 아닌지 검사한다
    if( !(FloatValueIsZero(c2)) ) { // 2차항의 계수가 0이 아니라면
        nonZeroTermDoesExist = TRUE;
        printf("(%f)x * x",c2);
    }
    if( !(FloatValueIsZero(c1)) ) { // 1차항의 계수가 0이 아니라면
        if(nonZeroTermDoesExist)
            printf(" + ");
        nonZeroTermDoesExist = TRUE;
        printf("(%f)x",c1);
    }
    if ( ! (FloatValueIsZero(c0)) ) {   // 상수항의 계수가 0이 아니라면
        if(nonZeroTermDoesExist)
            printf(" + ");
        nonZeroTermDoesExist = TRUE;
        printf("(%f)",c0);
    }
    if( !nonZeroTermDoesExist)  // 모든 계수가 0이면
        printf("0");
    printf(" = 0\n");

}
//방정식의 해를 보여준다
void AppIO_out_roots (float root1, float root2){
    printf(">방정식의 해는 다음과 같습니다.\n");
    printf("x1 = %0.2f\n",root1);
    printf("x2 = %0.2f\n",root2);
}
