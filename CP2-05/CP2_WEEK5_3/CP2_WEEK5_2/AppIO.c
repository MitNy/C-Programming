//
//  AppIO.c
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
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

void AppIO_out_boardColumnTitle(int anOrder) {
    printf("Magic Square Board : Order %d" ,anOrder);
    printf("\n");
    printf("%5s","");
    for( int aCol=0; aCol<anOrder; aCol++) { //차수만큼 aCol 증가 및 출력
        printf("[%2d]",aCol);
    }
    printf("\n");
}
void AppIO_out_boardRowTitle(int aRow) {    // aRow 출력
        printf("[%2d]",aRow);
}
void AppIO_out_cell(int aCell) {    // aCell에 저장된 마방진 출력
    printf("%4d" ,aCell);
}

void AppIO_out_newLine(void) {
    printf("\n");
}
