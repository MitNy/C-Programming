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
    int _order;
    int _board[MAX_ORDER][MAX_ORDER];  // MAX_ORDER = 99
    
    AppIO_out_msg_startMagicSquare();   // 마방진 풀이 시작 메시지
    _order = AppIO_in_order();  // 마방진 차수를 입력 받아 _order에 저장
    
    while(_order != END_OF_RUN) {   // 마방진 차수가 -1이면 프로그램 종료
        if( MagicSquare_orderIsValid(_order)) { // 차수가 유효한지 검사
            MagicSquare_solve(_order,_board);   //주어진 차수의 마방진을 얻는다.
            AppIO_out_board(_order,_board); // 마방진 판을 화면에 보여준다.
        }
        _order = AppIO_in_order();  // 다음 마방진을 위해 차수를 입력받는다.
    }
    AppIO_out_msg_endMagicSquare(); // 마방진 풀이 종료 메시지
    return 0;
}

