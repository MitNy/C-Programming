//
//  Student.c
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "Student.h"
#include "Common.h"
#include <string.h>
#define MAX_STUDENT_ID_LENGTH 9

struct _Student {
    char    _studentID[MAX_STUDENT_ID_LENGTH+1];
    int _score;
};

Student* Student_new(char* aStudentID, int aScore) {    // 주어진 학번과 성적을 갖는 Student 객체를 생성하여 얻는다
    Student* _this = NewObject(Student);
    strcpy(_this->_studentID, aStudentID);
    _this->_score = aScore;
    return _this;
}

void Student_delete(Student* _this) {    // 사용이 끝난 객체를 소멸시킨다.
    free(_this);
}

char* Student_studentID(Student* _this) {   //학번 문자열을 얻는다
    char* copiedStudentID = NewVector(char,10);
    strcpy(copiedStudentID, _this->_studentID);
    return copiedStudentID;
}

int Student_score(Student* _this) { // 성적을 얻는다
    return _this->_score;
}

Boolean Student_studentIDIsValid(char* aStudentID) {    //주어진 학번이 유효한지를 알아본다.(학번 길이 최대 9) 유효하면 TRUE, 아니면 FALSE
    int length = 0;
    while (*aStudentID != '\0') {
        length++;
        aStudentID++;
    }
    return (length <= MAX_STUDENT_ID_LENGTH);
    //학번(문자열)의 길이가 최대 길이인 9보다 짧거나 같아야 함
}

Boolean Student_scoreIsValid(int aScore) {  //주어진 점수가 유효한지를 알아본다( 점수 0과 100 사이 ) 유효하면 TRUE, 아니면 FALSE
    return (aScore >= 0 && aScore <= 100);
    //점수가 0과 100 사이여야 함
}

