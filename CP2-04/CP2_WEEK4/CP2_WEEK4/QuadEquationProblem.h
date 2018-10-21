//
//  QuadEquationProblem.h
//  CP2_WEEK4
//
//  Created by stu2017s10 on 2017. 3. 28..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef QuadEquationProblem_h
#define QuadEquationProblem_h

#include <stdio.h>
#include "Common.h"
#include "Roots.h"

typedef struct{
    float _c0;  //상수항의 계수
    float _c1;  //1차항의 계수
    float _c2;  //2차항의 계수
}QuadEquation;  // 이차방정식 객체를 위한 자료형

typedef struct {
    QuadEquation    _equation;
    Solution        _solution; 
}QuadEquationProblem;   // 이차방정식 문제 객체를 위한 자료형

//객체에게 정보를 제공하는 함수
void QuadEquationProblem_setEquation (QuadEquationProblem* _this, QuadEquation anEquation) ;

//객체의 상태를 검사하는 함수(객체의 속성 정보 값이 바뀌지 않음)
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this);   // 이차항이 0인지 아닌지 상태를 검사하는 함수
Boolean QuadEquationProblem_determinantIsNegative (QuadEquationProblem*_this);  // 판별식이 0인지 아닌지 상태를 보여주는 함수

//객체의 내용을 변경시키는 함수
void QuadEquationProblem_solve (QuadEquationProblem* _this) ;   // 방정식의 해를 구한다.

//객체의 내용을 얻어내는 함수
QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this);
float QuadEquationProblem_determinant(QuadEquationProblem* _this);  //주어진 이차방정식 문제 _this에 대해 판별식 계산
Solution QuadEquationProblem_solution(QuadEquationProblem* _this); // 소유하고 있는 정보로부터 객체의 상태를 얻는다.
#endif /* QuadEquationProblem_h */
