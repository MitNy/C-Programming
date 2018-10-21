//
//  MagicSquare.c
//  CP2_WEEK4_2
//
//  Created by stu2017s10 on 2017. 3. 29..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "MagicSquare.h"
#include "Common.h"

#define EMPTY_CELL -1

void MagicSquare_setOrder(MagicSquare* _this, int anOrder) {   // 객체의 속성값을 설정하는 함수
    _this->_order = anOrder;
}

//객체의 상태를 검사하는 함수
Boolean MagicSquare_orderIsValid(MagicSquare* _this) { // 주어진 차수가 유효한지 검사하고, 유효하지 않다면 오류 메시지를 출력
    if( _this->_order < 3) {   // 차수가 3보다 작을때
        printf("오류 : 차수가 너무 작습니다. 3보다 크거나 같아야 합니다.\n");
        return FALSE;
    }
    else if( _this->_order > _this->_maxOrder) {    // 차수가 99보다 클 때
        printf("오류 : 차수가 너무 큽니다. %d보다 작아야 합니다.\n",_this->_maxOrder);
        return FALSE;
    }
    else if(( _this->_order %2)==0) {  // 차수가 짝수일 때
        printf("오류 : 차수가 짝수입니다. 차수는 홀수이어야 합니다\n");
        return FALSE;
    }
    else {
        return TRUE;
    }
}

void MagicSquare_solve(MagicSquare* _this) {   // 주어진 차수의 마방진을 푸는 함수
    int row,col;    // 위치 표현을 위한 변수
    
    CellLocation currentLoc;    // CellLocation의 currentLoc 객체 선언
    CellLocation nextLoc;    // CellLocation의 nextLoc 객체 선언
    
    
    // 보드 초기화
    for( row=0; row< _this->_order; row++ ) {
        for( col=0; col<_this->_order; col++ ) {
            _this->_board[row][col] = EMPTY_CELL;
        }
    }
    // 보드 채우기
    
    currentLoc._row = 0;    // 맨 윗줄
    currentLoc._col = _this->_order/2;    // 한 가운데 열
    
    int cellValue = 1;
    _this->_board[currentLoc._row][currentLoc._col] = cellValue;   // 보드의 현재 위치에  cellValue를 넣는다.
    int lastCellValue = _this->_order * _this->_order;
    cellValue = 2;
    for( cellValue = 2; cellValue <= lastCellValue; cellValue++ ) { // cellValue가 2부터 (aMagicSquare._order * aMagicSquare._order)까지 증가하며 내용 반복
        
        // 현재 위치로부터 다음 위치인 오른쪽 위 위치를 계산한다.
        nextLoc._row = currentLoc._row -1;  // 다음 row = 현재 row - 1
        if( nextLoc._row <0)
            nextLoc._row = _this->_order-1;   // 맨 밑줄 위치로
        
        nextLoc._col = currentLoc._col +1;  // 다음 col = 현재 col + 1
        if( nextLoc._col >= _this->_order )
            nextLoc._col = 0;   // 가장 왼쪽 열 위치로
        
        
        nextLoc._col = (currentLoc._col+1) % _this->_order ;
        
        // 다음 위치가 채워져 있으면 바로 아래칸을 다음 위치로 수정한다.
        if( _this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL ) {
            nextLoc._row = currentLoc._row+1;
            nextLoc._col = currentLoc._col;
        }
        
        currentLoc = nextLoc;   // 다음 위치를 새로운 현재 위치로 한다.
        _this->_board[currentLoc._row][currentLoc._col] = cellValue;   // 보드의 새로운 현재위치에 cellValue를 넣는다.
    }
}

//객체의 정보를 얻는 함수
int MagicSquare_order( MagicSquare* _this ) {
    return _this->_order;
}

int* MagicSquare_board( MagicSquare* _this ) {
    return (int*) (_this->_board);  // 2차원 배열을 1차원 배열로 생각하도록 (int*)로 자료형을 맞춘다.
}
