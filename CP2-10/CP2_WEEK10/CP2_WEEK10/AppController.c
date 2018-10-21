//
//  AppController.c
//  CP2_WEEK10
//
//  Created by stu2017s10 on 2017. 5. 16..
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
    Boolean expressionIsAvailable, noErrorIsInEvaluation;
    
    AppIO_out_startingMessage(_this->_appIO);
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
    expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO,_this->_expression);
    while( expressionIsAvailable ) {
        Postfix_setExpression(_this->_postfix,_this->_expression);
        noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
        
        if( ! noErrorIsInEvaluation ) {
            AppIO_out_errorInExpression(_this->_appIO);
        }
        else {
            AppIO_out_evaluatedValue(_this->_appIO,Postfix_evaluatedValue(_this->_postfix));
        }
        expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO,_this->_expression);
        
    }
    Postfix_delete(_this->_postfix);
    AppIO_out_endingMessage(_this->_appIO);
}
