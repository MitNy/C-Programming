//
//  AppIO.c
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppIO.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

struct _AppIO{
    
};

AppIO* AppIO_new(){ // AppIO 객체 생성
    AppIO* _this = NewObject(AppIO);
    return _this;
}

void AppIO_delete(AppIO* _this){    // 객체 소멸
    free(_this);
}

void AppIO_out_msg_startMessage(AppIO* _this){  // 시작 메시지 출력
    printf(">>> 프로그램을 시작합니다 <<<\n");
}

void AppIO_out_msg_endMessage(AppIO* _this){    //   종료 메시지 출력
    printf("<<< 프로그램을 종료합니다 >>>\n");
}

char AppIO_in_nextInputChar(AppIO* _this) { // 문자를 입력 받음
    printf(">>> 문자를 입력하세오 : ");
    char inputChar = getcharDirectlyFromKeyboard();
    printf("\n");
    return inputChar;
}

char getcharDirectlyFromKeyboard(void) {
    struct termios oldAttr;
    struct termios newAttr;
    char charFromKeyboard;
    
    fpurge(stdin);  // stdin buffer를 비운다
    tcgetattr( STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    charFromKeyboard = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    
    return charFromKeyboard;
    
}
void AppIO_out_msg_queueIsFull(AppIO* _this, char aChar) {   // 큐가 꽉 찼을 때 메시지 출력
    printf("\n[Full] 큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n",aChar);
}

void AppIO_out_msg_addedElementInQueue(AppIO* _this, char aChar) {  // 큐에 원소가 삽입됐을 때 메시지 출력
    printf("\n[Add] 삽입된 원소는 \'%c\' 입니다.\n",aChar);
}

void AppIO_out_msg_noElementInQueue(AppIO* _this) { // 큐가 비었을 때 메시지 출력
    printf("\n[Empty] 큐에 삭제할 원소가 없습니다.\n");
}

void AppIO_out_msg_removedElementFromQueue(AppIO* _this, char aRemovedChar) {    // 큐에서 원소가 삭제됐을 때 메시지 출력
    printf("\n[Remove1] 삭제된 원소는 \'%c\' 입니다. \n", aRemovedChar);
}

void AppIO_out_msg_queueSize(AppIO* _this, int queueSize) {
    printf("\n[Size] 현재 큐의 크기는 %d 입니다.\n",queueSize);
}

void AppIO_out_msg_Esc(AppIO* _this, Element aRemovedChar){ // esc 입력 시 삭제된 원소 출력
    printf("\n[Esc] 삭제된 원소는 \'%c\' 입니다. \n", aRemovedChar);
}
void AppIO_out_msg_ignoreChars(AppIO* _this){   // 의미없는 문자가 입력되었을 때 메시지 출력
    printf("\n[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}
void AppIO_out_FrontInQueue(AppIO* _this, Element aChar){   // front 원소 출력
    printf("\n[Front] Front 원소는 \'%c\' 입니다. \n", aChar);
}
void AppIO_out_labelOfFront(AppIO* _this){  // <Front> 출력
    printf("<Front>");
}

void AppIO_out_labelOfRear(AppIO* _this) {   // <Rear> 출력
    printf("<Rear>\n");
}

void AppIO_out_elementInQueue(AppIO* _this,char anElemet) {
    printf("%c ",anElemet);
}

void AppIO_out_msg_numberOfInputChars(AppIO* _this, int numberOfInputChars){    //  입력된 문자 수 출력
    printf(">>> 입력된 문자는 %d 개 입니다.\n",numberOfInputChars);
}
void AppIO_out_msg_numberOfNormalChars(AppIO* _this, int numberOfNormalChars){ // 정상적으로 처리된 문자 수 출력
    printf(">>> 정상적으로 처리된 문자는 %d 개 입니다.\n",numberOfNormalChars);
}
void AppIO_out_msg_numberOfIgnoredChars(AppIO* _this, int numberOfIgnoredChars){    // 무시된 문자 수 출력
    printf(">>> 무시된 문자는 %d 개 입니다.\n",numberOfIgnoredChars);
}
void AppIO_out_msg_numberOfAddedChars(AppIO* _this, int numberOfAddedChars){   // 삽입 된 문자 수 출력
    printf(">>> 삽입된 문자는 %d 개 입니다.\n",numberOfAddedChars);
}
