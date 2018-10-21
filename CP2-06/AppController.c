//
//  AppController.c
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "AppController.h"
#include "Common.h"


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
    
    while (storingAStudentWasSuccessful && AppIO_in_doesContinueToInputNextStudent(_this->_appIO)) {
        printf("\n");
        score = AppIO_in_score(_this->_appIO);
        if( Ban_scoreIsValid(score)) {
            storingAStudentWasSuccessful = Ban_add(_this->_ban, score);
        }
        else {
            AppIO_out_msg_invalidScore(_this->_appIO,score);
        }
    }
    return storingAStudentWasSuccessful;
}

void AppController_showStatistics(AppController* _this) {
    //이 시점에 성적 처리된 결과를 Ban객체가 가지고 있다.
    printf("\n");
    AppIO_out_averageScore(_this->_appIO, Ban_averageScore(_this->_ban));
    AppIO_out_numberOfStudentsAboveAverage(_this->_appIO, Ban_numberOfStudentsAboveAverage(_this->_ban));
    AppIO_out_maxScore(_this->_appIO, Ban_maxScore(_this->_ban));
    AppIO_out_minScore(_this->_appIO, Ban_minScore(_this->_ban));
    
    printf("\n");
    //학점 별 학생수는 Ban객체로부터 GradeCounter 객체 형태로 얻음
    GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
    AppIO_out_gradeCountFor(_this->_appIO, 'A', GradeCounter_numberOfA(gradeCounter));
    AppIO_out_gradeCountFor(_this->_appIO, 'B', GradeCounter_numberOfB(gradeCounter));
    AppIO_out_gradeCountFor(_this->_appIO, 'C', GradeCounter_numberOfC(gradeCounter));
    AppIO_out_gradeCountFor(_this->_appIO, 'D', GradeCounter_numberOfD(gradeCounter));
    AppIO_out_gradeCountFor(_this->_appIO, 'F', GradeCounter_numberOfF(gradeCounter));
    GradeCounter_delete(gradeCounter);  // 더 이상 필요 없으므로 소멸
}

void AppController_showStudentsSortedByScore (AppController* _this) {
    printf("\n");
    AppIO_out_titleForSortedStudentList(_this->_appIO);
    
    int score;
    char grade;
    for( int order = 0; order < Ban_size(_this->_ban); order++ ) {
        score = Ban_elementAt(_this->_ban, order);
        grade = Ban_scoreToGrade(score);
        AppIO_out_studentInfo(_this->_appIO, score,grade);
    }
}

void AppController_run(AppController* _this) {
    AppIO_out_msg_startScoreProcessing(_this->_appIO);
    
    //성적을 입력받음
    Boolean inputAndStoreWasSuccessful;
    inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
    
    if( inputAndStoreWasSuccessful ) {
        if( Ban_isEmpty(_this->_ban)) {
            AppIO_out_msg_noStudentFromInput(_this->_appIO);
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
        AppIO_out_msg_errorInInputStudentInfo(_this->_appIO);
    }
    AppIO_out_msg_endScoreProcessing(_this->_appIO);
}
