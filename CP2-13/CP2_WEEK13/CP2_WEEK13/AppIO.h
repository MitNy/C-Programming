//
//  AppIO.h
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h
#include "Common.h"
#include "Queue.h"

typedef struct _AppIO AppIO;

AppIO* AppIO_new(); // AppIO 객체 생성
void AppIO_delete(AppIO* _this);    // 객체 소멸
char AppIO_in_nextInputChar(AppIO* _this);   // 문자 입력
char getcharDirectlyFromKeyboard(void); // 키보드에서 문자를 바로 받을 수 있도록 하는 함수
void AppIO_out_msg_startMessage(AppIO* _this);  // 시작 메시지 출력
void AppIO_out_msg_endMessage(AppIO* _this);    //   종료 메시지 출력
void AppIO_out_msg_queueIsFull(AppIO* _this, char aChar);   // 큐가 꽉 찼을 때 메시지 출력
void AppIO_out_msg_addedElementInQueue(AppIO* _this, char aChar);   // 큐에 원소가 삽입됐을 때 메시지 출력
void AppIO_out_msg_noElementInQueue(AppIO* _this);  // 큐가 비었을 때 메시지 출력
void AppIO_out_msg_removedElementFromQueue(AppIO* _this, char aRemovedChar);    // 큐에서 원소가 삭제됐을 때 메시지 출력
void AppIO_out_FrontInQueue(AppIO* _this, Element aChar);   // front 원소 출력
void AppIO_out_msg_queueSize(AppIO* _this, int queueSize);  // queue size return
void AppIO_out_msg_Esc(AppIO* _this, Element aRemovedChar); // esc 입력 시 삭제된 원소 출력
void AppIO_out_msg_ignoreChars(AppIO* _this);   // 의미없는 문자가 입력되었을 때 메시지 출력
void AppIO_out_labelOfFront(AppIO* _this);  // <Front> 출력
void AppIO_out_labelOfRear(AppIO* _this);   // <Rear> 출력
void AppIO_out_elementInQueue(AppIO* _this,char anElemet);  // 큐에 있는 원소 출력

// 처리 후 종료
void AppIO_out_msg_numberOfInputChars(AppIO* _this, int numberOfInputChars);    //  입력된 문자 수 출력
void AppIO_out_msg_numberOfNormalChars(AppIO* _this, int numberOfNormalChars);  // 정상적으로 처리된 문자 수 출력
void AppIO_out_msg_numberOfIgnoredChars(AppIO* _this, int numberOfIgnoredChars);    // 무시된 문자 수 출력
void AppIO_out_msg_numberOfAddedChars(AppIO* _this, int numberOfAddedChars);    // 삽입 된 문자 수 출력

#endif /* AppIO_h */
