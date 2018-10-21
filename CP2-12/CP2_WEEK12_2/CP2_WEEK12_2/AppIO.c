
//
//  AppIO.c
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"


void AppIO_out_bottomOfStack(AppIO* _this);

struct _AppIO {
    
};

AppIO* AppIO_new() {    // 객체 생성
    AppIO* _this = NewObject(AppIO);
    
    return _this;
}

void AppIO_delete(AppIO* _this) {   // 객체 소멸
    free(_this);
}

Boolean AppIO_in_postfixExpression(AppIO* _this,char* anExpression) {   // 수식을 입력받음 , $를 입력받으면 종료
    printf(">infix 수식을 입력하시오 :");
    scanf("%s",anExpression);
    if( anExpression[0] == '$' ) {
        return FALSE;
    }
    return TRUE;
}
void AppIO_out_errorInExpression (AppIO* _this) {   // 수식에 오류가 있을 때 오류 메시지 출력
    printf(">수식에 오류가 있습니다\n");
}

void AppIO_out_evaluatedValue(AppIO* _this, int anEvaluatedValue) {  // 계산값 출력
    printf("계산값 : %d\n",anEvaluatedValue);
}

void AppIO_out_newLine(AppIO* _this) {  // 개행
    printf("\n");
}

void AppIO_out_bottomOfStack(AppIO* _this) {    // <Bottom> 출력
    printf("<Bottom>");
}


void AppIO_out_startingMessage(AppIO* _this) {  // 시작 메시지 출력
    printf("<Postfix 수식을 계산합니다>\n");
}

void AppIO_out_endingMessage(AppIO* _this) { // 종료 메시지 출력
    printf("<계산을 종료합니다>\n");
}

void AppIO_printTop(AppIO* _this) { // <Top> 출력
    printf("<Top>\n");
}

void AppIO_outLine(AppIO* _this,char* aMessage){    // 오류 메시지 출력
    printf("%s\n",aMessage);
}
