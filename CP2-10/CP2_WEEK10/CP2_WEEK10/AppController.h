//
//  AppController.h
//  CP2_WEEK10
//
//  Created by stu2017s10 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include <stdio.h>

#define MAX_NUMBER_OF_TOKENS    200

typedef struct _AppController AppController;

AppController* AppController_new(); // 객체 생성
void AppController_delete(AppController* _this);    // 객체 소멸
void AppController_run(AppController* _this);   // 프로그램 실행


#endif /* AppController_h */
