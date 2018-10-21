//
//  AppController.c
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"

struct _AppController {
    AppIO* _appIO;
    Stack* _stack;
    char _expression[MAX_NUMBER_OF_TOKENS];
    Postfix* _postfix;
};

void AppController_out_postfixEvaluationErrorMessage(AppController* _this,PostfixError aPostfixError);

AppController* AppController_new(){ // 객체 생성
    AppController* _this;
    _this = NewObject(AppController);
    _this->_stack = Stack_new();
    _this->_appIO = AppIO_new();
    
    return _this;
}

void AppController_delete(AppController* _this){    // 객체 소멸
    AppIO_delete(_this->_appIO);
    Stack_delete(_this->_stack);
    free(_this);
}

void AppController_out_postfixEvaluationErrorMessage(AppController* _this,PostfixError aPostfixError) {
    if( aPostfixError == PostfixError_ExpressionTooLong ) {
        AppIO_outLine(_this->_appIO, ErrorMsg_ExpressionTooLong );
    }
    else if( aPostfixError == PostfixError_OperandsTooMany ) {
        AppIO_outLine(_this->_appIO, ErrorMsg_OperandsTooMany);
    }
    else if( aPostfixError == PostfixError_OperandsTooFew ) {
        AppIO_outLine(_this->_appIO, ErrorMsg_OperandsTooFew );
    }
    else if( aPostfixError == PostfixError_UnknownOperator ) {
        AppIO_outLine(_this->_appIO, ErrorMsg_UndefinedOperator);
    }
    else if( aPostfixError == PostfixError_DivideByZero ) {
        AppIO_outLine(_this->_appIO, ErrorMsg_DivideByZero);
    }
}

void AppController_run(AppController* _this) {  //  프로그램 실행
    Boolean nextPostfixExpressionIsAvailable;
    PostfixError evaluationError;
    
    AppIO_out_startingMessage(_this->_appIO);
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
    nextPostfixExpressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO, _this->_expression);
    
    while( nextPostfixExpressionIsAvailable ) {
        Postfix_setExpression(_this->_postfix, _this->_expression);
        evaluationError = Postfix_evaluate(_this->_postfix);
        
        if( evaluationError == PostfixError_None ) {
            AppIO_out_evaluatedValue(_this->_appIO, Postfix_evaluatedValue(_this->_postfix));
        }
        else {
            AppController_out_postfixEvaluationErrorMessage(_this, evaluationError);
        }
        nextPostfixExpressionIsAvailable= AppIO_in_postfixExpression(_this->_appIO, _this->_expression);
       Postfix_delete(_this->_postfix);
    }

    AppIO_out_endingMessage(_this->_appIO);
    
}
