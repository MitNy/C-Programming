//
//  AppIO.h
//  CP2_WEEK11
//
//  Created by stu2017s10 on 2017. 5. 23..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Message.h"
#include "Common.h"

typedef struct _AppIO   AppIO;

AppIO* AppIO_new(void);    // AppIO 객체 생성
void AppIO_delete(AppIO* _this);   // 주어진 AppIO 객체 소멸시킴
void AppIO_out_message(AppIO* _this, char* aMessage);  // 주어진 메시지 문자열 aMessage출력


#endif /* AppIO_h */
