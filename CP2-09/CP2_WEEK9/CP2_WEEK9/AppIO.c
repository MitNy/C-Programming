//
//  AppIO.c
//  CP2_WEEK9
//
//  Created by stu2017s10 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include "Common.h"
#include "getcharDirectlyFromKeyboard.h"


struct _AppIO {
    
};

AppIO* AppIO_new() {    // 객체 생성
    AppIO* _this = NewObject(AppIO);
    
    return _this;
}

void AppIO_delete(AppIO* _this) {   // 객체 소멸
    free(_this);
}

char AppIO_in_charDirectlyFromKeyboard(AppIO* _this) {  // 문자를 입력 받음
    printf("문자를 입력하시오 : ");
    char charDirectlyFromKeyboard = getcharDirectlyFromKeyboard();
    AppIO_out_newLine(_this);
    
    return charDirectlyFromKeyboard;
}

void AppIO_out_stackIsFullAgainstPush(AppIO* _this, char anElementForPush) { // 스택이 꽉 찼을때 삽입할 경우 삽입이 불가능 하다는 메시지 출력
    printf(" [Push: Full] 스택이 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다. \n", anElementForPush);
}

void AppIO_out_pushedElement(AppIO* _this, char anElement) { // 삽입된 원소 출력
    printf("[Push] 삽입이 된 원소는 \'%c\' 입니다.\n" ,anElement);
}

void AppIO_out_stackIsEmptyAgainstPop1(AppIO* _this) {   // pop할때 스택이 비었을 경우 스택에 삭제할 원소가 없다는 메시지 출력
    printf("[Pop1: Empty] 스택에 삭제할 원소가 없습니다.\n");
}

void AppIO_out_poppedElementByPop1(AppIO* _this,char anElement) {    // pop할 때 삭제된 원소가 무엇인지 출력
    printf("[Pop1] 삭제된 원소는 \'%c\' 입니다.\n" ,anElement);
}

void AppIO_out_beginpops(AppIO* _this, int numberOfElements) {   // 삭제할 원소를 보여줌
    printf("[Pops] %d 개의 원소를 삭제하려고 합니다.\n", numberOfElements);
}

void AppIO_out_endPops(AppIO* _this) {   // 삭제 종료 메시지 출력
    printf("[Pops] 삭제를 종료합니다.\n");
}

void AppIO_out_stackIsEmptyAgainstPops(AppIO* _this) {   //  pop할 때 스택이 비었을 경우 스택에 더 이상 삭제할 원소가 없다는 메시지 출력
    printf("[Pops: Empty] 스택에 더 이상 삭제할 원소가 없습니다.\n");
}

void AppIO_out_topElement(AppIO* _this, char anElement) {    //  top에 있는 원소 출력
    printf("[Top] Top 원소는 \'%c\' 입니다.\n" ,anElement);
}

void AppIO_out_noTopElement(AppIO* _this) {  // top에 원소가 없을 경우 스택이 비어있다는 메시지 출력
    printf("[Top: Empt] 현재 스택은 비어 있습니다.\n");
}

void AppIO_out_bottomOfStack(AppIO* _this) { // <Bottom of Stack> 출력
    printf("<Bottom of Stack> ");
}

void AppIO_out_element(AppIO* _this, char anElement) {   // 원소 출력
    printf("%c ",anElement);
}

void AppIO_out_topOfStack(AppIO* _this) {    // <Top of Stack> 출력
    printf("<Top of Stack>");
}

void AppIO_out_newLine(AppIO* _this) {  // 개행
    printf("\n");
}

void AppIO_out_stackSize(AppIO* _this, int stackSize) {  // 스택의 크기를 출력
    printf("[Size] 현재 스택의 크기는 %d 입니다. \n" , stackSize);
}

void AppIO_out_ignoredChar(AppIO* _this) {   // 의미 없는 문자가 입력되었을 때 메시지 출력
    printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}

void AppIO_out_endInput(AppIO* _this) {  // 입력 종료 및 스택의 모든 원소 삭제
    printf("[End Input] 입력을 종료하며, 스택의 모든 원소를 삭제합니다.\n");
}

void AppIO_out_poppedElementByEndInput(AppIO* _this, char anElement) {   // 삭제된 원소가 무엇인지 출력
    printf(">End Input : 삭제된 원소는 \'%c\' 입니다.\n" ,anElement);
}

void AppIO_out_numberOfInputChars(AppIO* _this, int numberOfChars) { // 입력된 문자의 개수 출력
    printf(">>> 입력된 문자는 모두 %d 개 입니다.\n" ,numberOfChars);
}

void AppIO_out_numberOfNormallyProcessedChars(AppIO* _this, int numberOfChars) {    // 정상적으로 처리된 문자의 개수 출력
    printf(">>> 정상적으로 처리된 문자는 %d 개 입니다.\n" ,numberOfChars);
}

void AppIO_out_numberOfIgnoredChars(AppIO* _this, int numberOfChars) {   // 무시된 문자의 개수 출력
    printf(">>> 무시된 문자는 %d 개 입니다.\n" ,numberOfChars);
}

void AppIO_out_numberOfPushedChars(AppIO* _this, int numberOfChars) {    // 스택에 넣은 문자의 개수 출력
    printf(">>> 스택에 넣은 문자는 %d 개 입니다.\n" ,numberOfChars);
}

void AppIO_out_endProgram(AppIO* _this) {   // 프로그램 종료 메시지 출력
    AppIO_out_newLine(_this);
    printf("> 프로그램을 종료합니다.\n");
}

