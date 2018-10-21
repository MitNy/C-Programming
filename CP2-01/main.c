//
//  main.c
//  cp2
//
//  Created by stu2017s10 on 2017. 3. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>    // 수학 함수 사용을 위한 math.h 라이브러리
#include "Common.h" // 매크로 헤더
#include "AppIO.h"  // AppIO 관련 함수 헤더


float LinearEquation_solve (float c0, float c1) {   //  주어진 계수를 갖는 일차방정식의 해를 구하는 함수
    if(FloatValueIsZero(c1)) {  // 코드의 안전성을 위해 매크로를 통해 검사
        if(c1*c0 >= 0.0) {  // 두 계수의 부호가 같을 때
            return -MAXFLOAT;   //  return 값은 -MAXFLOAT;
        }
        else {  //두 계수의 부호가 다를 때
            return +MAXFLOAT;   // return 값은 +MAXFLOAT;
    }
}
    else {
        return (-c0)/c1;    
    }
}

int main( int argc, const char * argv[])
{
    Boolean solvingIsRequested;
    float c0,c1;    //c1 : 1차항의 계수 , c0 : 상수항의 계수
    float root;
    
    AppIO_out_msg_startSolvingLinearEquation(); // <<<일차방정식 풀이>>> 메시지를 출력

    solvingIsRequested = AppIO_in_solvingIsRequested(); // 방정식을 풀려면 y, 풀이를 종료하려면 아무 문자나 입력받고 입력받은 값이 y일 때 풀이가 시작된다는 내용의 함수
    
    while(solvingIsRequested) { //반복해야 할 일
        AppIO_in_linearEquation(&c0,&c1);   //일차방정식의 계수를 입력받는다.
        AppIO_out_linearEquation(c1,c0);    //입력 받은 일차방정식을 보여준다.
        
        if(FloatValueIsZero(c1)) {  //일차항의 계수가 0이면
            AppIO_out_msg_firstOrderTermCoefficientIsZero();    //일차항의 계수가 0이라는 메시지를 출력
        }
        else {
            root = LinearEquation_solve(c0,c1); //일차방정식을 푼다.
            AppIO_out_root(root);   //일차방정식의 해를 출력
        }
        solvingIsRequested = AppIO_in_solvingIsRequested(); // 방정식을 풀려면 y, 풀이를 종료하려면 아무 문자나 입력받고 입력받은 값이 y일 때 풀이가 시작된다는 내용의 함수
        }
    AppIO_out_msg_endSolvingLinearEquation();   // <<<일차방정식 풀이를 종료합니다>>> 메시지를 출력

    return 0;
}
