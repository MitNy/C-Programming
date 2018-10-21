//
//  AppIO.c
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"

struct _AppIO {
    
};

AppIO* AppIO_new(void) {    //AppIO 객체 생성
    AppIO* _this = NewObject(AppIO);
    
    return _this;
}

void AppIO_delete(AppIO* _this) {   // AppIO 객체 소멸
    free(_this);
}

void AppIO_out_message(AppIO* _this,char* aMessage) {   // 메시지 출력
    printf("%s",aMessage);
}
