//
//  Postfix.c
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 31..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Postfix.h"
#include "Stack.h"
#include "AppIO.h"
#include <string.h>

int Postfix_inComingPrecedence(Postfix* _this, char aToken);
int Postfix_inStackPrecedence(Postfix* _this, char aToken);
void Postfix_showOStackAll(Stack* _this);   // OStack을 보여줌
void Postfix_showTokenAndStack(Postfix* _this, char currentToken);

struct _Postfix {
    int _maxNumberOfTokens;
    char* _expression;
    char* _infixExpression;
    int _evaluatedValue;
    Stack* _operandStack;
    AppIO* _appIO;
};

Postfix* Postfix_new(int givenMaxNumberOfTokens) {  // 객체 생성
    Postfix* _this = NewObject(Postfix);
    _this->_maxNumberOfTokens = givenMaxNumberOfTokens;
    _this->_expression = NewVector(char, givenMaxNumberOfTokens);
    _this->_infixExpression = NewVector(char, givenMaxNumberOfTokens);
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
    for( int i=Stack_size(_this->_operandStack)-1; i>=0; i++ ) {
        float Stack = Stack_elementAt(_this->_operandStack, i);
        printf("%.1f ",Stack);
    }
    AppIO_printTop(_this->_appIO);
}

void Postfix_showOStackAll(Stack* _this) {  // OStack을 보여줌
    printf("<OStack> ");
    for( int i= Stack_size(_this)-1; i>=0; i-- ) {
        int Stack = Stack_elementAt(_this, i);
        printf("%c ",Stack);
    }
    printf("\n");
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

void Postfix_setInfix(Postfix* _this, char* newInfix){  // infix 설정자
    _this->_infixExpression = newInfix;
}

Boolean Postfix_infixToPostfix(Postfix* _this){
    // infix -> postfix
    Stack* OStack = Stack_new();
    int i = 0;  // infix
    int p = 0;  // postfix
    char currentToken,poppedToken;
    
    if( _this->_infixExpression != NULL ) {
        while( _this->_infixExpression[i] != '\0' ) {
            currentToken = _this->_infixExpression[i++];
            
            if( isDigit(currentToken)) {
                _this->_expression[p++] = currentToken;
            }
            else {
                if( currentToken == ')' ) {
                    if( !(Stack_isEmpty(OStack))) {
                        poppedToken = Stack_pop(OStack);
                        
                        while( poppedToken != '(' ) {
                            _this->_expression[p++] = poppedToken;
                            poppedToken = Stack_pop(OStack);
                        }
                    }
                    else {
                        return FALSE;
                    }
                }
                else {
                    int postfix_inComing = Postfix_inComingPrecedence(_this, currentToken);
                    
                    if( Stack_top(OStack) != NULL ) {
                        if( Postfix_inStackPrecedence(_this, Stack_peekElement(OStack)) >= postfix_inComing ) {
                            _this->_expression[p++] = Stack_pop(OStack);
                            Stack_push(OStack, currentToken);
                        }
                        else {
                            Stack_push(OStack, currentToken);
                        }
                    }
                    else {
                        Stack_push(OStack, currentToken);
                    }
                }
                Postfix_showOStackAll(OStack);
            }
        }
    }
    else {
        return FALSE;
    }
    while( Stack_top(OStack) != NULL ) {
        _this->_expression[p++] = Stack_pop(OStack);
    }
    return TRUE;
}

char* Postfix_postfix(Postfix* _this){
    return _this->_expression;
}

int Postfix_inComingPrecedence(Postfix* _this, char aToken) {
    // 각 연산자의 입력 토큰 상태의 우선 순위를 돌려준다.
    if( aToken == '(' ) {
        return 20;
    }
    else if( aToken == ')' ) {
        return 19;
    }
    else if( aToken == '^' ) {
        return 17;
    }
    else if( aToken == '*' ) {
        return 13;
    }
    else if( aToken == '/' ) {
        return 13;
    }
    else if( aToken == '%' ) {
        return 13;
    }
    else if( aToken == '+' ) {
        return 12;
    }
    else if( aToken == '-' ) {
        return 12;
    }
    else if( aToken == '$' ) {
        return 0;
    }
    else {
        return -1;
    }
}

int Postfix_inStackPrecedence(Postfix* _this, char aToken) {
    // 각 연산자의 스택 안에서의 우선 순위를 돌려준다.
    if( aToken == '^' ) {
        return 16;
    }
    else if( aToken == '*' ) {
        return 13;
    }
    else if( aToken == '/' ) {
        return 13;
    }
    else if( aToken == '%' ) {
        return 13;
    }
    else if( aToken == '+' ) {
        return 12;
    }
    else if( aToken == '-' ) {
        return 12;
    }
    else if( aToken == '$' ) {
        return 0;
    }
    else {
        return -1;
    }
}


