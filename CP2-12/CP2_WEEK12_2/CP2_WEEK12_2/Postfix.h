//
//  Postfix.h
//  CP2_WEEK12_2
//
//  Created by stu2017s10 on 2017. 5. 31..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Postfix_h
#define Postfix_h

#include <stdio.h>
#include "Common.h"
typedef struct _Postfix Postfix;

Postfix* Postfix_new(int givenMaxNumberOfTokens);  // 객체 생성
void Postfix_delete(Postfix* _this);    // 객체 소멸
void Postfix_setExpression(Postfix* _this, char* anExpression); //계산할 postfix 수식인 expression[] 을 postfix 객체에 전달
void Postfix_showTokenAndStack(Postfix* _this, char currentToken);
PostfixError Postfix_evaluate(Postfix* _this);   //현재 객체가 가지고 있는 postfix 수식을 계산하도록 지시
int Postfix_evaluatedValue(Postfix* _this); // 계산된 결과 값을 Postifx 객체로부터 얻는다.
void Postfix_setInfix(Postfix* _this, char* newInfix); // Postfix 객체에게 infix 수식을 전달
Boolean Postfix_infixToPostfix(Postfix* _this); // Postfix 객체가 가지고 있는 infix 수식을 postfix 수식으로 변환할 것을 Postfix 객체에게 시킨다
char* Postfix_postfix(Postfix* _this);  // 변환된 postfix 수식을 얻는다.

#endif /* Postfix_h */
