//
//  AppController.c
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "MagicSquare.h"
#include "Common.h"
#include "AppIO.h"

AppController* AppController_new() {    // AppController 객체 생성
    AppController* _this = NewObject(AppController);
    _this->_magicSquare = MagicSquare_new();
    return _this;
}

void AppController_delete(AppController* _this) {   // 더 이상 사용할 필요가 없는 AppController 객체 삭제
    MagicSquare_delete(_this->_magicSquare);
    free(_this);
}

void AppController_showBoard(AppController* _this) {    // 마방진 판을 보여준다
    int order = MagicSquare_order(_this->_magicSquare);
    AppIO_out_boardColumnTitle(order);
    
    for( int row = 0; row<order; row++ ) {
        AppIO_out_boardRowTitle(row);
        for(int col=0; col<order; col++ ) {
            AppIO_out_cell(MagicSquare_cell(_this->_magicSquare,row,col));
        }
        AppIO_out_newLine();    //개행
    }
}

void AppController_run(AppController* _this) {  // app을 실행시킨다.
    AppIO_out_msg_startMagicSquare();
    int order = AppIO_in_order();
    while ( order != END_OF_RUN ) {
        MagicSquare_setOrder(_this->_magicSquare, order);
        
        if (MagicSquare_orderIsValid(_this->_magicSquare)) {
            MagicSquare_solve(_this->_magicSquare);
            AppController_showBoard(_this); // 마방진 판을 보여준다.
        }
        order = AppIO_in_order();
    }
    AppIO_out_msg_endMagicSquare();
}
