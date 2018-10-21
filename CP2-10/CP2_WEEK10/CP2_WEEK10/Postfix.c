//
//  Postfix.c
//  CP2_WEEK10
//
//  Created by stu2017s10 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Postfix.h"
#include "Stack.h"
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

    printf("%c : Stack <Bottom> ",currentToken);
    for( int i=0; i<Stack_size(_this->_operandStack); i++ ) {
        int Stack = Stack_elementAt(_this->_operandStack, i);
        printf("%d ",Stack);
    }
    
    printf("<Top>\n");
}

Boolean Postfix_evaluate(Postfix* _this){   //현재 객체가 가지고 있는 postfix 수식을 계산하도록 지시
    int operand, operand1, operand2, calculated;
    char currentToken;
    int i = 0;
    Stack_reset(_this->_operandStack);
    
    while (_this->_expression[i] != '\0') {
        currentToken = _this->_expression[i];
        if( currentToken >= '0' && currentToken <= '9') {
            operand = (currentToken-'0');
            Stack_push(_this->_operandStack, operand);
        }

        else {
            if( currentToken == '+') {  // 덧셈
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 + operand2;
                Stack_push(_this->_operandStack, calculated);
            }
            else if ( currentToken == '-') {    // 뺄셈
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 - operand2;
                Stack_push(_this->_operandStack, calculated);
            }
            else if ( currentToken == '*') {    // 곱셈
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 * operand2;
                Stack_push(_this->_operandStack, calculated);
            }
            else if( currentToken == '/') { // 나눗셈
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 / operand2;
                Stack_push(_this->_operandStack, calculated);
            }
            else if ( currentToken == '%' ) {   // 나머지 연산
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 % operand2;
                Stack_push(_this->_operandStack, calculated);
            }
            
        }
        Postfix_showTokenAndStack(_this,currentToken);
        i++;
    }// end of while
    _this->_evaluatedValue = Stack_pop(_this->_operandStack);
    return TRUE;
}

int Postfix_evaluatedValue(Postfix* _this){ // 계산된 결과 값을 Postifx 객체로부터 얻는다.
    return (_this->_evaluatedValue);
}
