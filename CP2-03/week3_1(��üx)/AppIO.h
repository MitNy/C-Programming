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

void AppIO_out_msg_startMagicSquare();
void AppIO_out_msg_endMagicSquare();
int AppIO_in_order(void);
void AppIO_out_board(int anOrder,int aBoard[MAX_ORDER][MAX_ORDER]);

#endif /* AppIO_h */
