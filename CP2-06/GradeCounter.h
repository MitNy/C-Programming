//
//  GradeCounter.h
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef GradeCounter_h
#define GradeCounter_h

#include <stdio.h>

typedef struct _GradeCounter GradeCounter;

// 객체를 생성하여 그 소유권을 돌려받는다. 학점을 셀 수 있도록 준비
GradeCounter* GradeCounter_new(void);

// 사용이 끝난 객체를 소멸시킨다.
void GradeCounter_delete(GradeCounter* _this);

// 주어진 학점을 받아서 해당 학점의 학생수를 증가시키게 함
void GradeCounter_count(GradeCounter* _this, char aGrade);

// 학점 별 학생 수 얻기
int GradeCounter_numberOfA (GradeCounter* _this);   // A 학점 학생 수 얻기
int GradeCounter_numberOfB (GradeCounter* _this);   // B 학점 학생 수 얻기
int GradeCounter_numberOfC (GradeCounter* _this);   // C 학점 학생 수 얻기
int GradeCounter_numberOfD (GradeCounter* _this);   // D 학점 학생 수 얻기
int GradeCounter_numberOfF (GradeCounter* _this);   // F 학점 학생 수 얻기


#endif /* GradeCounter_h */
