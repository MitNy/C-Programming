//
//  Ban.h
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//


#ifndef Ban_h
#define Ban_h

#define DEFAULT_MAX_SIZE    100
#include <stdio.h>
#include "Common.h"
#include "GradeCounter.h"
#include "Student.h"

typedef struct _Ban Ban;

Ban* Ban_new(void); // 객체 생성자
Ban* Ban_newWithCapacity(int givenCapacity);    // 최대 학생 수 설정 및 초기 학생수 설정
Boolean Ban_scoreIsValid(int aScore);     // 점수가 0보다 작거나 큰지 검사
char Ban_scoreToGrade(int aScore);  //  // 점수별 학점
void Ban_delete(Ban* _this);    // 객체 소멸자

// Ban객체의 상태 알아보기
int Ban_maxSize(Ban* _this);    // 학급 객체가 가질 수 있는 최대 학생 수를 얻어 알아낸다.
int Ban_size(Ban* _this);   // 학급 객체가 가지고 있는 학생 수를 얻어 알아낸다.
Boolean Ban_isEmpty(Ban* _this);    //현재 가지고 있는 학생이 없으면 TRUE, 없으면 FALSE 를 얻는다.
Boolean Ban_isFull(Ban* _tihs); // 현재 학생을 더 이상 저장할 공간이 없으면 TRUE, 아직 여유가 있으면 FALSE를 얻는다.

// 학생 개인 정보 입력 받아 저장
// 정상적으로 성적이 저장되었으면 TRUE, 아니면 즉 저장공간이 모자라면 FALSE를 return 값으로 돌려 받는다.
Boolean Ban_add(Ban* _this,Student* aStudent);

// Ban에 저장된 원소 얻어내기
Student* Ban_elementAt(Ban* _this,int anOrder);

// 학생 정보 정렬(성적 순)
void Ban_quickSort (Ban* _this);
void Ban_sortStudentsByScore(Ban* _this);   // 객체에 저장된 학생들의 성적을 성적 순으로 정렬시킨다.
void Ban_quickSortRecursively(Ban* _this,int left, int right);  // 퀵 정렬
int Ban_partition(Ban* _this, int left, int right); // 원소들을 특정 값을 기준으로 두 부분으로 나눈다.

float Ban_averageScore(Ban* _this); // 평균을 계산하여 return 값으로 돌려준다.
int Ban_maxScore(Ban* _this);   // 최고점을 찾아서 return 값으로 돌려준다
int Ban_minScore(Ban* _this);   // 최저점을 찾아서 return 값으로 돌려준다.

//재귀함수로 구현
int Ban_sumOfScoreRecursively(Ban* _this,int left, int right);   // 성적 합계를 계산하여 return 값으로 돌려준다.
int Ban_maxScoreRecursively(Ban* _this,int left, int right);    // 최고점을 찾아서 return 값으로 돌려준다
int Ban_minScoreRecursively(Ban* _this,int left, int right);    // 최저점을 찾아서 return 값으로 돌려준다.

// 평균 이상인 학생 수 세기
int Ban_numberOfStudentsAboveAverage(Ban* _this);

GradeCounter* Ban_countGrades(Ban* _this);  //학점 별 학생수를 구함

#endif /* Ban_h */
