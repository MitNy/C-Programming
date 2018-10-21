//
//  AppController.c
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#define Esc 27

// 문자 별 행위를 처리
void AppController_add(AppController* _this, char aChar);   // 큐에 원소 삽입
void AppController_removeN(AppController* _this, char aDigit);  // 숫자 입력시 원소 삭제
void AppController_remove1(AppController* _this);   // - 입력시 원소 삭제
void AppController_showSize(AppController* _this); // 큐의 크기를 보여줌
void AppController_showAllFromFront(AppController* _this);  // front부터 큐에 있는 모든 원소를 보여줌
void AppController_showFront(AppController* _this); // front 원소를 보여줌
void AppController_ignore(AppController* _this);   // 의미 없는 문자 무시
void AppController_esc(AppController* _this);  // Esc 입력시 종료

// 행위 별 문자 수를 센다
void AppController_initCharCounts(AppController* _this);    //각 문자 수를 0으로 초기화 시킴
void AppController_countInput(AppController* _this);    // 입력된 문자의 개수를 증가시킴
void AppController_countIgnored(AppController* _this);  // 무시된 문자의 개수를 증가시킴
void AppController_countAdded(AppController* _this);    // 삽입된 문자의 개수를 증가시킴

struct _AppController {
    AppIO* _appIO;
    Queue* _queue;
    int _inputChars;    // 입력된 문자의 개수
    int _ignoredChars;  // 무시된 문자의 개수
    int _addedChars;    // 삽입된 문자의 개수
};

AppController* AppController_new(void) { // 객체 생성
    AppController* _this;
    _this = NewObject(AppController);
    
    _this->_appIO = AppIO_new();
    _this->_queue = Queue_new();
    _this->_inputChars = 0;
    _this->_ignoredChars = 0;
    _this->_addedChars = 0;
    
    return _this;
}

void AppController_delete(AppController* _this){    // 객체 소멸
    Queue_delete(_this->_queue);
    AppIO_delete(_this->_appIO);
    free(_this);
}

void AppController_add(AppController* _this, char aChar) {  // 큐에 원소 삽입
    if( Queue_isFull(_this->_queue)) {
        AppIO_out_msg_queueIsFull(_this->_appIO, aChar);
    }
    else {
        Queue_add(_this->_queue, aChar);
        AppController_countAdded(_this);
        AppIO_out_msg_addedElementInQueue(_this->_appIO,aChar);
    }
}

void AppController_removeN(AppController* _this, char aDigit){
    int numberOfCharsRemoved = aDigit-'0';  // digit 문자를 숫자로
    if( Queue_isEmpty(_this->_queue)) {
        AppIO_out_msg_noElementInQueue(_this->_appIO);
    }
    else {
        numberOfCharsRemoved = Queue_remove(_this->_queue);
        AppIO_out_msg_removedElementFromQueue(_this->_appIO, numberOfCharsRemoved);
    }
}

void AppController_remove1(AppController* _this) {  // 큐에서 원소 삭제
    char removedChar;
    if( Queue_isEmpty(_this->_queue)) {
        AppIO_out_msg_noElementInQueue(_this->_appIO);
    }
    else {
        removedChar = Queue_remove(_this->_queue);
        AppIO_out_msg_removedElementFromQueue(_this->_appIO,removedChar);
    }
}

void AppController_showAllFromFront(AppController* _this) {
    AppIO_out_labelOfFront(_this->_appIO);
    for( int i=0; i< Queue_size(_this->_queue); i++ ) {
        AppIO_out_elementInQueue(_this->_appIO, Queue_elementAt(_this->_queue, i));
    }
    AppIO_out_labelOfRear(_this->_appIO);
}

void AppController_showSize(AppController* _this){ // 큐의 크기를 보여줌
    AppIO_out_msg_queueSize(_this->_appIO, Queue_size(_this->_queue));
}

void AppController_showFront(AppController* _this){ // front 원소를 보여줌
    AppIO_out_FrontInQueue(_this->_appIO, Queue_elementAt(_this->_queue, 0));
}

void AppController_ignore(AppController* _this) {
    AppIO_out_msg_ignoreChars(_this->_appIO);
    AppController_countIgnored(_this);
}
void AppController_initCharCounts(AppController* _this) {   //각 문자 수를 0으로 초기화 시킴
    _this->_inputChars = 0; // 입력된 문자의 개수
    _this->_ignoredChars = 0;  // 무시된 문자의 개수
    _this->_addedChars = 0;   // 삽입된 문자의 개수
}

void AppController_countInput (AppController* _this) {
    _this->_inputChars++; // 입력된 문자의 개수 증가
}

void AppController_countIgnored(AppController* _this){
    _this->_ignoredChars++;  // 무시된 문자의 개수 증가
}

void AppController_countAdded(AppController* _this){
    _this->_addedChars++;   // 삽입된 문자의 개수 증가
}

void AppController_esc(AppController* _this) {  // Esc 입력시 종료
    AppController_removeN(_this, Queue_size(_this->_queue)+'0');
    AppIO_out_msg_numberOfInputChars(_this->_appIO, _this->_inputChars);
    AppIO_out_msg_numberOfNormalChars(_this->_appIO, (_this->_inputChars)-(_this->_ignoredChars));
    AppIO_out_msg_numberOfIgnoredChars(_this->_appIO, _this->_ignoredChars);
    AppIO_out_msg_numberOfAddedChars(_this->_appIO, _this->_addedChars);
}

// 전체 제어
void AppController_run(AppController* _this){
    AppController_initCharCounts(_this);
    
    AppIO_out_msg_startMessage(_this->_appIO);
    
 //   AppIO_out_msg_inputChar(_this->_appIO);
    char inputChar = AppIO_in_nextInputChar(_this->_appIO);
    AppController_countInput(_this);
    
    while( inputChar != Esc ) {
        if( isAlpha(inputChar) ) {
            AppController_add(_this, inputChar);
        }
        else if( isDigit(inputChar)) {
            AppController_removeN(_this, inputChar);
        }
        else if( inputChar == '-' ) {
            AppController_remove1(_this);
        }
        else if( inputChar == '#' ) {
            AppController_showSize(_this);
        }
        else if( inputChar == '/' ) {
            AppController_showAllFromFront(_this);
        }
        else if( inputChar == '^' ) {
            AppController_showFront(_this);
        }
        else {
            AppController_ignore(_this);
        }
        
        inputChar = AppIO_in_nextInputChar(_this->_appIO);
        AppController_countInput(_this);
    }
    AppController_esc(_this);
    
    AppIO_out_msg_endMessage(_this->_appIO);
}
