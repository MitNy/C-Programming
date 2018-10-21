//
//  Queue.h
//  CP2_WEEK13
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "Common.h"
#include "Node.h"

typedef struct _Queue Queue;

// Queue 객체의 생성과 소멸
Queue* Queue_new(void);// Queue 객체의 생성
void Queue_delete(Queue* _this);  // Queue  객체 소멸

// Queue 객체의 점검
Boolean Queue_isEmpty(Queue* _this);    // 큐가 empty이면 TRUE,아니면 FALSE
Boolean Queue_isFull(Queue* _this); // 큐가 full 이면 TRUE를, 아니면, FALSE
int Queue_size(Queue* _this);   // 큐의 길이, 즉 큐가 가지고 있는 원소의 개수

// Queue 객체에 지시
Boolean Queue_add(Queue* _this, Element anElement); // 큐의 rear에 item을 삽입
Element Queue_remove(Queue* _this); // 큐의 front에서 Element를 삭제하고 그 값을 얻는다
void Queue_deleteLinkedChain(Queue* _this); // 큐의 크기만큼 삭제
Element Queue_elementAt(Queue* _this, int aPosition);   //큐의 aPosition 번째 원소를 얻는다.

#endif /* Queue_h */
