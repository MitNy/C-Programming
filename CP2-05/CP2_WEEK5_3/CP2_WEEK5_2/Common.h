//
//  Common.h
//  CP2_WEEK5_2
//
//  Created by stu2017s10 on 2017. 4. 4..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <stdlib.h>

#define END_OF_RUN  -1  // -1이 입력되면 프로그램 종료
#define MAX_ORDER   99  // 차수는 최대 99로 정의
#define NewObject(TYPE) (TYPE*) malloc(sizeof(TYPE))

typedef enum {FALSE,TRUE} Boolean;  // FALSE와 TRUE 값을 갖는 Boolean 선언

#endif /* Common_h */
