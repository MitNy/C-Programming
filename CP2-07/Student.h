//
//  Student.h
//  CP2_WEEK7
//
//  Created by stu2017s10 on 2017. 4. 18..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include "Common.h"

typedef struct _Student Student;

Student* Student_new(char* aStudentID, int aScore); //주어진 학번과 성적을 갖는 Student 객체를 생성하여 얻는다
void Student_delete(Student* _this);    // 사용이 끝난 객체를 소멸시킨다.
char* Student_studentID(Student* _this);    //학번 문자열을 얻는다
int Student_score(Student* _this);  // 성적을 얻는다

Boolean Student_studentIDIsValid(char* aStudentID);    //주어진 학번이 유효한지를 알아본다.(학번 길이 최대 9) 유효하면 TRUE, 아니면 FALSE
Boolean Student_scoreIsValid(int aScore);  //주어진 점수가 유효한지를 알아본다( 점수 0과 100 사이 ) 유효하면 TRUE, 아니면 FALSE

#endif /* Student_h */
