//
//  main.c
//  CP2_WEEK12
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "AppIO.h"
#include "AppController.h"
#include "Common.h"

int main() {
    AppController* appController =  AppController_new();    // 객체 생성
    AppController_run(appController);   // 프로그램 실행
    AppController_delete(appController);    // 객체 소멸
}
