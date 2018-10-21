//
//  AppIO.h
//  CP2_WEEK10
//
//  Created by stu2017s10 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Common.h"
#include "Postfix.h"

typedef struct _AppIO AppIO;

AppIO* AppIO_new();    // 객체 생성
void AppIO_delete(AppIO* _this);    // 객체 소멸
Boolean AppIO_in_postfixExpression(AppIO* _this,char* anExpression);   // 수식을 입력받음 , $를 입력받으면 종료
void AppIO_out_errorInExpression (AppIO* _this);   // 수식에 오류가 있을 때 오류 메시지 출력
void AppIO_out_evaluatedValue(AppIO* _this, int anEvaluatedValue);  // 계산값 출력
void AppIO_out_startingMessage(AppIO* _this);  // 시작 메시지 출력
void AppIO_out_endingMessage(AppIO* _this); // 종료 메시지 출력

#endif /* AppIO_h */
