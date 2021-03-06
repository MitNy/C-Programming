//
//  main.c
//  week3
//
//  Created by stu2017s10 on 2017. 3. 21..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>

#include "Common.h"
#include "AppIO.h"
#include "MagicSquare.h"

int main(void) {

    MagicSquare magicSquare;
    magicSquare._maxOrder = MAX_ORDER;  // MAX_ORDER = 99
    
    AppIO_out_msg_startMagicSquare();   // 마방진 풀이 시작 메시지
    magicSquare._order = AppIO_in_order();  // 마방진 차수를 입력 받아 _order에 저장

    while(magicSquare._order != END_OF_RUN) {   // 마방진 차수가 -1이면 프로그램 종료
        if( MagicSquare_orderIsValid(magicSquare)) { // 차수가 유효한지 검사
            MagicSquare_solve(magicSquare,magicSquare._board);  // 주어진 차수의 마방진을 푼다.
            AppIO_out_board(magicSquare._order,magicSquare._board); // 마방진 판을 화면에 보여준다.
        }
        magicSquare._order = AppIO_in_order();  // 다음 마방진을 위해 차수를 입력받는다.
    }
    AppIO_out_msg_endMagicSquare(); // 마방진 풀이 종료 메시지
    return 0;
}
