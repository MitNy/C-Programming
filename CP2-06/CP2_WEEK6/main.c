//
//  main.c
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "AppController.h"

int main(void) {
    AppController* appController  = AppController_new();    // appController 객체 생성
    AppController_run(appController);   // AppController_run 함수 실행
    AppController_delete(appController);    // appController 객체 소멸
    
    return 0;

}
