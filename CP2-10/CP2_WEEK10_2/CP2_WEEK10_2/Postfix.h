//
//  Postfix.h
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
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
void Postfix_showTokenAndStack(Postfix* _this, char currentToken);  // 스택과 토큰을 보여줌
PostfixError Postfix_evaluate(Postfix* _this);   //현재 객체가 가지고 있는 postfix 수식을 계산하도록 지시
int Postfix_evaluatedValue(Postfix* _this); // 계산된 결과 값을 Postifx 객체로부터 얻는다.

#endif /* Postfix_h */
