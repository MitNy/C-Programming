//
//  AppIO.h
//  CP2_WEEK9
//
//  Created by stu2017s10 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

typedef struct _AppIO   AppIO;

AppIO* AppIO_new(); // 객체 생성
void AppIO_delete(AppIO* _this);    // 객체 소멸
char AppIO_in_charDirectlyFromKeyboard(AppIO* _this);   // 문자를 입력 받음
void AppIO_out_stackIsFullAgainstPush(AppIO* _this, char anElementForPush); // 스택이 꽉 찼을때 삽입할 경우 삽입이 불가능 하다는 메시지 출력
void AppIO_out_pushedElement(AppIO* _this, char anElement); // 삽입된 원소 출력
void AppIO_out_stackIsEmptyAgainstPop1(AppIO* _this);   // pop할때 스택이 비었을 경우 스택에 삭제할 원소가 없다는 메시지 출력
void AppIO_out_poppedElementByPop1(AppIO* _this,char anElement);    // pop할 때 삭제된 원소가 무엇인지 출력
void AppIO_out_beginpops(AppIO* _this, int numberOfElements);   // 삭제할 원소를 보여줌
void AppIO_out_endPops(AppIO* _this);   // 삭제 종료 메시지 출력
void AppIO_out_stackIsEmptyAgainstPops(AppIO* _this);   //  pop할 때 스택이 비었을 경우 스택에 더 이상 삭제할 원소가 없다는 메시지 출력
void AppIO_out_topElement(AppIO* _this, char anElement);    //  top에 있는 원소 출력
void AppIO_out_noTopElement(AppIO* _this);  // top에 원소가 없을 경우 스택이 비어있다는 메시지 출력
void AppIO_out_bottomOfStack(AppIO* _this); // <Bottom of Stack> 출력
void AppIO_out_element(AppIO* _this, char anElement);   // 원소 출력
void AppIO_out_topOfStack(AppIO* _this);    // <Top of Stack> 출력
void AppIO_out_newLine(AppIO* _this);   // 개행
void AppIO_out_stackSize(AppIO* _this, int stackSize);  // 스택의 크기를 출력
void AppIO_out_ignoredChar(AppIO* _this);   // 의미 없는 문자가 입력되었을 때 메시지 출력
void AppIO_out_endInput(AppIO* _this);  // 입력 종료 및 스택의 모든 원소 삭제
void AppIO_out_poppedElementByEndInput(AppIO* _this, char anElement);   // 삭제된 원소가 무엇인지 출력

void AppIO_out_numberOfInputChars(AppIO* _this, int numberOfChars); // 입력된 문자의 개수 출력
void AppIO_out_numberOfNormallyProcessedChars(AppIO* _this, int numberOfChars); // 정상적으로 처리된 문자의 개수 출력
void AppIO_out_numberOfIgnoredChars(AppIO* _this, int numberOfChars);   // 무시된 문자의 개수 출력
void AppIO_out_numberOfPushedChars(AppIO* _this, int numberOfChars);    // 스택에 넣은 문자의 개수 출력
void AppIO_out_endProgram(AppIO* _this);    // 프로그램 종료 메시지 출력

#endif /* AppIO_h */
