//
//  main.c
//  CP2_WEEK5
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>

#include "Common.h"
#include "AppIO.h"
#include "MagicSquare.h"


int main(void) {
    
    MagicSquare* magicSquare;    // 저장 장소 선언
  //  magicSquare->_maxOrder  = MAX_ORDER; // MAX_ORDER = 99
    
    AppIO_out_msg_startMagicSquare();   // 마방진 풀이 시작 메시지
    magicSquare = MagicSquare_new();    // magicSquare 객체 생성
    int order = AppIO_in_order();  // 마방진 차수를 입력 받아 _order에 저장
    
    while(order != END_OF_RUN) {   // 마방진 차수가 -1이면 프로그램 종료, -1이 아니면 풀이 시작
        // 첫번째 인수는 항상 객체의 사용권인 객체의 주소 값
        // 두번째 이후 인수는 별도의 정보가 필요할 경우에 제공되는 정보
        MagicSquare_setOrder(magicSquare,order);   // 객체의 속성값을 설정하는 함수
        if( MagicSquare_orderIsValid(magicSquare)) { // 차수가 유효한지 검사
            MagicSquare_solve(magicSquare);  // 주어진 차수의 마방진을 푼다.
            AppIO_out_board(MagicSquare_order(magicSquare),(int(*)[MAX_ORDER])MagicSquare_board(magicSquare)); // 마방진 판을 화면에 보여준다.
        }
        order = AppIO_in_order();  // 다음 마방진을 위해 차수를 입력받는다.
    }
    MagicSquare_delete(magicSquare);    // 객체 소멸
    
    AppIO_out_msg_endMagicSquare(); // 마방진 풀이 종료 메시지
    return 0;
}
