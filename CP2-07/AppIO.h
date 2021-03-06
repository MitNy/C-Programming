//
//  AppIO.h
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Common.h"
#include "Student.h"

typedef struct _AppIO AppIO ;

AppIO* AppIO_new(); // 객체 생성
void AppIO_delete(AppIO* _this);    // 객체 소멸

// 출력을 위한 공개 함수
void AppIO_out_msg_startScoreProcessing (AppIO* _this); // 성적 처리 시작 메시지 출력
void AppIO_out_msg_endScoreProcessing (AppIO* _this);   // 성적 처리 종료 메시지 출력
void AppIO_out_msg_noStudentFromInput (AppIO* _this);   // 학생 정보가 입력되지 않았을 때 오류메시지 출력
void AppIO_out_msg_errorInInputStudentInfo (AppIO* _this);  // 입력된 성적이 0보다 작거나 100보다 클 때 오류 메시지 출력
void AppIO_out_msg_invalidScore(AppIO* _this,int aScore);   // 성적이 0보다 작거나 클 때 오류메시지 출력
void AppIO_out_msg_invalidStudentID(AppIO* _this,char* aStudentID, int maxLength ); // 학번이 maxLength보다 클때 오류 메시지 출력
void AppIO_in_studentID(AppIO* _this,char* aStudentID); // 학번을 입력 받음

void AppIO_out_averageScore (AppIO* _this, float anAverageScore); // 평균 점수 출력
void AppIO_out_numberOfStudentsAboveAverage (AppIO* _this, int aNumber);    // 평균 이상인 학생 수 출력
void AppIO_out_maxScore (AppIO* _this, int aMaxScore);  // 최고점 출력
void AppIO_out_minScore (AppIO* _this, int aMinScore);  // 최저점 출력
void AppIO_out_gradeCountFor (AppIO* _this, char aGrade, int aCount);   // 학점 별 학생 수 출력
void AppIO_out_titleForSortedStudentList (AppIO* _this);    // 성적순 목록 출력 안내 메시지
void AppIO_out_studentInfo (AppIO* _this,char* aStudentID, int aScore, char aGrade);    // 학번, 점수, 학점 출력

char getcharDirectlyFromKeyboard (void);   // keyboard에서 직접 문자 입력 받기

// 입력을 위한 공개 함수
Boolean AppIO_in_doesContinueToInputNextStudent (AppIO* _this); // 성적을 입력 받음
int AppIO_in_score (AppIO* _this);  // 점수를 입력 받음

#endif /* AppIO_h */
