//
//  AppController.h
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include "AppIO.h"
#include "Common.h"
#include "Queue.h"

typedef struct _AppController AppController;

AppController* AppController_new(void); // 객체 생성
void AppController_delete(AppController* _this);    // 객체 소멸
// 전체 제어
void AppController_run(AppController* _this);   // 프로그램 실행

#endif /* AppController_h */
