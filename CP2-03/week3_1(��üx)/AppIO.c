//  AppIO.c
//  week3
//
//  Created by stu2017s10 on 2017. 3. 21..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "AppIO.h"
#include "Common.h"


void AppIO_out_msg_startMagicSquare() { // <<<마방진 풀이를 시작합니다>>> 메시지 출력
    printf("<<<마방진 풀이를 시작합니다>>>\n");
}

void AppIO_out_msg_endMagicSquare() {   // <<<마방진 풀이를 종료합니다>>> 메시지 출력
    printf("<<<마방진 풀이를 종료합니다>>>\n");
}
int AppIO_in_order(void) {  // 차수를 입력받기 위한 메시지를 내보내고 차수를 입력받아 얻는다.
    int _order;
    printf("마방진 차수를 입력하시오 : ");
    scanf("%d" ,&_order);   // _order = 차수
    return _order;
}

void AppIO_out_board(int anOrder,int aBoard[MAX_ORDER][MAX_ORDER]) { // 주어진 차수의 완성된 마방진을 화면에 보여준다1
    printf("Magic Square Board : Order %d" ,anOrder);
    printf("\n");
    printf("%5s","");
    for( int col=0; col<anOrder; col++ ) {  // 차수만큼 col 증가 및 출력
    printf("[%2d]",col);
    }
    printf("\n");
    
    for( int row = 0; row<anOrder; row++ ){ // 차수만큼 row증가 및 출력
        printf("[%2d]",row);
        for( int col=0; col<anOrder; col++ ) {
            printf("%4d" ,aBoard[row][col]);    // aBoard에 저장된 row, col 값 출력 -> 마방진
        }
        printf("\n");
    }
}
