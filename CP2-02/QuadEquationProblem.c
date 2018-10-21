//
//  QuadEquationProblem.c
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#include "QuadEquationProblem.h"
#include "AppIO.h"


// 이차방정식 관련 함수

// 객체의 상태를 보여주는 함수 ( 객체의 속성 정보 값이 바뀌지 않음)
Boolean QuadEquationProblem_secondOrderTermCoefficinetIsZero (QuadEquationProblem aProblem) {
    return FloatValueIsZero (aProblem._equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative (QuadEquationProblem aProblem) { // 판별식이 0인지 아닌지 상태를 보여주는 함수
    if ( ( (aProblem._equation._c1 * aProblem._equation._c1)-4*aProblem._equation._c2*aProblem._equation._c0 ) < 0) {
        return TRUE;
    }
    else return FALSE;
}

float QuadEquationProblem_determinant (QuadEquationProblem aProblem) {  // 판별식의 값을 얻는 함수
    // 계산을 하여 객체의 상태를 얻는다.
    float determinant = (aProblem._equation._c1 * aProblem._equation._c1)-4*aProblem._equation._c2*aProblem._equation._c0; // 판별식의 값 계산,  판별식의 값 b*b-4*a*c
    return determinant;
}

//객체의 상태를 바꾸는 함수 ( 객체의 속성 정보 값이 바뀜 )
Solution QuadEquationProblem_solve (QuadEquationProblem aProblem) { // 방정식의 해를 구한다. 결과는 해(Solution) 객체로 만들어 돌려준다.
    Solution solution;
    
    float determinant = QuadEquationProblem_determinant (aProblem);
    //객체에게 일을 시키는 쪽 ( main()에서만 사용하는 함수지만 이렇게 객체 자신도 필요하면 사용!)
    float sqrtDeterminant = sqrt(determinant);  // <math.h> 반드시 include
    solution._root1 = (-aProblem._equation._c1 + sqrtDeterminant) / (2.0 * aProblem._equation._c2);
    solution._root2 = (-aProblem._equation._c1 - sqrtDeterminant) / (2.0 * aProblem._equation._c2);

    return solution;
}

Solution QuadEquationProblem_solution (QuadEquationProblem aProblem) {
    // 소유하고 있는 정보로부터 객체의 상태를 얻는다.
    return aProblem._solution;
}
