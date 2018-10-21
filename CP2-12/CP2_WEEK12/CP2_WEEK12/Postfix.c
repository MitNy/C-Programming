//
//  Postfix.c
//  CP2_WEEK12
//
//  Created by stu2017s10 on 2017. 5. 30..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Postfix.h"
#include "Stack.h"
#include "AppIO.h"
#include <string.h>


struct _Postfix {
    int _maxNumberOfTokens;
    char* _expression;
    int _evaluatedValue;
    Stack* _operandStack;
    AppIO* _appIO;
};

Postfix* Postfix_new(int givenMaxNumberOfTokens) {  // 객체 생성
    Postfix* _this = NewObject(Postfix);
    _this->_maxNumberOfTokens = givenMaxNumberOfTokens;
    _this->_expression = NewVector(char, givenMaxNumberOfTokens);
    _this->_operandStack = Stack_new(givenMaxNumberOfTokens);
    
    return _this;
}

void Postfix_delete(Postfix* _this) {    // 객체 소멸
    Stack_delete(_this->_operandStack);
    free(_this->_expression);
    free(_this);
}

void Postfix_setExpression(Postfix* _this, char* anExpression) {
    //계산할 postfix 수식인 expression[] 을 postfix 객체에 전달
    strcpy(_this->_expression,anExpression);
}

void Postfix_showTokenAndStack(Postfix* _this, char currentToken){    // 스택과 토큰을 보여줌
    printf("%c : Stack <Bottom> ", currentToken);
    for( int i = Stack_size(_this->_operandStack)-1; i>=0; i-- ){
        int stackElement = Stack_elementAt(_this->_operandStack, i);
        printf("%d ", stackElement);
    }
    AppIO_printTop(_this->_appIO);
}

PostfixError Postfix_evaluate(Postfix* _this){   //현재 객체가 가지고 있는 postfix 수식을 계산하도록 지시
    int operand, operand1, operand2, calculated;
    char currentToken;
    int i = 0;
    Stack_reset(_this->_operandStack);
    
    while ( _this->_expression[i] != '\0' ) {
        currentToken = _this->_expression[i];
        if( currentToken >= '0' && currentToken <= '9' ){
            operand = ( currentToken - '0' );
            if( Stack_isFull(_this->_operandStack) ) {
                return PostfixError_ExpressionTooLong;
            }
            else {
                Stack_push(_this->_operandStack, operand);
            }
        }
        
        else {
            if( currentToken == '+') {  // 덧셈
                if(Stack_size(_this->_operandStack) >= 2 ) {
                    operand2 = Stack_pop(_this->_operandStack);
                    operand1 = Stack_pop(_this->_operandStack);
                    calculated = operand1 + operand2;
                    Stack_push(_this->_operandStack, calculated);
                }
                else {
                    return PostfixError_OperandsTooFew;
                }
            }
            else if ( currentToken == '-') {    // 뺄셈
                if(Stack_size(_this->_operandStack) >= 2 ) {
                    operand2 = Stack_pop(_this->_operandStack);
                    operand1 = Stack_pop(_this->_operandStack);
                    calculated = operand1 - operand2;
            
                    Stack_push(_this->_operandStack, calculated);
                }
                else {
                    return PostfixError_OperandsTooFew;
                }
            }
            else if ( currentToken == '*') {    // 곱셈
                if(Stack_size(_this->_operandStack) >= 2 ) {
                    operand2 = Stack_pop(_this->_operandStack);
                    operand1 = Stack_pop(_this->_operandStack);
                    calculated = operand1 * operand2;
                    Stack_push(_this->_operandStack, calculated);
                }
                else {
                    return PostfixError_OperandsTooFew;
                }
            }
            else if( currentToken == '/') { // 나눗셈
                if(Stack_size(_this->_operandStack) >= 2 ) {
                    operand2 = Stack_pop(_this->_operandStack);
                    operand1 = Stack_pop(_this->_operandStack);
                    if( operand2 == 0 ) {
                        return PostfixError_DivideByZero;
                    }
                    calculated = operand1 / operand2;
                    Stack_push(_this->_operandStack, calculated);
                }
                else {
                    return PostfixError_OperandsTooFew;
                }
            }
            else if ( currentToken == '%' ) {   // 나머지 연산
                if(Stack_size(_this->_operandStack) >= 2 ) {
                    operand2 = Stack_pop(_this->_operandStack);
                    operand1 = Stack_pop(_this->_operandStack);

                    calculated = operand1 % operand2;
                    Stack_push(_this->_operandStack, calculated);
                }
                else {
                    return PostfixError_OperandsTooFew;
                }
            }
            else {
                return PostfixError_UnknownOperator;
            }
        }
        Postfix_showTokenAndStack(_this,currentToken);
        i++;
    }// end of while
    if( Stack_size(_this->_operandStack) > 1 ) {
        return PostfixError_OperandsTooMany;
    }
    else if( Stack_size(_this->_operandStack) == 1 ) {
        _this->_evaluatedValue = Stack_pop(_this->_operandStack);
    }
    return PostfixError_None;
    }

int Postfix_evaluatedValue(Postfix* _this){ // 계산된 결과 값을 Postifx 객체로부터 얻는다.
    return (_this->_evaluatedValue);
}
