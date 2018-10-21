//
//  AppController.h
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include <stdio.h>
#include "MagicSquare.h"

typedef struct {
    MagicSquare* _magicSquare;
} AppController;    // AppController 객체 생성

AppController* AppController_new(); // 객체 생성
void AppController_delete(AppController* _this);   // 더 이상 사용할 필요가 없는 AppController 객체 삭제
void AppController_showBoard(AppController* _this); // 마방진 판을 보여준다.
void AppController_run(AppController* _this); // app을 실행시킨다.

#endif /* AppController_h */
