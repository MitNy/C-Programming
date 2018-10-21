//
//  AppController.h
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

typedef struct _AppController AppController;

AppController* AppController_new(void);    // AppController 객체 생성
void AppController_delete(AppController* _this);   // AppController 객체 소멸
void AppController_run(AppController* _this);  // App 실행

#endif /* AppController_h */
