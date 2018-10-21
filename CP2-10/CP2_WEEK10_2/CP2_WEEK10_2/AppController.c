//
//  AppController.c
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "Common.h"
#include "AppIO.h"
#include "Postfix.h"
#include "Stack.h"

void AppController_showAllFromBottom(AppController* _this);

struct _AppController {
    AppIO* _appIO;
    Stack* _stack;
    char _expression[MAX_NUMBER_OF_TOKENS];
    Postfix* _postfix;
};

AppController* AppController_new() {    // 객체 생성
    AppController* _this;
    _this = NewObject(AppController);
    _this->_stack = Stack_new();
    _this->_appIO = AppIO_new();
    
    return _this;
}

void AppController_delete(AppController* _this) {   // 객체 소멸
    AppIO_delete(_this->_appIO);
    Stack_delete(_this->_stack);
    
    free(_this);
}

void AppController_run(AppController* _this){   // 프로그램 실행
    Boolean expressionIsAvailable;
    PostfixError evaluationError;
    
    AppIO_out_startingMessage(_this->_appIO);   // 시작 메시지 출력
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
    expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO,_this->_expression);
    while( expressionIsAvailable ) {
        Postfix_setExpression(_this->_postfix,_this->_expression);
        evaluationError = Postfix_evaluate(_this->_postfix);
        
        if( evaluationError == PostfixError_None ) {
           AppIO_out_evaluatedValue(_this->_appIO,Postfix_evaluatedValue(_this->_postfix));
        }
        else {
            AppIO_out_postfixEvaluationErrorMessage(_this->_appIO, evaluationError);
        }
        expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO,_this->_expression);
        
    }
    Postfix_delete(_this->_postfix);
    AppIO_out_endingMessage(_this->_appIO);
}
