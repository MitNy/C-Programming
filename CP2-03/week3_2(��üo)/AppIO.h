//
//  AppIO.h
//  week3
//
//  Created by stu2017s10 on 2017. 3. 21..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include "Common.h"

void AppIO_out_msg_startMagicSquare(); // <<<마방진 풀이를 시작합니다>>> 메시지 출력
void AppIO_out_msg_endMagicSquare();   // <<<마방진 풀이를 종료합니다>>> 메시지 출력
int AppIO_in_order(void);  // 차수를 입력받기 위한 메시지를 내보내고 차수를 입력받아 얻는다.
void AppIO_out_board(int anOrder,int aBoard[MAX_ORDER][MAX_ORDER]); // 주어진 차수의 완성된 마방진을 화면에 보여준다.

#endif /* AppIO_h */
