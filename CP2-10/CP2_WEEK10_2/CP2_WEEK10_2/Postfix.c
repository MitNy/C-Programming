//
//  Postfix.c
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Postfix.h"
#include "Stack.h"
#include "AppIO.h"
#include "Common.h"
#include "MessageKOR_PostfixError.h"
#include <string.h>


struct _Postfix {
    int _maxNumberOfTokens;
    char* _expression;
    int _evaluatedValue;
    Stack* _operandStack;
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

void Postfix_showTokenAndStack(Postfix* _this, char currentToken) {
    // 스택과 토큰을 보여줌

    printf("%c : Stack <Bottom> ",currentToken);
    for( int i=0; i<Stack_size(_this->_operandStack); i++ ) {
        int Stack = Stack_elementAt(_this->_operandStack, i);
        printf("%d ",Stack);
    }
    
    printf("<Top>\n");
}

PostfixError Postfix_evaluate(Postfix* _this){   //현재 객체가 가지고 있는 postfix 수식을 계산하도록 지시
    int operand, operand1, operand2, calculated;
    char currentToken;
    int i = 0;
    Stack_reset(_this->_operandStack);
    
    while (_this->_expression[i] != '\0') {
        currentToken = _this->_expression[i];
        if( currentToken >= '0' && currentToken <= '9') {
            operand = (currentToken-'0');
            if( Stack_isFull(_this->_operandStack)) {
                return PostfixError_ExpressionTooLong;
            }
            else {
            Stack_push(_this->_operandStack, operand);
            }
        }
        
        else {
            if( currentToken == '+') {  // 덧셈
                if( Stack_size(_this->_operandStack) >= 2 ) {
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 + operand2;
                Stack_push(_this->_operandStack, calculated);
                // 2개 pop 했으므로, 스택에 하나 push 할 여유는 있으므로 isFull 검사 불필요
                }
                else {
                    // [오류] 연산자에 비해 연산값의 수가 많습니다.
                    return PostfixError_OperandsTooMany;
                }
            }
            else if ( currentToken == '-') {    // 뺄셈
                if( Stack_size(_this->_operandStack) >= 2 ) {
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 - operand2;
                Stack_push(_this->_operandStack, calculated);
            }
                else {
                    // [오류] 연산자에 비해 연산값의 수가 많습니다.
                    return PostfixError_OperandsTooMany;
                }
            }
            else if ( currentToken == '*') {    // 곱셈
                if( Stack_size(_this->_operandStack) >= 2 ) {
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 * operand2;
                Stack_push(_this->_operandStack, calculated);
                }
                else {
                    // [오류] 연산자에 비해 연산값의 수가 많습니다.
                    return PostfixError_OperandsTooMany;
                }
            }
            else if( currentToken == '/') { // 나눗셈
                if( Stack_size(_this->_operandStack) >= 2 ) {
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                    if( operand2 == 0 ) {
                        return PostfixError_DivideByZero;
                    }
                calculated = operand1 / operand2;
                Stack_push(_this->_operandStack, calculated);
            }
                else {
                    // [오류] 연산자에 비해 연산값의 수가 많습니다.
                    return PostfixError_OperandsTooMany;
                }
            }
            else if ( currentToken == '%' ) {   // 나머지 연산
                if( Stack_size(_this->_operandStack) >= 2 ) {
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 % operand2;
                Stack_push(_this->_operandStack, calculated);
            }
                else {

                    // [오류] 연산자에 비해 연산값의 수가 많습니다.
                    return PostfixError_OperandsTooMany;
                }
            }
            else {
                // [오류] 수식에 알 수 없는 연산자가 있습니다.
                return PostfixError_UnknownOperator;
            }
        
        }
        Postfix_showTokenAndStack(_this,currentToken);
        i++;
    }   // end of while
    if( Stack_size(_this->_operandStack) == 1 ) {
        // the result is on top of stack
        _this->_evaluatedValue = Stack_pop(_this->_operandStack);
    }
    else if ( Stack_size(_this->_operandStack) > 1 ) {
        // [오류] 연산자에 비해 연산값의 수가 적습니다.
        return PostfixError_OperandsTooFew;
    }
    return PostfixError_None;   //  오류 없음. 성공적으로 계산 완료
}

int Postfix_evaluatedValue(Postfix* _this){ // 계산된 결과 값을 Postifx 객체로부터 얻는다.
    return (_this->_evaluatedValue);
}
