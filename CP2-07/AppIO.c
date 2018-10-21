//
//  AppIO.c
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//


#include "AppIO.h"
#include "Common.h"
#include <unistd.h>
#include <termios.h>

struct _AppIO{
    
};

AppIO* AppIO_new() {    // 객체 생성
    AppIO* _this = NewObject(AppIO);
    return _this;
}

void AppIO_delete(AppIO* _this) {   // 객체 소멸
    free(_this);
}

// 출력을 위한 공개 함수
void AppIO_out_msg_startScoreProcessing (AppIO* _this) {   // 성적 처리 시작 메시지 출력
    printf("<<<성적 처리를 시작합니다>>>\n");
}
void AppIO_out_msg_endScoreProcessing (AppIO* _this) {  // 성적 처리 종료 메시지 출력
    printf(">>>프로그램을 종료합니다<<<\n");
}
void AppIO_out_msg_noStudentFromInput (AppIO* _this) {  // 학생 정보가 입력되지 않았을 때 오류메시지 출력
    printf("[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
}
void AppIO_out_msg_errorInInputStudentInfo (AppIO* _this) { // 입력 종료 메시지
    printf("입력을 종료합니다.\n");
}
void AppIO_out_msg_invalidScore(AppIO* _this,int aScore) {  // 성적이 0보다 작거나 클 때 오류메시지 출력
    printf("[오류] 성적이 0보다 작거나 100보다 커서, 정상적인 성적이 아닙니다.\n");
}
void AppIO_out_msg_invalidStudentID(AppIO* _this,char* aStudentID, int maxLength ) {    // 학번이 maxLength보다 클때 오류 메시지 출력
    printf("[오류] 학번 %s의 길이가 너무 깁니다. 최대 %d입니다.\n",aStudentID,maxLength);
}

void AppIO_in_studentID(AppIO* _this,char* aStudentID) {    //  학번을 입력받음
    printf("> 학번을 입력하시오 : ");
    scanf("%s",aStudentID);
}

void AppIO_out_averageScore (AppIO* _this, float anAverageScore) {    // 평균 점수 출력
    printf("평균 점수는 %.01f 입니다\n",anAverageScore);
}
void AppIO_out_numberOfStudentsAboveAverage (AppIO* _this, int aNumber) {   // 평균 이상인 학생의 수 출력
    printf("평균 이상인 학생은 모두 %d 명입니다.\n",aNumber);
}
void AppIO_out_maxScore (AppIO* _this, int aMaxScore) { // 최고점 출력
    printf("최고점은 %d 점 입니다.\n",aMaxScore);
}
void AppIO_out_minScore (AppIO* _this, int aMinScore) { // 최저점 출력
    printf("최저점은 %d 점 입니다.\n" ,aMinScore);
}
void AppIO_out_gradeCountFor (AppIO* _this, char aGrade, int aCount) {  // 학점 별 학생 수 출력
    printf("%c 학점은 %d명 입니다.\n" ,aGrade,aCount);
}

void AppIO_out_titleForSortedStudentList (AppIO* _this) {   // 성적순 목록 출력 안내 메시지
    printf("학생들의 성적순 목록입니다.\n");
}
void AppIO_out_studentInfo (AppIO* _this,char* aStudentID,int aScore , char aGrade) {   // 학번, 점수, 학점 출력
    printf("학번 : %s   점수 : %d     학점 : %c \n",aStudentID,aScore,aGrade);
}

char getcharDirectlyFromKeyboard (void) {   // keyboard에서 직접 문자 입력 받기
    struct termios oldAttr;
    struct termios newAttr;
    char charFromKeyBoard;
    
    fpurge(stdin);  // stdin buffer를 비운다
    tcgetattr(STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    charFromKeyBoard = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);
    
    return charFromKeyBoard;
}

// 입력을 위한 공개 함수
//성적을 입력 받음
Boolean AppIO_in_doesContinueToInputNextStudent (AppIO* _this) {
    printf(">>>성적을 입력하려면 'y'를, 입력을 종료하려면 다른 아무 키나 누르시오.");
    char answer = getcharDirectlyFromKeyboard();
    return ( answer == 'Y' || answer =='y');
}

// 점수를 입력 받음
int AppIO_in_score (AppIO* _this) {
    int score;
    printf(">>>점수를 입력하시오 : ");
    scanf("%d",&score);
    return score;
}




