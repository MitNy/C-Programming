//
//  GradeCounter.c
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#include "GradeCounter.h"
#include "Common.h"

struct _GradeCounter {
    int _numberOfA;
    int _numberOfB;
    int _numberOfC;
    int _numberOfD;
    int _numberOfF;
};

// 객체를 생성하여 그 소유권을 돌려받는다. 학점을 셀 수 있도록 준비
GradeCounter* GradeCounter_new(void) {
    GradeCounter* _this = NewObject(GradeCounter);
    
    _this->_numberOfA = 0;
    _this->_numberOfB = 0;
    _this->_numberOfC = 0;
    _this->_numberOfD = 0;
    _this->_numberOfF = 0;
    
    return _this;
}

// 사용이 끝난 객체를 소멸시킨다.
void GradeCounter_delete(GradeCounter* _this) {
    free(_this);
}

// 주어진 학점을 받아서 해당 학점의 학생수를 증가시키게 함
void GradeCounter_count(GradeCounter* _this, char aGrade) {
    switch (aGrade) {
        case 'A':
            _this->_numberOfA++;
            break;
        case 'B':
            _this->_numberOfB++;
            break;
        case 'C':
            _this->_numberOfC++;
            break;
        case 'D':
            _this->_numberOfD++;
            break;
        default:
            _this->_numberOfF++;
    }
}

// 학점 별 학생 수 얻기
int GradeCounter_numberOfA (GradeCounter* _this){   // A 학점 학생 수 얻기
    return _this->_numberOfA;
}
int GradeCounter_numberOfB (GradeCounter* _this){   // B 학점 학생 수 얻기
    return _this->_numberOfB;
}
int GradeCounter_numberOfC (GradeCounter* _this){   // C 학점 학생 수 얻기
    return _this->_numberOfC;
}
int GradeCounter_numberOfD (GradeCounter* _this){   // D 학점 학생 수 얻기
    return _this->_numberOfD;
}
int GradeCounter_numberOfF (GradeCounter* _this){   // F 학점 학생 수 얻기
    return _this->_numberOfF;
}
