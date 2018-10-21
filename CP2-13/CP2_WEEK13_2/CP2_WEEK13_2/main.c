//
//  main.c
//  CP2_WEEK13_2
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

// Array Queue
#include <stdio.h>
#include "AppController.h"

int main(void) {
    AppController* appController = AppController_new(); // 객체 생성
    AppController_run(appController);   // 프로그램 실행
    AppController_delete(appController);    // 객체 소멸
    
    return 0;
}
