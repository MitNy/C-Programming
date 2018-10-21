//
//  main.c
//  CP2_WEEK4
//
//  Created by stu2017s10 on 2017. 3. 28..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "AppIO.h"
#include "Common.h"
#include "QuadEquationProblem.h"
#include "Roots.h"

int main() {
    QuadEquationProblem qeProblem;  // 객체 qeProblem 생성 : 문제 풀이 과정에서 필요한 모든 정보를 소유한다.
    QuadEquation    equation;   // 객체 equation 생성
    Solution    solution;   // 객체 solution 생성
    
    AppIO_out_msg_startSolvlingQuadEquation();// 이차방정식 풀이 시작 메시지 출력
    printf("\n");
    while( AppIO_in_solvingIsRequested() ) {    // 사용자로부터 이차방정식 풀이 여부를 입력을 받는다.
        AppIO_in_quadEquation(&equation._c0,&equation._c1,&equation._c2);   // 이차방정식의 계수를 입력받는다.
        QuadEquationProblem_setEquation (&qeProblem, equation) ; // 객체와 부가정보를 제공
        AppIO_out_quadEquation (equation._c0, equation._c1, equation._c2) ; // 주어진 이차방정식을 보여준다.
        float determinant = QuadEquationProblem_determinant(&qeProblem);
        AppIO_out_determinant(determinant); //판별식의 값 출력
        
        if(QuadEquationProblem_secondOrderTermCoefficientIsZero (&qeProblem)) { // 이차항의 계수가 0이면
            AppIO_out_msg_secondOrderTermCoefficientIsZero();   // 이차항의 계수가 0이어서 이차방정식이 아니라는 메시지 출력
        }
        else {
            if( QuadEquationProblem_determinantIsNegative(&qeProblem)) {    // 판별식의 값이 음수라면
                float determinant = QuadEquationProblem_determinant(&qeProblem);
                AppIO_out_msg_determinantIsNegative(determinant);    // 판별식의 값과 판별식의 값이 음수라는 메시지 출력
            }
            else {
                QuadEquationProblem_solve(&qeProblem);  // 방정식의 해를 구한다.
                solution = QuadEquationProblem_solution(&qeProblem);
                AppIO_out_roots(solution._root1,solution._root2);   // 두 개의 방정식 해를 출력
            }
        }
    }
          AppIO_out_msg_endSolvingQuadEquation();   //종료 메시지 출력
          return 0;
}
