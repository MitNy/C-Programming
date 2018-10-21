//
//  main.c
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#include <stdio.h>
#include <math.h>

#include "AppIO.h"
#include "Common.h"
#include "QuadEquationProblem.h"


int main() {
    QuadEquationProblem     qeProblem;  // 객체 qeProblem 생성
    Boolean    solvingIsRequested;  // 객체 solvingIsRequested 생성
    QuadEquation    equation; // 객체 equation 생성
    Solution    solution; // 객체 solution 생성
    //객체 생성 : 문제 풀이 과정에서 필요한 객체의 속성 정보를 소유한다.
    
    AppIO_out_msg_startSolvingQuadEquation();   // 이차방정식 풀이 시작 메시지 출력
    solvingIsRequested = AppIO_in_solvingIsRequested(); // 이차방정식 풀이 여부를 묻고 사용자로부터 응답을 입력받는다.
    
    while ( solvingIsRequested ) {
        AppIO_in_quadEquation (&(equation._c0), &(equation._c1), &(equation._c2));  // 이차방정식의 계수를 입력받는다.
        AppIO_out_quadEquation (equation._c0, equation._c1, equation._c2);  // 이차방정식을 보여준다.
        
        //QuadEquationProblem_ 을 붙인 함수는 QuadEquationProblem 객체와 직결된 함수
        qeProblem._equation = equation; // main()에서 객체의 속성값을 직접 변경
        if( QuadEquationProblem_secondOrderTermCoefficinetIsZero(qeProblem) ) { // 이차항의 계수가 0 이면
            AppIO_out_msg_secondOrderTermCoefficientIsZero();   // 이차항의 계수가 0이어서 이차방정식이 아니라는 메시지 출력
        }
        else {
            if( QuadEquationProblem_determinantIsNegative(qeProblem) ) {    // 판별식의 값이 음수이면
                float determinant = QuadEquationProblem_determinant (qeProblem) ;   //판별식의 값과 판별식의 값이 음수라는 메시지를 출력
                AppIO_out_msg_determinantIsNegative(determinant);
        }
        else {
            qeProblem._solution = QuadEquationProblem_solve(qeProblem); // main()에서 객체의 속성값을 직접 변경 , 이차방정식을 푼다.
            solution = QuadEquationProblem_solution(qeProblem);
            AppIO_out_solution (solution._root1, solution._root2); // 이차방정식의 해를 출력
            }
        }
        solvingIsRequested = AppIO_in_solvingIsRequested(); // 이차방정식 풀이 여부를 묻고 사용자로부터 응답을 입력받는다.
    }
    AppIO_out_msg_endSolvingQuadEquation();  // 이차방정식 풀이 종료 메시지 출력
    return 0;
}
