//
//  main.c
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include <stdio.h>
#include "Common.h"
#include "MagicSquare.h"
#include "Timer.h"
#include "AppController.h"
#include "AppIO.h"

int main() {
    AppController* appController;   // 저장 장소 선언
    appController = AppController_new();    // 객체 생성
    AppController_run(appController);    // app을 실행시킨다.
    AppController_delete(appController);   // 더 이상 사용할 필요가 없는 AppController 객체 삭제
    return 0;
}

