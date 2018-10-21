//
//  MagicSquare.h
//  week3
//
//  Created by stu2017s10 on 2017. 3. 21..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef MagicSquare_h
#define MagicSquare_h

#include "Common.h"

typedef struct {    // CellLocation 객체 생성
    int _row;
    int _col;
} CellLocation;



Boolean MagicSquare_orderIsValid(int anOrder); // 주어진 차수가 유효한지 검사하고, 유효하지 않다면 오류 메시지를 출력한다.
void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER] );    // 주어진 차수에 따라 마방진 판을 채운다.

#endif /* MagicSquare_h */

