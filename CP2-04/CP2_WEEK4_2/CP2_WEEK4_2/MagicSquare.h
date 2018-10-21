//
//  MagicSquare.h
//  CP2_WEEK4_2
//
//  Created by stu2017s10 on 2017. 3. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef MagicSquare_h
#define MagicSquare_h

#include "Common.h"

typedef struct {    // MagicSqure 객체 생성
    int _order; // 차수
    int _maxOrder;
    int _board[MAX_ORDER][MAX_ORDER];   // 보드
} MagicSquare;

typedef struct {    // CellLocation 객체 생성
    int _row;
    int _col;
} CellLocation;

void MagicSquare_setOrder(MagicSquare* _this, int anOrder);   // 객체의 속성값을 설정하는 함수

//객체의 상태를 검사하는 함수
Boolean MagicSquare_orderIsValid(MagicSquare* _this); // 주어진 차수가 유효한지 검사하고, 유효하지 않다면 오류 메시지를 출력한다.
void MagicSquare_solve(MagicSquare* _this);    // 주어진 차수에 따라 마방진 판을 채운다.

//객체의 정보를 얻는 함수
int MagicSquare_order( MagicSquare* _this );
int* MagicSquare_board( MagicSquare* _this );

#endif /* MagicSquare_h */
