//
//  QuadEquationProblem.c
//  CP2_WEEK4
//
//  Created by stu2017s10 on 2017. 3. 28..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include "Common.h"
#include "QuadEquationProblem.h"

//객체에게 정보를 제공하는 함수
void QuadEquationProblem_setEquation (QuadEquationProblem* _this, QuadEquation anEquation){
    _this->_equation = anEquation;
}

//객체의 상태를 검사하는 함수
Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this){
    return FloatValueIsZero(_this->_equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative (QuadEquationProblem*_this){ // 판별식이 0인지 아닌지 상태를 보여주는 함수
    if(((_this->_equation._c1 *_this->_equation._c1)-4 *_this->_equation._c2 *_this->_equation._c0)<0) {
        return TRUE;
    }
    else return FALSE;
}

//객체의 내용을 변경시키는 함수
void QuadEquationProblem_solve (QuadEquationProblem* _this){   // 방정식의 해를 구한다.
    float sqrtDeterminant;
    
    sqrtDeterminant = sqrt(QuadEquationProblem_determinant(_this));
    //결과를 _this->solution에 저장
    _this->_solution._root1 = (-_this->_equation._c1 + sqrtDeterminant )/(2.0*_this->_equation._c2);
    _this->_solution._root2 = (-_this->_equation._c1 - sqrtDeterminant )/(2.0*_this->_equation._c2);
}

//객체의 내용을 얻어내는 함수
QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this){
    return _this->_equation;
}

//주어진 이차방정식 문제 _this에 대해 판별식 계산
float QuadEquationProblem_determinant(QuadEquationProblem* _this){
    float determinant = (_this->_equation._c1 * _this->_equation._c1)-4 * _this->_equation._c2 * _this->_equation._c0;
    return determinant;
}

Solution QuadEquationProblem_solution(QuadEquationProblem* _this){  // 소유하고 있는 정보로부터 객체의 상태를 얻는다.
    return _this->_solution;
}
