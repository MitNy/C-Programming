//
//  AppIO.c
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include "Common.h"

void AppIO_out_newLine(AppIO* _this);
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
    printf(">Postfix 수식을 입력하시오 :");
    scanf("%s",anExpression);
    if( anExpression[0] == '$' ) {
        return FALSE;
    }
    return TRUE;
}
void AppIO_out_errorInExpression (AppIO* _this) {   // 수식에 오류가 있을 때 오류 메시지 출력
    printf(">수식에 오류가 있습니다\n");
}

void AppIO_out_evaluatedValue(AppIO* _this, int anEvaluatedValue) { // 계산값 출력
    printf("계산값 : %d\n",anEvaluatedValue);
}

void AppIO_out_newLine(AppIO* _this) {  // 개행
    printf("\n");
}

void AppIO_out_bottomOfStack(AppIO* _this) {
    printf("<Bottom>");
}


void AppIO_out_startingMessage(AppIO* _this) {  // 시작 메시지 출력
    printf("<Postfix 수식을 계산합니다>\n");
}

void AppIO_out_endingMessage(AppIO* _this) {    // 종료 메시지 출력
    printf("<계산을 종료합니다>\n");
}

void AppIO_out_postfixEvaluationErrorMessage(AppIO* _this, PostfixError aPostfixError) { // 오류 메시지 출력
    if( aPostfixError == PostfixError_ExpressionTooLong) {
        printf(ErrorMsg_ExpressionTooLong); //[오류] 수식이 너무 길어 처리가 불가능합니다
        AppIO_out_newLine(_this);
    }
    else if( aPostfixError == PostfixError_OperandsTooMany ) {
        printf(ErrorMsg_OperandsTooMany);   // [오류] 연산자에 비해 연산값의 수가 많습니다
        AppIO_out_newLine(_this);
    }
    else if( aPostfixError == PostfixError_OperandsTooFew ) {
        printf(ErrorMsg_OperandsTooFew);    // [오류] 연산자에 비해 연산값의 수가 적습니다
        AppIO_out_newLine(_this);
    }
    else if( aPostfixError == PostfixError_UnknownOperator ) {
        printf(ErrorMsg_UndefinedOperator);    // [오류] 수식에 알 수 없는 연산자가 있습니다
        AppIO_out_newLine(_this);
    }
    else if( aPostfixError == PostfixError_DivideByZero ) {
        printf(ErrorMsg_DivideByZero);  // [오류] 나눗셈의 분모가 0 입니다
        AppIO_out_newLine(_this);
    }
}
