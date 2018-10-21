//
//  AppIO.c
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#include "AppIO.h"
#include "Common.h"
#include "QuadEquationProblem.h"


//입력 관련 함수
Boolean AppIO_in_solvingIsRequested() { // 이차방정식 풀이를 할 것인지 종료할 것인지 묻는 메시지 출력
    char answer;
    printf("방정식을 풀려면 y, 풀이를 종료하려면 아무 키나 입력하시오.");
    fpurge(stdin);  // 이전에 입력되어 임시 보관중인 모든 입력 값을 없앤다.
    answer = getchar(); // 키보드로부터 키 한개를 입력받는다.
    return ( answer == 'y');    // 입력 받은 것이 y이면 TURE,그 외의 값은 FALSE 반환
    
}
void AppIO_in_quadEquation( float* p_c0, float* p_c1, float* p_c2 ) {   // 계수를 각각 입력받아서 돌려준다.
   
    printf("2차항의 계수를 입력하시오 : ");
    scanf("%f" ,p_c2);  // 2차항의 계수

    printf("1차항의 계수를 입력하시오 : ");
    scanf("%f" ,p_c1);  // 1차항의 계수
    
    printf("상수항의 계수를 입력하시오 : ");
    scanf("%f" ,p_c0);  // 상수항의 계수
}

//출력 관련 함수
void AppIO_out_msg_startSolvingQuadEquation() { // <<<이차방정식 풀이>>> 메시지 출력
    printf("<<<이차방정식 풀이>>>\n");
}
void AppIO_out_msg_endSolvingQuadEquation() {   // <<<이차방정식 풀이를 종료합니다>>> 메시지 출력
    printf("<<<이차방정식 풀이를 종료합니다>>>\n");
}
void AppIO_out_msg_secondOrderTermCoefficientIsZero() { // 이차항의 계수가 0임을 알리는 메시지 출력
    printf("이차항의 계수가 0이어서, 이차방정식이 아닙니다.\n");
}
void AppIO_out_msg_determinantIsNegative(float aDeterminant) {  // 판별식의 값이 음수임을 알리는 메시지를 출력하고 판별식의 값을 보여준다.
    printf(">판별식의 값이 음수여서 해가 존재하지 않습니다.\n");
    printf("-판별식의 값 : %0.1f \n " ,aDeterminant);
}

void AppIO_out_quadEquation (float c0, float c1, float c2) {    // 이차방정식을 보여줌 단, 계수의 값이 0인 항은 보이지 않게 하고 모든 계수가 0이면 0=0 을 출력
    Boolean aNonZeroTermExists = FALSE;
    printf(">주어진 방정식 : ");
    //매크로 사용 , 0인지 아닌지 검사
    if( ! (FloatValueIsZero(c2)) ) {    // 2차항의 계수가 0이 아니라면
        aNonZeroTermExists = TRUE;
        printf("(%0.1f)x * x" , c2);
    }
    if( ! (FloatValueIsZero(c1)) ) {    // 1차항의 계수가 0이 아니라면
        if( aNonZeroTermExists )
            printf(" + ");
        aNonZeroTermExists = TRUE;
        printf("(%0.1f) x" ,c1);
    }
    if( ! (FloatValueIsZero(c0))) { // 상수항의 계수가 0이 아니라면
        if( aNonZeroTermExists )
            printf(" + ");
        aNonZeroTermExists = TRUE;
        printf("(%0.1f)" ,c0);
    }
    if( !aNonZeroTermExists ) { // 모든 계수가 0이면
        printf("0");
    }
    printf(" = 0\n");
    
    }

void AppIO_out_solution (float root1, float root2) {    // 방정식의 해를 보여준다.
    printf(">방정식의 해는 다음과 같습니다.\n");
    printf("x1 = %0.2f \n" ,root1);
    printf("x2 = %0.2f \n" ,root2);
}

