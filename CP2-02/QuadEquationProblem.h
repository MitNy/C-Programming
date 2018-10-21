//
//  QuadEquationProblem.h
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#ifndef QuadEquationProblem_h
#define QuadEquationProblem_h


#include "Common.h"


typedef struct {
    float _c0;  // 상수항의 계수
    float _c1;  // 1차항의 계수
    float _c2;  // 2차항의 계수
} QuadEquation;

typedef struct {
    float _root1;   // 방정식의 해 1
    float _root2;   // 방정식의 해 2
} Solution;

typedef struct {
    QuadEquation _equation;
    Solution _solution;
}  QuadEquationProblem; // 이차방정식 문제


Boolean QuadEquationProblem_secondOrderTermCoefficinetIsZero (QuadEquationProblem aProblem);
Boolean QuadEquationProblem_determinantIsNegative (QuadEquationProblem aProblem);
Solution QuadEquationProblem_solve (QuadEquationProblem aProblem);
Solution QuadEquationProblem_solution (QuadEquationProblem aProblem);
float QuadEquationProblem_determinant (QuadEquationProblem aProblem);
void QuadEquationProblem_setEquation (QuadEquationProblem, QuadEquationProblem equation);


#endif /* QuadEquationProblem_h */
