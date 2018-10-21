//
//  AppController.c
//  CP2_WEEK9
//
//  Created by stu2017s10 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "Common.h"
#include "AppIO.h"
#include "Stack.h"

#define Esc 27

// 비공개 함수
// 문자 별로 해야 할 일들
void AppController_push(AppController* _this, char anElement);  // 스택에 원소를 넣음
void AppController_pops(AppController* _this, int numberOfElements);    // 스택에서 원소를 꺼내고 삭제
void AppController_pop1(AppController* _this);  // 스택에서 원소를 꺼내고 삭제
void AppController_showSize(AppController* _this);  // 스택의 크기를 보여줌
void AppController_showAllFromBottom(AppController* _this); // 스택의 아래에서부터 원소를 보여줌
void AppController_showAllFromTop(AppController* _this);    // 스택의 위에서부터 원소를 보여줌
void AppController_showTopElement(AppController* _this);    // 스택의 top에 있는 원소를 보여줌
void AppController_ignore(AppController* _this);    // 무시되는 원소를 검사하고 개수 증가
void AppController_endInput(AppController* _this);  // 입력 종료
void AppController_endProgram(AppController* _this);    // 프로그램 종료

// 각 행위 실행 횟수 세기
void AppController_initCountingChars(AppController* _this);    // 각 문자의 개수를 초기화
void AppController_countInputChars(AppController* _this);   // 입력된 원소 개수 count
void AppController_countIgnoredChars(AppController* _this); // 무시된 원소 개수 count
void AppController_countPushedChars(AppController* _this);  // 스택에 저장된 원소 개수 count

// 각 실행 횟수 얻기
int AppController_numberOfInputChars(AppController* _this); // 입력된 원소 개수를 얻음
int AppController_numberOfIgnoredChars(AppController* _this);   // 무시된 원소 개수를 얻음
int AppController_numberOfNormallyProcessedChars(AppController* _this); // 정상적으로 처리된 원소 개수를 얻음
int AppController_numberOfPushedChars(AppController* _this);    // 스택에 저장된 원소의 개수를 얻음

struct _AppController {
    AppIO* _appIO;
    Stack* _stack;
    int _inputChars;    // 입력된 문자의 개수
    int _ignoredChars;  // 무시된 문자의 개수
    int _pushedChars;   // 스택에 넣은 문자의 개수
};

AppController* AppController_new() {    // 객체 생성
    AppController* _this;
    _this = NewObject(AppController);
    _this->_stack = Stack_new();
    _this->_appIO = AppIO_new();
    
    return _this;
}

void AppController_delete(AppController* _this) {   // 객체 소멸
    AppIO_delete(_this->_appIO);
    Stack_delete(_this->_stack);
    
    free(_this);
}

void AppController_push(AppController* _this, char anElement){  // 스택에 원소를 넣음
    if( Stack_isFull (_this->_stack)) {
        AppIO_out_stackIsFullAgainstPush(_this->_appIO, anElement);
    }
    else {
        Stack_push(_this->_stack, anElement);
        AppController_countPushedChars(_this);
        AppIO_out_pushedElement(_this->_appIO, anElement);
    }
}

void AppController_pops(AppController* _this, int numberOfElements) {   // 스택에서 원소를 꺼내고 삭제
    AppIO_out_beginpops(_this->_appIO, numberOfElements);
    for( int i=0; (i<numberOfElements) && (!Stack_isEmpty(_this->_stack)); i++ ) {
        char poppedChar = Stack_pop(_this->_stack);
        AppIO_out_poppedElementByPop1(_this->_appIO, poppedChar);
    }
    if(Stack_isEmpty(_this->_stack)) {
        AppIO_out_stackIsEmptyAgainstPops(_this->_appIO);
    }
    else {
        AppIO_out_endPops(_this->_appIO);
    }
}

void AppController_pop1(AppController* _this) {   // 스택에서 원소를 꺼내고 삭제
    if( Stack_isEmpty(_this->_stack)) {
        AppIO_out_stackIsEmptyAgainstPop1(_this->_appIO);
    }
    else {
        char poppedChar = Stack_pop(_this->_stack);
        AppIO_out_poppedElementByPop1(_this->_appIO, poppedChar);
    }
}

void AppController_showSize(AppController* _this) {  // 스택의 크기를 보여줌
    int size = Stack_size(_this->_stack);
    AppIO_out_stackSize(_this->_appIO, size);
}

void AppController_showAllFromBottom(AppController* _this) { // 스택의 아래에서부터 원소를 보여줌
    // App 사용자는 스택의 내용에 직접 접근 불가
    
    char stackElement;
    AppIO_out_bottomOfStack(_this->_appIO);
    for( int i=0; i<Stack_size(_this->_stack); i++ ) {
        stackElement = Stack_elementAt(_this->_stack, i);
        AppIO_out_element(_this->_appIO, stackElement);
    }
    AppIO_out_topOfStack(_this->_appIO);
    AppIO_out_newLine(_this->_appIO);
}

void AppController_showAllFromTop(AppController* _this) {    // 스택의 위에서부터 원소를 보여줌
    char stackElement;
    AppIO_out_topOfStack(_this->_appIO);
    for( int i=0; i<Stack_size(_this->_stack); i++ ) {
        stackElement = Stack_elementAt(_this->_stack, i);
        AppIO_out_element(_this->_appIO, stackElement);
    }
    AppIO_out_bottomOfStack(_this->_appIO);
    AppIO_out_newLine(_this->_appIO);
}

void AppController_showTopElement(AppController* _this) {    // 스택의 top에 있는 원소를 보여줌
    char stackElement;
    stackElement = Stack_topElement(_this->_stack);
    AppIO_out_topElement(_this->_appIO, stackElement);
}

void AppController_ignore(AppController* _this) {   // 무시되는 원소를 검사하고 개수 증가
    AppIO_out_ignoredChar(_this->_appIO);
    AppController_countIgnoredChars(_this);
}

void AppController_endInput(AppController* _this) {  // 입력 종료
    AppIO_out_endInput(_this->_appIO);
    char stackElement;
    for(int i = Stack_size(_this->_stack)-1; i>=0; i--){
        stackElement = Stack_elementAt(_this->_stack, i);
        AppIO_out_poppedElementByEndInput(_this->_appIO, stackElement);
    }
}
void AppController_endProgram(AppController* _this) {    // 프로그램 종료
    AppIO_out_endProgram(_this->_appIO);
}

void AppController_initCountingChars(AppController* _this) {    // 각 문자의 개수를 초기화
    _this->_inputChars = 0;
    _this->_ignoredChars = 0;
    _this->_pushedChars = 0;
}

void AppController_countInputChars(AppController* _this) {   // 입력된 원소 개수 count
    _this->_inputChars++;
}

void AppController_countIgnoredChars(AppController* _this) { // 무시된 원소 개수 count
    _this->_ignoredChars++;
}
void AppController_countPushedChars(AppController* _this) {  // 스택에 저장된 원소 개수 count
    _this->_pushedChars++;
}

// 통계 정보 얻기
int AppController_numberOfInputChars(AppController* _this) { // 입력된 원소 개수를 얻음
    return (_this->_inputChars);
}
int AppController_numberOfIgnoredChars(AppController* _this) {   // 무시된 원소 개수를 얻음
    return (_this->_ignoredChars);
}
int AppController_numberOfNormallyProcessedChars(AppController* _this) { // 정상적으로 처리된 원소 개수를 얻음
    return (_this->_inputChars - _this->_ignoredChars);
}
int AppController_numberOfPushedChars(AppController* _this) {    // 스택에 저장된 원소의 개수를 얻음
    return (_this->_pushedChars);
}

// 통계 정보 출력
void AppController_showStatistics(AppController* _this) {
    AppIO_out_newLine(_this->_appIO);
    
    AppIO_out_numberOfInputChars(_this->_appIO, AppController_numberOfInputChars(_this));
    AppIO_out_numberOfNormallyProcessedChars(_this->_appIO, AppController_numberOfNormallyProcessedChars(_this));
    AppIO_out_numberOfIgnoredChars(_this->_appIO, AppController_numberOfIgnoredChars(_this));
    AppIO_out_numberOfPushedChars(_this->_appIO, AppController_numberOfPushedChars(_this));
}

void AppController_run(AppController* _this){   // 프로그램 실행
    char c;
    AppController_initCountingChars(_this);
    c = AppIO_in_charDirectlyFromKeyboard(_this->_appIO);
    
    while(c != Esc){
        AppController_countInputChars(_this);
        if( isAlpha(c) ){
            AppController_push(_this, c);
        }
        else if( isDigit(c)) {
            int digitValue = c - '0';
            AppController_pops(_this, digitValue);
        }
        else if(c == '-'){
            AppController_pop1(_this);
        }
        else if(c == '#'){
            AppController_showSize(_this);
        }
        else if(c == '/'){
            AppController_showAllFromBottom(_this);
        }
        else if(c == '\\'){
            AppController_showAllFromTop(_this);
        }
        else if(c == '^'){
            AppController_showTopElement(_this);
        }
        else {
            AppController_ignore(_this);
        }
        c = AppIO_in_charDirectlyFromKeyboard(_this->_appIO);
    }
    AppController_endInput(_this);
    
    AppController_showStatistics(_this);
    AppController_endProgram(_this);
}
