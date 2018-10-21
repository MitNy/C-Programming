//
//  AppController.h
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include <stdio.h>
#include "AppIO.h"
#include "Common.h"
#include "Ban.h"
#define MAX_NUMBER_OF_STUDENTS  100

typedef struct _AppController AppController;

// 학생들의 정보를 입력 받아 Ban 객체에 저장한다.
// 저장이 정상적으로 이뤄지지 않으면 더 이상 입력 받지 않음
Boolean AppController_inputAndStoreStudents( AppController* _this); // 학생들의 정보를 입력 받아 Ban 객체에 저장한다.
Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore);    // 입력이 유효한지 검사
AppController* AppController_new(void); // 객체 생성
void AppController_showStatistics(AppController* _this);    // 평균 점수,평균 이상인 학생 수, 최고점, 최저점 출력
void AppController_showStudentsSortedByScore (AppController* _this);    // 학생 정보 정렬
void AppController_delete(AppController* _this);    // 객체 소멸
void AppController_run(AppController* _this);   // 성적 처리 실행

#endif /* AppController_h */
