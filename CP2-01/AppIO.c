//
//  AppIO.c
//  cp2
//
//  Created by stu2017s10 on 2017. 3. 8..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

// AppIO 관련 함수 구현
#include "AppIO.h"  // AppIO 헤더 파일 include


void AppIO_out_msg_startSolvingLinearEquation() {   // <<<일차방정식 풀이>>> 메시지를 출력
    printf("<<<일차방정식 풀이>>>\n");
}
void AppIO_out_msg_endSolvingLinearEquation() { // <<<일차방정식 풀이를 종료합니다>>> 메시지를 출력
    printf("<<<일차방정식 풀이를 종료합니다>>>\n");
}
void AppIO_out_linearEquation(float c0, float c1) { // 일차방정식을 보여주는 함수
    printf(">주어진 방정식: (%f)x+(%f) = 0\n" ,c1,c0);
}


void AppIO_out_root(float root) {   // 방정식의 해를 출력
    printf(">방정식의 해는 다음과 같습니다 : \n");
    printf("x = %f\n",root);
}
void AppIO_out_msg_firstOrderTermCoefficientIsZero() {  // 일차항의 계수가 0일 때, 일차항의 계수가 0이므로 방정식을 풀 수 없다는 메시지를 출력
    printf(">일차항의 계수가 0이므로 방정식을 풀 수 없습니다.\n");
}

Boolean AppIO_in_solvingIsRequested() { // 방정식을 풀려면 y, 풀이를 종료하려면 아무 문자나 입력하라는 메시지를 출력하고 사용자에게 입력을 받아 입력받은 값이 y일 때 풀이가 시작되고 그 외의 문자일 땐 종료한다.
    char answer;
    printf("방정식을 풀려면 y, 풀이를 종료하려면 아무 문자나 치시오.");
    fpurge(stdin);  // 이전에 입력되어 임시 보관중인 모든 입력 값을 없앤다.
    answer = getchar(); // 새로 입력하는 값을 받는다.
    return (answer == 'y'); // 입력받은 값이 y이면 TRUE,그 외의 값은 FALSE를 return
}


void AppIO_in_linearEquation (float* p_c0, float* p_c1) {   // 1차항의 계수와 상수항의 계수를 입력받는 함수
    printf("1차항의 계수를 입력하시오: ");
    scanf("%f",p_c1);
    printf("상수항의 계수를 입력하시오: ");
    scanf("%f",p_c0);
}
