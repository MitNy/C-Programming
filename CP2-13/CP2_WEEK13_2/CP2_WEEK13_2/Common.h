
//
//  Common.h
//  CP2_WEEK13_2
//
//  Created by stu2017s10 on 2017. 6. 7..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <math.h>
#include <stdlib.h>
#define DEFAULT_QUEUE_CAPACITY  8

#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))
#define isAlpha(CHAR) ( (('a' <= CHAR) && (CHAR <= 'z')) || (('A' <= CHAR) && (CHAR <= 'Z')))
typedef enum {FALSE,TRUE} Boolean;  // FALSE와 TRUE 값을 갖는 Boolean 선언
typedef int Element;

#endif /* Common_h */
