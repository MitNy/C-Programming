//
//  AppIO.c
//  CP2_WEEK8_1
//
//  Created by stu2017s10 on 2017. 4. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include "Common.h"

struct _AppIO{
    // 이곳에 선언할 감추어진 속성이 없음
};

AppIO* AppIO_new(){    // AppIO 객체 생성
    AppIO* _this = NewObject(AppIO);
    
    return _this;
}

void AppIO_delete(AppIO* _this){  // 주어진 AppIO 객체 소멸시킴
    free(_this);
}

void AppIO_out_message(AppIO* _this, char* aMessage){  // 주어진 메시지 문자열 aMessage출력
    printf("%s", aMessage);
}
