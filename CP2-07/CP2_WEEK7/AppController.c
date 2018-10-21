//
//  AppController.c
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "AppIO.h"
#include "Common.h"
#include "Ban.h"
#include "Student.h"

struct _AppController{
    AppIO*  _appIO;
    Ban*    _ban;
};

AppController* AppController_new(void) {    // 객체 생성
    AppController* _this = NewObject(AppController);
    _this->_appIO = AppIO_new();
    _this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
    return _this;
}
void AppController_delete(AppController* _this) {   // 객체 소멸
    AppIO_delete(_this->_appIO);
    Ban_delete(_this->_ban);
    free(_this);
}

// 학생들의 정보를 입력 받아 Ban 객체에 저장한다.
// 저장이 정상적으로 이뤄지지 않으면 더 이상 입력 받지 않음
Boolean AppController_inputAndStoreStudents( AppController* _this) {
    int score;
    Boolean storingAStudentWasSuccessful = TRUE;
    char studentID[10];
    Student* student;
    
    while (storingAStudentWasSuccessful && AppIO_in_doesContinueToInputNextStudent(_this->_appIO)) {
        printf("\n");
        AppIO_in_studentID(_this->_appIO,studentID);
        score = AppIO_in_score(_this->_appIO);
        if( AppController_inputIsValid(_this, studentID, score)) {  // 입력이 유효하면
            student = Student_new(studentID, score);    // student 객체 생성
            storingAStudentWasSuccessful = Ban_add(_this->_ban, student);
        }
    }
    return storingAStudentWasSuccessful;
}

// 비공개 함수
Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore) {    // 입력이 유효한지 검사
    Boolean inputIsValid = TRUE;
    if( ! Student_studentIDIsValid(aStudentID)) {   // 주어진 학번이 유효하지 않으면
        AppIO_out_msg_invalidStudentID(_this->_appIO, aStudentID,MAX_STUDENT_ID_LENGTH);
        inputIsValid = FALSE;
    }
    if( ! Student_scoreIsValid(aScore)) {   // 주어진 점수가 유효하지 않으면
        AppIO_out_msg_invalidScore(_this->_appIO, aScore);
        inputIsValid = FALSE;
    }
    return inputIsValid;
}

void AppController_showStatistics(AppController* _this) {
    //이 시점에 성적 처리된 결과를 Ban객체가 가지고 있다.
    printf("\n");
    AppIO_out_averageScore(_this->_appIO, Ban_averageScore(_this->_ban));   // 점수 평균 출력
    AppIO_out_numberOfStudentsAboveAverage(_this->_appIO, Ban_numberOfStudentsAboveAverage(_this->_ban));  // 평균 이상인 학생 수 출력
    AppIO_out_maxScore(_this->_appIO, Ban_maxScore(_this->_ban));   // 최고점 출력
    AppIO_out_minScore(_this->_appIO, Ban_minScore(_this->_ban));   // 최저점 출력
    
    printf("\n");
    //학점 별 학생수는 Ban객체로부터 GradeCounter 객체 형태로 얻음
    GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
    AppIO_out_gradeCountFor(_this->_appIO, 'A', GradeCounter_numberOfA(gradeCounter));  // A 학점 별 학생수
    AppIO_out_gradeCountFor(_this->_appIO, 'B', GradeCounter_numberOfB(gradeCounter));  // B 학점 별 학생수
    AppIO_out_gradeCountFor(_this->_appIO, 'C', GradeCounter_numberOfC(gradeCounter));  // C 학점 별 학생수
    AppIO_out_gradeCountFor(_this->_appIO, 'D', GradeCounter_numberOfD(gradeCounter));  // D 학점 별 학생수
    AppIO_out_gradeCountFor(_this->_appIO, 'F', GradeCounter_numberOfF(gradeCounter));  // F 학점 별 학생수
    GradeCounter_delete(gradeCounter);  // 더 이상 필요 없으므로 소멸
}

void AppController_showStudentsSortedByScore (AppController* _this) {   // 학생 정보 정렬
    printf("\n");
    Student* student;
    AppIO_out_titleForSortedStudentList(_this->_appIO);
    
    for( int i = 0; i < Ban_size(_this->_ban); i++ ) {
        student = Ban_elementAt(_this->_ban, i);    // student는 주어진 순서의 학생 객체
        int score = Student_score(student);
        AppIO_out_studentInfo(_this->_appIO,Student_studentID(student),score,Ban_scoreToGrade(score));    // 학번, 점수, 학점 출력
    }
}

void AppController_run(AppController* _this) {   // 성적 처리 실행
    AppIO_out_msg_startScoreProcessing(_this->_appIO); // 성적 처리 시작 메시지 출력
    
    //성적을 입력받음
    Boolean inputAndStoreWasSuccessful;
    inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);    // 학생들의 정보를 입력 받아 Ban 객체에 저장한다.
    
    if( inputAndStoreWasSuccessful ) {  // 저장이 성공적으로 되었을 때
        if( Ban_isEmpty(_this->_ban)) { // 현재 저장된 학생 정보가 없으면
            printf("\n");
            AppIO_out_msg_noStudentFromInput(_this->_appIO);   // 학생 정보가 입력되지 않았을 때 오류메시지 출력
        }
        else {
            // 평균과 평균 이상인 학생수, 최고점, 최저점 출력
            AppController_showStatistics(_this);
            // 성적순으로 정렬, 입력받은 학생 정보 출력
            Ban_sortStudentsByScore(_this->_ban);
            AppController_showStudentsSortedByScore(_this);
        }
    }
    else {
        AppIO_out_msg_errorInInputStudentInfo(_this->_appIO);  // 입력된 성적이 0보다 작거나 100보다 클 때 오류 메시지 출력
    }
    AppIO_out_msg_endScoreProcessing(_this->_appIO);   // 성적 처리 종료 메시지 출력
}

